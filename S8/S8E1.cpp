

/*


g++ -Wall -o S8E1 S8E1.cpp `pkg-config --cflags --libs opencv`


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

int V = 0;
/*      Funcion SiRatonSeMueve. Cada vez que el raton se mueva
	en la ventana "programada" se ejecutara esta funcion.

	


*/

void opcion(int  A, int B){
	//cout << "A vale: " << A << endl;
	//cout << "B vale: " << B << endl;
	if(A > 0 && A < 79 && B> 0 && B< 49)
		{
			cout << "Se presiono Menu1" << endl;
		  V = 0;

		}
	else if(A > 80 && A < 160 && B > 0 && B<49)
	{
		cout << "Se presiono Menu2" << endl;
		V =1;

	}
	else if(A > 160 && A < 240 && B > 0  && B<49)
	{
		cout << "Se presiono Menu3 " << endl;
		V = 2;	
}

}

static void SiRatonSeMueve(	int evento, 
				int x, 
				int y, 
				int flags, 
				void* param){
		
		switch(evento)       
		{
			case CV_EVENT_LBUTTONDOWN :
				//	cout <<"X: "<< x << endl;
				//	cout <<"Y: "<< y << endl;
				//	cout << "*********" << endl;

					opcion(x, y);

					break;
			default : 
					break;
		}
}





int main(void)
{
	int  dummy = 0;
	Mat base(250,240,CV_8UC3,Scalar(255, 255, 255));
	Mat menu_act(50,80,CV_8UC3,Scalar(0, 255, 0));  
	Mat menu_des(50,80,CV_8UC3,Scalar(0, 0, 255));  

	Mat ventana1(200,240,CV_8UC3,Scalar(97, 167, 97)); 
	Mat ventana2(200,240,CV_8UC3,Scalar(25, 190, 210));
	Mat ventana3(200,240,CV_8UC3,Scalar(224, 58, 171)); 
	

	Rect reg_ventana(Point(0,50),Size(240,200));
	Rect reg1(Point(0,0), Size(80,50));
	Rect reg2(Point(80,0), Size(80,50));
	Rect reg3(Point(160,0),Size(80,50));

	namedWindow("Principal",1);

	cvSetMouseCallback(	"Principal",
				SiRatonSeMueve, 
				&dummy );


	

	for(;;)
	{
		switch(V){
			case 0:
			ventana1.copyTo(base(reg_ventana));
		  menu_act.copyTo(base(reg1));
			menu_des.copyTo(base(reg2));
			menu_des.copyTo(base(reg3));
			break;

			case 1:
			ventana2.copyTo(base(reg_ventana));
		  menu_act.copyTo(base(reg2));
			menu_des.copyTo(base(reg1));
			menu_des.copyTo(base(reg3));
			break;

			case 2:
			ventana3.copyTo(base(reg_ventana));
		  menu_act.copyTo(base(reg3));
			menu_des.copyTo(base(reg1));
			menu_des.copyTo(base(reg2));
			break;
			

			default:
				cout << "Error";

		}
		imshow("Principal", base);
	
	if(waitKey(30)>0) break;

 	}

	return 1;
}


