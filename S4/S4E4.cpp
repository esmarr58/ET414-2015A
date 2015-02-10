

/*


g++ -Wall -o S4E3 S4E3.cpp `pkg-config --cflags --libs opencv`


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


int main(void)
{
		
	
	//Mat NOmbre(Y,X,TAMANO,color);

Mat A(800,700,CV_8UC3,Scalar(0, 255, 254)); 
Mat B(200,200,CV_8UC3,Scalar(0,255,0));
Mat C(100,100,CV_8UC3,Scalar(0,0,255));
Mat D(200,100,CV_8UC3,Scalar(15,15,15));

Mat E = imread("logo_dark.jpg");

	//Rect nombre(O_x, O_Y, T_x, T_y);
	Rect reg1(300,300,200,200);
	Rect usuario(100,100,100,100);
	Rect taco(500,0,100,200);
	Rect usr2(350,350,80,26);

	for(;;)
	{
		B.copyTo(A(reg1));
		C.copyTo(A(usuario));
		D.copyTo(A(taco));
		E.copyTo(A(usr2));
		imshow("V1",A);
	
	if(waitKey(30)>0) break;

 	}
	imwrite("S4E3.png", A);

	return 1;
}
