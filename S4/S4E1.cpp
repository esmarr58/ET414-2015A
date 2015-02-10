

/*


g++ -Wall -o S4E1 S4E1.cpp `pkg-config --cflags --libs opencv`


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
		//Matriz verde
	Mat A(450,300,CV_8UC3,Scalar(0, 255, 0)); 
		//Matriz azul
	Mat B(450,300,CV_8UC3,Scalar(255, 0, 0)); 
		//Matriz azul
	Mat C(450,300,CV_8UC3,Scalar(0, 0, 255)); 
		//Matriz D
	Mat D(150,300,CV_8UC3,Scalar(24,2,127));

	//Rect nombreRegion(	OrigenX, 
	//			OrigenY,
	//			AnchoX,
	//			LargoY );
	Rect reg1(0,300,300,150);
	Rect reg2(Point(0,300), Size(300,150));



	for(;;)
	{
		//Copia D en A(region1)
		//Un tipo de uso de la ROI
		D.copyTo(A(reg1));
		
		imshow("V1", A);
		imshow("V2", B);
		imshow("V3", C);
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}
