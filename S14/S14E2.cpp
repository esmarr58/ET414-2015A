

/*


g++ -Wall -o S14E1 S14E2.cpp `pkg-config --cflags --libs opencv`


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

int main(void){
	Mat imagen1(		400,
									400, 
									CV_8UC3, 
									Scalar(255,255,255));

	double temporal = 2.4;
	char buffer[20];
	
	sprintf(buffer,"%.2f oC",temporal);
	putText(		imagen1,
							buffer,
							Point2f(30,30),
							FONT_HERSHEY_PLAIN,
							2,
							Scalar(0,0,0),
							3);


	line (imagen1,
					Point(0,0),
					Point(100,100),
					Scalar(255,0,0),
					10,
					0);

	Mat original = imread("TEST4.jpg",1);
	Mat itemporal;
	Mat negra(400,400, CV_8UC3,Scalar(0));
	Mat procesada;
	threshold(original, procesada, 200, 255, CV_8UC1);	

	Rect cuadrante1(Point(0,0), Size(400,400));
	Rect cuadrante2(Point(400, 0),Size(400,400));
	Rect cuadrante3(Point(400,400),Size(400,400));
	Rect cuadrante4(Point(0,400),Size(400,400));
	

/*Inicia procesamiento*/ 
	procesada.copyTo(itemporal);
	
/*Aplicar mascara 1*/
negra.copyTo(itemporal(cuadrante2));
	negra.copyTo(itemporal(cuadrante3));
	negra.copyTo(itemporal(cuadrante4));

/*Encontrar el centro de masa*/
 puntos++;
/*Obetener punto A*/

	namedWindow("A", 1);
	Mat itemporal2;
	resize(itemporal, itemporal2, Size(100,100));
	imshow("A", itemporal2);





/*
 
	rectangle(imagen1,
							Point(0,0),
							Point(50,50),
							Scalar(0,255,0),
							5,	
							8);

	circle(	imagen1,
					Point(50,50),
					50, 
					Scalar(0,0,0), 
					5);

	int B=0,G=0,R=0;
	Vec3b color = imagen1.at<Vec3b>(Point(0,0));
	B = color.val[0];
	G = color.val[1];
	R = color.val[2];

	cout << "B: " << B << endl;
	cout << "G: " << G << endl;
	cout << "R: " << R << endl;

	color.val[0] = 255;
	color.val[1] = 255;
	color.val[2] = 0;

	imagen1.at<Vec3b>(Point(0,0)) = color;

*/



	for(;;){
		imshow("s", imagen1);
		if(waitKey(30)>0) break;

 	}
	return 1;
}


