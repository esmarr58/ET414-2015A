

/*


g++ -Wall -o S13E1 S13E1.cpp `pkg-config --cflags --libs opencv`


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
	Mat imagen; // Guardar la camara
	Mat hsv; 		// GUarda el espacio HSV
	Mat gauss; // Filtro gaussiao
	Mat color;  //BInaria 

	//PASO # 1 Abrir la camara y verificarla
	VideoCapture camara(0);
	if(!camara.isOpened()) return -1; 

	for(;;){
		//PASO # 2 pasar la camara a una mat
		camara >> imagen;

	 //PASO # 3 procesamiento digital
		//3.1 convertir BGR a HSV
		cvtColor(imagen, hsv, CV_BGR2HSV);

		//3.2 aplicar un desenfoque digital
		GaussianBlur(		hsv,
										gauss,
										Size(11,11),
										10, 10); 

	//3.3 aplicar filtro de color
	inRange		( 		gauss,
									Scalar(40, 89, 86),
									Scalar(198,235,182),
									color);

	// PASO # 4 CALCULAR EL CENTRO DE MASA
	//4.1 Declarar el objeto Moments
	Moments centro = moments( color, false);

	//4.2 los puntos puntos de moento
	Point p1(	centro.m10/centro.m00,
						centro.m01/centro.m00);
		
	//4.3 Imprimir la coordenada del centro
	cout 	<< "El centro esta en: "
				<< p1
				<< endl;

// PASO # 5 (opcional)
//Dibujar un circulo que represente el centro
	circle(	color, p1, 50, Scalar(128,0,0), 2);

	

	//#PASO FINAL mostrar resultado
	imshow("s", color);


		if(waitKey(30)>0) break;

 	}
	return 1;
}


