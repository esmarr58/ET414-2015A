

/*


g++ -Wall -o S7E1 S7E1.cpp `pkg-config --cflags --libs opencv`


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
#include <stdlib.h>

using namespace cv;
using namespace std;
/*      Funcion SiRatonSeMueve. Cada vez que el raton se mueva
	en la ventana "programada" se ejecutara esta funcion.

	


*/

int C = 9;
int D = 8;
int T = 0;


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


int suma(int A, int B){
	return (A+B);

}

int resta(void){
	return (C-D);
}

void multiplicacion(int G, float F){

	T = G*F;
}

void apagar(void){
	system("poweroff");
}




int main(void){
	int opcion = 0;
	cout 	<< "Ingresa opcion"
		<< endl;
	cout	<< "0: suma"
		<< endl;
	cout 	<< "1: resta"
		<< endl;
	cout 	<< "2: multi"
		<< endl;
	cout 	<< "3: system"
		<< endl;
	//cin permite guardar valor

	cin >> opcion;
	cout << "La opcion dada "
	     << opcion
	     << endl;

	switch(opcion){
	
	case 0: 
		cout << suma(2,3)
		     << endl;
		break;
	case 1:
		cout << resta()
		     << endl;
		break;
	case 2:
	   multiplicacion(6,2);
	   cout << T << endl;
		break;
	default:
		apagar();
	}




	
	waitKey(0);

	
	return 1;
}

