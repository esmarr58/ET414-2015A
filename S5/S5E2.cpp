

/*


g++ -Wall -o S5E2 S5E2.cpp `pkg-config --cflags --libs opencv`


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
int SePrecionoBoton = 0;

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
		if( x > 0 && x < 250 && y > 0 && y<250)
			{
				cout << "VERDE" << endl;
				
				if(SePrecionoBoton == 0)
				SePrecionoBoton = 1;
				
			}


					break;
			default : 
					break;
		}
}





int main(void)
{
	int  dummy = 0;
	Mat A(500,250,CV_8UC3,Scalar(255, 255, 255)); 
	Mat B(250,250,CV_8UC3,Scalar(0, 255, 0)); 
	Mat C(250,250,CV_8UC3,Scalar(0, 0, 255)); 

	Point Origen1;
	Origen1.x = 0;
	Origen1.y = 0;

	Rect region1(Origen1, Size(250,250));
	Rect region2(Point(0,250), Size(250,250));


	namedWindow("Principal",1);

	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );

	for(;;)
	{
		if(SePrecionoBoton == 0)
			{
				C.copyTo(A(region1));
			}
		else
		{
			B.copyTo(A(region1));
			//SePrecionoBoton = 0;

		}
		
		C.copyTo(A(region2));
		imshow("Principal", A);
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}


