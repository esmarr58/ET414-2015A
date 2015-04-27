/*


g++ -Wall -o S15E2 S15E2.cpp `pkg-config --cflags --libs opencv`

*/
// http://my-tech-talk.blogspot.mx/2012/06/digit-recognition-with-opencv.html

#include <opencv2/ml/ml.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

const int train_samples = 1;
const int classes = 10;
const int sizex = 20;
const int sizey = 30;
const int ImageSize = sizex * sizey;
char pathToImages[] = "images";

void PreProcessImage(Mat *inImage,Mat *outImage,int sizex, int sizey);
void LearnFromImages(CvMat* trainData, CvMat* trainClasses);
void RunSelfTest(KNearest& knn2);
void AnalyseImage(KNearest knearest);
int Practica8(KNearest PEPE);
/** @function main */






int main(int argc, char** argv)
{

 CvMat* trainData = cvCreateMat(classes * train_samples,ImageSize, CV_32FC1);
 CvMat* trainClasses = cvCreateMat(classes * train_samples, 1, CV_32FC1);

 //namedWindow("single", CV_WINDOW_AUTOSIZE);
 namedWindow("all",CV_WINDOW_AUTOSIZE);
int i=0;
 LearnFromImages(trainData, trainClasses);

 KNearest DatosACompa(trainData, trainClasses);

 //RunSelfTest(knearest);

 //cout << "losgehts\n";

 //AnalyseImage(TACO);
 //Practica8(TACO);
VideoCapture cam(1);
if(!cam.isOpened()) return -1;
Mat imagen;  //Guardar la imagen de camara
	Mat imagen_small; //Igual que la anterior
	Mat imagen_filtro; //FIltro gaussiano
	Mat imagen_hsv; //IMagen en hsv de la anterior
Mat imagen_color1;
Mat imagen_color2;  
 vector < vector<Point> > contours;
//Rect rec;
 Mat image, gray, blur, thresh;
CvMat* sample2 = cvCreateMat(1, ImageSize, CV_32FC1);

for(;;){
//Paso # 1 capturar imagen
	  cam >>  imagen;

	//Paso # 2 cambiar de tama;o (opcional)
	resize(imagen, imagen_small, Size(800,600));
	
	//Paso # 3 aplicar filtro gaussiano
	GaussianBlur(		imagen_small,
									imagen_filtro,
									Size(0,0),
									3,
									0,
									BORDER_DEFAULT);

	//Paso # 4 convertir a HSV
	cvtColor(	imagen_filtro, 
						imagen_hsv,
						CV_BGR2HSV);

		//Paso # 5 Filtrar el color de HSV
	inRange(	imagen_hsv,
						Scalar(	0, 
										0,
										160),
					Scalar(	255,
									255,
									255),
					imagen_color1);
	//imwrite("analizar.jpg", imagen_color1);
	//Mat analiza = imread("analizar.jpg");
 findContours(imagen_color1, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
for (i = 0; i < contours.size(); i++)
 {
  vector < Point > cnt = contours[i];
  cout << "Area: " << contourArea(cnt) << endl;
  if (contourArea(cnt) > 180)
  {
   Rect rec = boundingRect(cnt);
   if (rec.height > 14)
   {
    Mat roi = image(rec);
   
 Mat stagedImage;
    PreProcessImage(&roi, &stagedImage, sizex, sizey);
    for (int n = 0; n < ImageSize; n++)
    {
     sample2->data.fl[n] = stagedImage.data[n];
    }
    float result = DatosACompa.find_nearest(sample2, 1);
    rectangle(image, Point(rec.x, rec.y),
      Point(rec.x + rec.width, rec.y + rec.height),
      Scalar(0, 0, 255), 2);

    imshow("all", image);
    cout << result << "\n";
	}

	}
}

	//imshow("V1", imagen_color1);
	

										
		//if(waitKey(30)>0) {imwrite("test1.jpg", stagedImage); break; }

}





/*
	signed int i=0;

 CvMat* sample2 = cvCreateMat(1, ImageSize, CV_32FC1);

 Mat image, gray, blur, thresh;

 vector < vector<Point> > contours;
 //image = imread("images/buchstaben.png", 1);

for(;;){
 cam >>  image;
 cvtColor(image, gray, COLOR_BGR2GRAY);

 GaussianBlur(gray, blur, Size(5, 5), 2, 2);
 adaptiveThreshold(blur, thresh, 255, 1, 1, 11, 2);
 Mat copiaThresh;
 resize(thresh, copiaThresh, Size(200,200));
 findContours(copiaThresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
 //cout << "Contornos: " << contours.size() << endl;

 
imshow("sdf", thresh);
	 if(waitKey(30) == 'u') break;
}

imwrite("detectar.png",thresh);


image = imread("detectar.png", 1);

 cvtColor(image, gray, COLOR_BGR2GRAY);
 GaussianBlur(gray, blur, Size(5, 5), 2, 2);
 adaptiveThreshold(blur, thresh, 255, 1, 1, 11, 2);
 
 findContours(thresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
 cout << "Contornos: " << contours.size() << endl;
 
 for (i = 0; i < contours.size(); i++)
 {
  vector < Point > cnt = contours[i];
  cout << "Area: " << contourArea(cnt) << endl;
  if (contourArea(cnt) > 180)
  {
   Rect rec = boundingRect(cnt);
   if (rec.height > 14)
   {
    Mat roi = image(rec);
   
 Mat stagedImage;
    PreProcessImage(&roi, &stagedImage, sizex, sizey);
    for (int n = 0; n < ImageSize; n++)
    {
     sample2->data.fl[n] = stagedImage.data[n];
    }
    float result = DatosACompa.find_nearest(sample2, 1);
    rectangle(image, Point(rec.x, rec.y),
      Point(rec.x + rec.width, rec.y + rec.height),
      Scalar(0, 0, 255), 2);

    imshow("all", image);
    cout << result << "\n";

    imshow("single", stagedImage);
    waitKey(0);
   }

  }}

 
*/
destroyAllWindows();
 return 0;

}

void PreProcessImage(Mat *inImage,Mat *outImage,int sizex, int sizey)
{

 Mat grayImage,blurredImage,thresholdImage,contourImage,regionOfInterest;

 vector<vector<Point> > contours;
//Paso # 4 - COnvertir a escala de grises 4
 cvtColor(*inImage,grayImage , COLOR_BGR2GRAY);
//Paso # 5 -- APlicar Gaussiano
 GaussianBlur(grayImage, blurredImage, Size(5, 5), 2, 2);
//Paso  # 6 -- Remover en forma dinamica el fondo de una imagen gris y convertir a B y N. 


 adaptiveThreshold(blurredImage, thresholdImage, 255, 1, 1, 11, 2);

 //PASO # 7 -- Encontrar contorno y convertir a BN
 thresholdImage.copyTo(contourImage);

 findContours(contourImage, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

 int idx = 0;
 size_t area = 0;
 for (size_t i = 0; i < contours.size(); i++)
 {
  if (area < contours[i].size() )
  {
   idx = i;
   area = contours[i].size();
  }
 }

 Rect rec = boundingRect(contours[idx]);

 regionOfInterest = thresholdImage(rec);

//PASO # 8 -- Cambiar tama;o
 resize(regionOfInterest,*outImage, Size(sizex, sizey));

}

void LearnFromImages(CvMat* trainData, CvMat* trainClasses)
{
 Mat img;
 char file[255];
//#PASO 1,2, declarar una variable y verficar
// que no exceda el valor del numero de las
//clases
 for (int i = 0; i < classes; i++)
 {
	//#PASO 3, LEE A LA IMAGEN i.png
  sprintf(file, "%s/%d.png", pathToImages, i);
  img = imread(file, 1);
  if (!img.data)
  {
    cout << "File " << file << " not found\n";
    exit(1);
  }

 //PASO # 3 - TERMINA AQUI
  Mat outfile;

//De el paso 4 al paso 8, estan las funciones
//dentro de la funcion PreProcessImage
  PreProcessImage(&img, &outfile, sizex, sizey);
  for (int n = 0; n < ImageSize; n++)
  {
// PASO  # 9 CONVERTIR LA INFO A VECTOR DE
// SizeX * SizeyY  = 600 posiciones (dimensiones
   trainData->data.fl[i * ImageSize + n] = outfile.data[n];
  }
//PASO  # 10, Con los del vector anterior, entregar a la clase i  
trainClasses->data.fl[i] = i;
 }

}

void RunSelfTest(KNearest& knn2)
{
 Mat img;
 CvMat* sample2 = cvCreateMat(1, ImageSize, CV_32FC1);
 // SelfTest
 char file[255];
 int z = 0;
 while (z++ < 10)
 {
  int iSecret = rand() % 10;
  //cout << iSecret;
  sprintf(file, "%s/%d.png", pathToImages, iSecret);
  img = imread(file, 1);
  Mat stagedImage;
  PreProcessImage(&img, &stagedImage, sizex, sizey);
  for (int n = 0; n < ImageSize; n++)
  {
   sample2->data.fl[n] = stagedImage.data[n];
  }
  float detectedClass = knn2.find_nearest(sample2, 1);
  if (iSecret != (int) ((detectedClass)))
  {
   cout << "Falsch. Ist " << iSecret << " aber geraten ist "
     << (int) ((detectedClass));
   exit(1);
  }
  cout << "Richtig " << (int) ((detectedClass)) << "\n";
  imshow("single", img);
  waitKey(0);
 }

}

void AnalyseImage(KNearest knearest)
{
	signed int i=0;

 CvMat* sample2 = cvCreateMat(1, ImageSize, CV_32FC1);

 Mat image, gray, blur, thresh;

 vector < vector<Point> > contours;
 image = imread("images/buchstaben.png", 1);

 cvtColor(image, gray, COLOR_BGR2GRAY);
 GaussianBlur(gray, blur, Size(5, 5), 2, 2);
 adaptiveThreshold(blur, thresh, 255, 1, 1, 11, 2);
 
 findContours(thresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
 cout << "Contornos: " << contours.size() << endl;
 
 for (i = 0; i < contours.size(); i++)
 {
  vector < Point > cnt = contours[i];
  cout << "Area: " << contourArea(cnt) << endl;
  if (contourArea(cnt) > 180)
  {
   Rect rec = boundingRect(cnt);
   if (rec.height > 14)
   {
    Mat roi = image(rec);
    Mat stagedImage;
    PreProcessImage(&roi, &stagedImage, sizex, sizey);
    for (int n = 0; n < ImageSize; n++)
    {
     sample2->data.fl[n] = stagedImage.data[n];
    }
    float result = knearest.find_nearest(sample2, 1);
    rectangle(image, Point(rec.x, rec.y),
      Point(rec.x + rec.width, rec.y + rec.height),
      Scalar(0, 0, 255), 2);

    imshow("all", image);
    cout << result << "\n";

    imshow("single", stagedImage);
    waitKey(0);
   }

  }

 }
 
 // destroyAllWindows();
}


int Practica8(KNearest PEPE)
{

 CvMat* sample2 = cvCreateMat(1, ImageSize, CV_32FC1);
 
 Mat image, gray, blur, thresh;
 Mat camara;
 vector < vector<Point> > contours;
/* Linea1 */

/*
 VideoCapture cam(0);
 if(!cam.isOpened()) return -1;

for(;;){
 cam >> camara;
 imshow("dfs", camara);
 if(waitKey(30)>0) break;
}
*/
while(1);
 ///Filtrada por color la matriz camara
 //imwrite("images/buchstaben.png", camara);


 image = imread("images/buchstaben.png", 1);

 cvtColor(image, gray, COLOR_BGR2GRAY);
 GaussianBlur(gray, blur, Size(5, 5), 2, 2);
 adaptiveThreshold(blur, thresh, 255, 1, 1, 11, 2);
 
 findContours(thresh, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

 for (size_t i = 0; i < contours.size(); i++)
 {
  vector < Point > cnt = contours[i];
  if (contourArea(cnt) > 5)
  {
   Rect rec = boundingRect(cnt);
   if (rec.height > 28)
   {
    Mat roi = image(rec);
    Mat stagedImage;
    PreProcessImage(&roi, &stagedImage, sizex, sizey);
    for (int n = 0; n < ImageSize; n++)
    {
     sample2->data.fl[n] = stagedImage.data[n];
    }
    float result = PEPE.find_nearest(sample2, 1);
    rectangle(image, Point(rec.x, rec.y),
      Point(rec.x + rec.width, rec.y + rec.height),
      Scalar(0, 0, 255), 2);

    imshow("all", image);
    cout << result << "\n";

    imshow("single", stagedImage);
    if(waitKey(30)>0) return 1;
   }

  }

 }
 return 1;
}

