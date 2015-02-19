

/*


g++ -Wall -o S7E2 S7E2.cpp `pkg-config --cflags --libs opencv`


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



int operacion(int A, int B){

	return A+B;
}

int main(void){
	int tem1 = 0;
	int tem2 = 0;
	

	cout << "Ingresa A: " ;
	cin >> tem1;

	cout << endl
	     << "Ingresa B: " ;
	cin >> tem2;

	cout << endl
	     << "Resultado "
	     <<  operacion(tem1,tem2)
	     << endl;




	waitKey(0);

	return 1;
}


