

/*


g++ -Wall -o S4E2 S4E2.cpp `pkg-config --cflags --libs opencv`


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
Mat A(470,320,CV_8UC3,Scalar(255, 255, 255)); 
		//Matriz azul
	Mat B(150,150,CV_8UC3,Scalar(0, 255, 127)); 
		//Matriz azul
	Mat C(200,150,CV_8UC3,Scalar(0, 0, 255)); 
		//Matriz D
	Mat D(200,150,CV_8UC3,Scalar(24,2,10));

	Mat E(100,300,CV_8UC3,Scalar(255,2,127));

	//Rect nombreRegion(	OrigenX, 
	//			OrigenY,
	//			AnchoX,
	//			LargoY );
	Rect reg1(10,10,300,100);
	Rect reg2(10,110,150,150);
	Rect reg3(160,110,150,150);
	Rect reg4(10,260,150,200);
	Rect reg5(160,260,150,200);



	for(;;)
	{
		//Copia D en A(region1)
		//Un tipo de uso de la ROI
		E.copyTo(A(reg1));
		B.copyTo(A(reg2));
		B.copyTo(A(reg3));
		D.copyTo(A(reg4));
		C.copyTo(A(reg5));
		
		imshow("V1", A);
		
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}
