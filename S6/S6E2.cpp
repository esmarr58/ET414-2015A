

/*


g++ -Wall -o S6E2 S6E2.cpp `pkg-config --cflags --libs opencv`


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
/*      Funcion SiRatonSeMueve. Cada vez que el raton se mueva
	en la ventana "programada" se ejecutara esta funcion.

	


*/

static void SiRatonSeMueve(	int evento, 
				int x, 
				int y, 
				int flags, 
				void* param){
		
		switch(evento)       
		{
			case CV_EVENT_LBUTTONDOWN :
					cout <<"X: "<< x << endl;
					cout <<"Y: "<< y << endl;
					cout << "*********" << endl;
					break;
			default : 
					break;
		}
}



int im1X = 10;
int im1Y = 20;

int main(void)
{
	int  dummy = 0;

	Mat A(400,600,CV_8UC3,Scalar(255, 255, 255)); 
	Mat temporal = imread("imagenes/fatH.jpg", 1);
	Mat B,C,D;

	Rect reg1(Point(20,100),Size(im1X,im1Y));
	Rect reg2(Point(200,10), Size(300,200));
	Rect reg3(Point(200,200), Size(100,100));

	resize(	temporal ,
		B ,
		Size (im1X , im1Y),
		0 ,0 ,
		INTER_LINEAR);

	resize(	temporal ,
		C ,
		Size ( 300 , 200 ),
		0 ,0 ,
		INTER_LINEAR);
	
	resize(	temporal ,
		D ,
		Size ( 100 , 100 ),
		0 ,0 ,
		INTER_LINEAR);



	namedWindow("Principal",1);

	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );


	

	for(;;)
	{
		B.copyTo(A(reg1));
		C.copyTo(A(reg2));
		D.copyTo(A(reg3));

		imshow("Principal", A);
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}

