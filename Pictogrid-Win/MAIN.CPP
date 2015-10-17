#include "glut.h"
#include <math.h>
#include "Escenario.h"
#include "Fondo.h"
#include <iostream.h>
#include "OpenGL.h"

#define MAX 10

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
//void onMouse(int button, int state, int x, int y);
void OnSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial	



Escenario escenario;

/*void onMouse(int button, int state, int x, int y) 
{
	if ( (button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN) ) 
	{
	i = x; j = y;
	cout<<i<<','<<j<<endl;
	}
}*/


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("PICTOGRID");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyboardDown);

//	glutMouseFunc(onMouse);


	escenario.InicializaEscenario();

	

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	gluLookAt(4, 4,65, // posicion del ojo
	4, 4, 0, // hacia que punto mira
	0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)   

	//aqui es donde hay que poner el código de dibujo

	escenario.Dibuja();

	OpenGL::Print("Pictogrid 1",0,0,255,255,255);
	OpenGL::Print("por Andres & Ruth",0,15,155,255,0);

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	escenario.Tecla(key);

}

void OnSpecialKeyboardDown(int key, int x, int y)
{
	escenario.TeclaEspecial(key);
}

void OnTimer(int value)
{
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();

	if(escenario.CompruebaPanel())
		{
		if(escenario.GetPantalla()<=MAX){
		cout<<"Enhorabuena PANTALLA "<<escenario.GetPantalla()<<" COMPLETADA"<<endl;
		escenario.SetPantalla(escenario.GetPantalla()+1);
		escenario.InicializaEscenario();}
		}

}

