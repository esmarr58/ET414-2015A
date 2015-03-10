

/*


g++ -Wall -o S12E1 S12E1.cpp `pkg-config --cflags --libs opencv`


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

	for(;;){
		cout << "ColorMinimo :" << ColorMinimo << endl;
	cout << "ColorMaximo:" << ColorMaximo << endl;
	cout << "SaturacionMinimo :" << SaturacionMinimo << endl;
	cout << "SaturacionMaximo :" << SaturacionMaximo << endl;
	cout << "ContrasteMinimo :" << ContrasteMimino << endl;
	cout << "ContrasteMaximo :" << ContrasteMaximo << endl;
cout << "******************" << endl;


	
		if(waitKey(30)>0) break;

 	}
	return 1;
}


