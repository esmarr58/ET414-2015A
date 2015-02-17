

/*


g++ -Wall -o S6E1 S6E1.cpp `pkg-config --cflags --libs opencv`


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





int main(void)
{
	int  dummy = 0;
	//Mat nombre(Y,X, Capas, COlor);
	Mat A(600,400,CV_8UC3,Scalar(255, 255, 255)); 
	Mat B(300,400,CV_8UC3,Scalar(0,0,255));
	Mat imagen(800,800, CV_8UC3, Scalar(255,0,0));
	Mat imagen_small;

	namedWindow("Principal",1);

	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );
	//resize(	Matriz de origen,
	//		Matriz destino,
	//		Tamanio de la matriz destino,
	//		0,0,
	//		TIPO_DE_REDUCCION );
	resize(	imagen ,
		imagen_small ,
		Size ( 400 , 300 ),
		0 ,0 ,
		INTER_LINEAR);

	Rect reg1(Point(0,0), Size(400,300));
	Rect reg2(Point(0,300), Size(400,300));
	

	for(;;)
	{
		B.copyTo(A(reg1));
		imagen_small.copyTo(A(reg2));

		imshow("Principal", A);
	
		if(waitKey(30)>0) break;

 	}

	return 1;
}

