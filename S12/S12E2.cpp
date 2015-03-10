

/*


g++ -Wall -o S12E2 S12E2.cpp `pkg-config --cflags --libs opencv`


*/
// cp /home/rub/ET414-B/Sesion2/ejemplo1.cpp /home/rub/ET414-B/Sesion3/template.cpp
// cp -> permite copiar archivos
// mkdir -> crear carpetas
// cd .. -> bajar una carpeta anterior
// cd -> subir una carpeta
// gedit -> crear archivos con alguna extension determinada
// locate -> buscar archivos
// ls -> mostrar archivos y carpetas
// pwd -> mostrar la ubicacion actual del cursos
// sudo apt-get install programa

/*
	Este es el ejemplo1 de la sesion1
	Muestra el uso  y declaracion de clases en c++
*/

#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>


#include <iostream>


using namespace cv;
using namespace std;

int ColorMinimo = 0;
int ColorMaximo = 255;
int SaturacionMinimo = 0;
int SaturacionMaximo = 255;
int ContrasteMimino = 0;
int ContrasteMaximo = 255;
static int color = 0;


int main(void){

	namedWindow("Calibracion", 1);
	cvCreateTrackbar(		"ColorMinimo",
											"Calibracion",
											&ColorMinimo,
											255);
cvCreateTrackbar(		"ColorMaximo",
											"Calibracion",
											&ColorMaximo,
											255);
cvCreateTrackbar(		"SaturacionMinimo",
											"Calibracion",
											&SaturacionMinimo,
											255);
cvCreateTrackbar(		"SaturacionMaximo",
											"Calibracion",
											&SaturacionMaximo,
											255);
cvCreateTrackbar(		"ContrasteMinimo",
											"Calibracion",
											&ContrasteMimino,
											255);
cvCreateTrackbar(		"ContrasteMaximo",
											"Calibracion",
											&ContrasteMaximo,
											255);
/***********************/
	VideoCapture camara(0);
	if(!camara.isOpened()) return -1;

	Mat imagen;  //Guardar la imagen de camara
	Mat imagen_small; //Igual que la anterior
	Mat imagen_filtro; //FIltro gaussiano
	Mat imagen_hsv; //IMagen en hsv de la anterior
Mat imagen_color1;
Mat imagen_color2;  //Guardaran la imagen binaria del filtro de color de la matriz anterior, estas dos matrices son clones una a otra.
/*Vector de vector*/
vector < vector <Point> > contornos;






/***************************/



	for(;;){
	 //Paso # 1 capturar imagen
	  camara >>  imagen;

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
						Scalar(	ColorMinimo, 
										SaturacionMinimo,
										ContrasteMimino),
					Scalar(	ColorMaximo,
									SaturacionMaximo,
									ContrasteMaximo),
					imagen_color1);
//	Paso # 6 Crear una rutina la deteccion de cada color
//int color = 0
switch(color){
	case 0: 

		inRange(	imagen_hsv,
						Scalar(	40, 
										89,
										86),
					Scalar(	198,
									235,
									182),
					imagen_color1);

		//color++;
		break;
	case 1:
		inRange(	imagen_hsv,
						Scalar(	108, 
										119,
										55),
					Scalar(	133,
									197,
									129),
					imagen_color1);

		//color++;
		break;
	default: cout << "Error13 " << endl;


}


	//Paso # 7 - Duplicar a la imagen binaria
imagen_color1.copyTo(imagen_color2);

	//Paso # 8 - Encontrar contornos
	findContours (	imagen_color2,
									contornos,
									RETR_LIST,
									CHAIN_APPROX_SIMPLE);

	//cout 	<< "COntornos: " 
	//			<< contornos.size()
	//			<< endl
	//			<< "********************" << endl;

//#Paso # 9 encontrar el area de cada contorno
 for( size_t i = 0; i<contornos.size();i++){
  size_t Area = contornos[i].size();
	//cout << "Area " << area << endl;
	if(Area>300){
		if(color == 0) cout << "ROJO" << endl;
		else if(color == 1) cout <<"AZUL" << endl;
		else if(color == 2) cout <<"VERDE"<<endl;
		else cout <<"eRROR" <<endl;
	}
}





	color++;
	if(color>=2) color=0;

	imshow("V1", imagen_color1);

										
		if(waitKey(30)>0) break;

 	}
	return 1;
}


