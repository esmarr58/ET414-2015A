

/*


g++ -Wall -o S14E1 S13E1.cpp `pkg-config --cflags --libs opencv`


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



 
	


	for(;;){
		imshow("s", imagen1);
		if(waitKey(30)>0) break;

 	}
	return 1;
}


