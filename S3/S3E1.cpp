

/*


g++ -Wall -o S3E1 S3E1.cpp `pkg-config --cflags --libs opencv`


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

class Caja{
	public:
	double largo;
	double ancho;
	double alto;
};

int main(void){
  
  Caja 	cajaA, CajaB, CaJaC;
  
  cajaA.largo =   10.0;
  cajaA.ancho =   9.0;
  cajaA.alto  =   6.2;
  
  CajaB.largo = 5.2;
  CajaB.ancho = 5.1;
  CajaB.alto  = 10;
  
  CaJaC.largo = CajaB.largo;
  CaJaC.ancho = CajaB.ancho;
  CaJaC.alto  = (cajaA.ancho * 
                CajaB.ancho);
  
  

	for(;;)
	{
	  cout << "El valor
	           del largo de la 
	           caja A es: "
	       << CaJaC.largo
	       << endl;
	       
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}
