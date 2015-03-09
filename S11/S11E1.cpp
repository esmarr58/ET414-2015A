

/*


g++ -Wall -o S11E3 S11E1.cpp `pkg-config --cflags --libs opencv`


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
#include <sstream>
#include <fstream>

#define TEMPERATURA 100

using namespace cv;
using namespace std;
float var1 = 13.2;

int main(void)
{
	/**Inicio de la creacion del archivo */
	ofstream info;
	info.open("variables.txt");

	info << TEMPERATURA << endl;
	info << var1 << endl;

	info.close();
	/*FIn de la creacion del archivo*/


	/*Inicia la lectura del archivo*/
	double A[2] = {0.0, 0.0};
	int indice = 0;
	ifstream lectura("variables.txt");
	string linea; //variable string
	while(getline(lectura, linea)){
		istringstream lectura_linea(linea);
		lectura_linea >> A[indice];
		indice++;
	}
	cout << "Esto fue lo que lei: " 
	<< A[0] << endl
	<< A[1] << endl;


	return 1;
}



