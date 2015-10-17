// Escenario.cpp: implementation of the Escenario class.
//
//////////////////////////////////////////////////////////////////////

#include "EscenarioServidor.h"
#include "glut.h"
#include "OpenGL.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void* hilo_comandos(void* d);
Escenario::Escenario()
{
	int a=4,b=4;//1º PANTALLA POR DEFECTO AL CREAR UN ESCENARIO
	panel_juego_serv=new Panel_Juego(a,b);
	panel_flechas_serv=new Panel_Flechas(a+2,b+2);
	
	panel_solucion=new Panel_Solucion(a,b);
		
	panel_juego_client=new Panel_Juego(a,b);
	panel_flechas_client=new Panel_Flechas(a+2,b+2);
	
	pantalla=1;
	
	marcador_serv=0;
	marcador_client=0;

	servidor.InitServer("10.0.2.15",12000);
	conexion=servidor.Accept();
	pthread_t thid;
	pthread_create(&thid, 0 ,hilo_comandos, this);

}

Escenario::~Escenario()
{
	delete panel_juego_serv;
	delete panel_solucion;
	delete panel_flechas_serv;
	
	delete panel_juego_client;
	delete panel_flechas_client;
}

void* hilo_comandos(void* d)
{
	Escenario* e=(Escenario*) d;
	e->RecibeComandos();
	
}
void Escenario::RecibeComandos()
{
	while(1)
	{
		usleep(10);
		char cad[100];
		conexion.Receive(cad,100);
		unsigned char key;
		sscanf(cad,"%c",&key);
		

	panel_flechas_client->Buscador();

	switch(key)
		{
		case GLUT_KEY_LEFT:
			panel_flechas_client->MoverFilaIzq(panel_flechas_client->GetLocalizadorJ());
			break;
		case GLUT_KEY_RIGHT:
			panel_flechas_client->MoverFilaDcha(panel_flechas_client->GetLocalizadorJ());
			break;
		case GLUT_KEY_UP:
			panel_flechas_client->MoverColumnaArriba(panel_flechas_client->GetLocalizadorI());
			break;
		case GLUT_KEY_DOWN:
			panel_flechas_client->MoverColumnaAbajo(panel_flechas_client->GetLocalizadorI());
			break;

			
		}

	if(key==' ')
		{
	
		if(panel_flechas_client->Buscador()){

		if(panel_flechas_client->GetLocalizadorI()==0)
			panel_juego_client->MoverFilaDcha(panel_flechas_client->GetLocalizadorJ()-1);

		if(panel_flechas_client->GetLocalizadorI()==((panel_flechas_client->GetFila())-1))
			panel_juego_client->MoverFilaIzq(panel_flechas_client->GetLocalizadorJ()-1);

		if(panel_flechas_client->GetLocalizadorJ()==0)
			panel_juego_client->MoverColumnaArriba(panel_flechas_client->GetLocalizadorI()-1);

		if(panel_flechas_client->GetLocalizadorJ()==((panel_flechas_client->GetColumna())-1))
			panel_juego_client->MoverColumnaAbajo(panel_flechas_client->GetLocalizadorI()-1);}
		
		
		}

	}

}



void Escenario::Dibuja()
{	
	if ( pantalla != 8 &&  pantalla !=10)
	{
	////servidor
	glTranslatef(-24,0,0);
	panel_juego_serv->DibujaPanel();
	glTranslatef(24,0,0);			

	glTranslatef(-26.1,-2.1,0);
	panel_flechas_serv->DibujaPanel();	
	glTranslatef(26.1,2.1,0);
	
	////cliente
	glTranslatef(17.1,0,0);
	panel_juego_client->DibujaPanel();
	glTranslatef(-17.1,0,0);

	glTranslatef(15.0,-2.1,0);
	panel_flechas_client->DibujaPanel();	
	glTranslatef(-15.0,2.1,0);
	
	
	// Solución	
	glTranslatef(0,12,0);
	glScalef(0.8,0.8,0.8);
	panel_solucion->DibujaPanel();
	glScalef(1.25,1.25,1.25);
	glTranslatef(0,-12,0);	
	}

/////// ARREGLOS VISUALES DE PANTALLAS /////////////////
	
	if (pantalla == 8)
	{	
// SERVER
	glTranslatef(-24.3,-0.4,0);
	glScalef(0.8,0.8,0.8);
	panel_juego_serv->DibujaPanel();
		glScalef(1.25,1.25,1.25);
	glTranslatef(24.3,0.4,0);			

	
	glTranslatef(-26,-2.1,0);
	glScalef(0.8,0.8,0.8);
	panel_flechas_serv->DibujaPanel();	
		glScalef(1.25,1.25,1.25);
	glTranslatef(26	,2.1,0);

		// CLIENT
	glTranslatef(14.6,-0.4,0);
	glScalef(0.8,0.8,0.8);
	panel_juego_client->DibujaPanel();
	glScalef(1.25,1.25,1.25);
	glTranslatef(-14.6,0.4,0);

	glTranslatef(13.0,-2.1,0);
	glScalef(0.8,0.8,0.8);
	panel_flechas_client->DibujaPanel();	
	glScalef(1.25,1.25,1.25);
	glTranslatef(-13.0,2.1,0);


	// SOLUCION
	glTranslatef(-2,17,0);
	glScalef(0.5,0.5,0.5);
	panel_solucion->DibujaPanel();
	glScalef(2,2,2);
	glTranslatef(2,-17,0);	
	
	}

	if (pantalla == 10)
	
	{	
// SERVER
	glTranslatef(-24.3,-0.4,0);
	glScalef(0.8,0.8,0.8);
	panel_juego_serv->DibujaPanel();
		glScalef(1.25,1.25,1.25);
	glTranslatef(24.3,0.4,0);			

	
	glTranslatef(-26,-2.1,0);
	glScalef(0.8,0.8,0.8);
	panel_flechas_serv->DibujaPanel();	
		glScalef(1.25,1.25,1.25);
	glTranslatef(26	,2.1,0);

		// CLIENT
	glTranslatef(14.6,-0.4,0);
	glScalef(0.8,0.8,0.8);
	panel_juego_client->DibujaPanel();
	glScalef(1.25,1.25,1.25);
	glTranslatef(-14.6,0.4,0);

	glTranslatef(13.0,-2.1,0);
	glScalef(0.8,0.8,0.8);
	panel_flechas_client->DibujaPanel();	
	glScalef(1.25,1.25,1.25);
	glTranslatef(-13.0,2.1,0);


	// SOLUCION
	glTranslatef(-2,17,0);
	glScalef(0.5,0.5,0.5);
	panel_solucion->DibujaPanel();
	glScalef(2,2,2);
	glTranslatef(2,-17,0);	
	
	}		
	
	fondo.Dibuja();

	OpenGL::Print("SOLUCION",200,20,255,255,255);
	OpenGL::Print("INSTRUCCIONES:",45,450,255,255,255);
	OpenGL::Print("Conseguir el panel solucion utilizando los cursores del teclado",45,470,200,200,200);
	OpenGL::Print("Las casillas rojas solo se pueden mover dentro del perimetro:",45,490,255,0,0);
	OpenGL::Print("Las casillas verdes pueden superar los obstaculos",45,510,0,255,0);
	OpenGL::Print("Las casillas azules son estaticas",45,530,0,0,255);
	
	glutSwapBuffers();
}
		
bool Escenario::CompruebaPanel()//COMPARA EL ESTADO DE LOS PANELES CON LA SOLUCIÓN
{
	int ganador;
	
	for(int j=0;j<panel_juego_serv->GetColumna();j++)
	{
		for (int i=0; i<panel_juego_serv->GetFila();i++)
			{
				if ((panel_juego_serv->casilla[i][j]->GetColorR()==panel_solucion->casilla[i][j]->GetColorR())&(panel_juego_serv->casilla[i][j]->GetColorV()==panel_solucion->casilla[i][j]->GetColorV())&(panel_juego_serv->casilla[i][j]->GetColorA()==panel_solucion->casilla[i][j]->GetColorA()))
					{
						ganador=1;
							
					}	
			
				else if ((panel_juego_client->casilla[i][j]->GetColorR()==panel_solucion->casilla[i][j]->GetColorR())&(panel_juego_client->casilla[i][j]->GetColorV()==panel_solucion->casilla[i][j]->GetColorV())&(panel_juego_client->casilla[i][j]->GetColorA()==panel_solucion->casilla[i][j]->GetColorA()))
					{
						ganador=2;

					}
			
				else 
					{
						ganador=0;
						return false;
					}

			}
	}

		if (ganador==1)
			marcador_serv++;
		if (ganador ==2)
			marcador_client++;
			
			
		cout<<"PUNTOS SERVIDOR: "<<marcador_serv<<endl;
		cout<<"PUNTOS CLIENTE: "<<marcador_client<<endl;
	
	return true;
}

void Escenario::Tecla(unsigned char key)
{

	if(key==' ')
	{
		if(panel_flechas_serv->Buscador()){

		if(panel_flechas_serv->GetLocalizadorI()==0)
			panel_juego_serv->MoverFilaDcha(panel_flechas_serv->GetLocalizadorJ()-1);

		if(panel_flechas_serv->GetLocalizadorI()==((panel_flechas_serv->GetFila())-1))
			panel_juego_serv->MoverFilaIzq(panel_flechas_serv->GetLocalizadorJ()-1);

		if(panel_flechas_serv->GetLocalizadorJ()==0)
			panel_juego_serv->MoverColumnaArriba(panel_flechas_serv->GetLocalizadorI()-1);

		if(panel_flechas_serv->GetLocalizadorJ()==((panel_flechas_serv->GetColumna())-1))
			panel_juego_serv->MoverColumnaAbajo(panel_flechas_serv->GetLocalizadorI()-1);}
		
		
	}
	
	if(key=='+')//TRUCO
	{
		if(pantalla<10)pantalla++;
		InicializaEscenario();
	}
}

void Escenario::TeclaEspecial(unsigned char key)
{
	panel_flechas_serv->Tecla(key);

}

void Escenario::InicializaEscenario()
{
	int columna;
	int fila;
	int i=pantalla;
	int k=0;

///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 1*********************************************/
    if(i==1)
    {    
            
        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<columna;k++)// INICIALIZACION DEL PANEL JUEGO SERV
            {
            panel_juego_serv->SetColor(0,k,255,0,0);
            }
            
        for (k=0;k<columna;k++)// INICIALIZACION DEL PANEL JUEGO CLIENT
            {
            panel_juego_client->SetColor(0,k,255,0,0);
            }

        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        for (k=0;k<fila;k++)// INICIALIZACION DEL PANEL SOLUCION
            {
            panel_solucion->SetColor(k,k,255,0,0);
            }





        fondo.DefineColor();//INICIACION FONDO ALEATORIO

    }

//////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 2*********************************************/
    if(i==2)
    {    

        delete panel_flechas_serv;//INICIALIZACION DEL PANEL FLECHAS SERVIDOR
        panel_flechas_serv=new Panel_Flechas(7,5);    
                
        delete panel_juego_serv;// INICIALIZACION DEL PANEL JUEGO SERVIDOR
        panel_juego_serv=new Panel_Juego(5,3);
            
        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<columna;k++)
            {
            panel_juego_serv->SetColor(0,k,0,255,0);
            }
        for (k=0;k<columna;k++)
            {
            panel_juego_serv->SetColor(fila-1,k,0,255,0);
            }

        delete panel_flechas_client;//INICIALIZACION DEL PANEL FLECHAS CLIENTE
        panel_flechas_client=new Panel_Flechas(7,5);    
                
        delete panel_juego_client;// INICIALIZACION DEL PANEL JUEGO CLIENTE
        panel_juego_client=new Panel_Juego(5,3);
            
        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<columna;k++)
            {
            panel_juego_client->SetColor(0,k,0,255,0);
            }
        for (k=0;k<columna;k++)
            {
            panel_juego_client->SetColor(fila-1,k,0,255,0);
            }



        delete panel_solucion;//INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,3);
                    
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(0,1,0,255,0);
        panel_solucion->SetColor(1,0,0,255,0);
        panel_solucion->SetColor(1,2,0,255,0);
        panel_solucion->SetColor(2,1,0,255,0);
        panel_solucion->SetColor(3,0,0,255,0);
        panel_solucion->SetColor(3,2,0,255,0);



                
        fondo.DefineColor();//INICIACION FONDO ALEATORIO
    }


///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 3*********************************************/
    if(i==3)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERVIDOR   
        panel_flechas_serv=new Panel_Flechas(9,7);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERVIDOR
        panel_juego_serv=new Panel_Juego(7,5);
                    
        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<fila;k++)
            {
            panel_juego_serv->SetColor(k,0,255,0,0);
            }
            
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENTE   
        panel_flechas_client=new Panel_Flechas(9,7);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENTE
        panel_juego_client=new Panel_Juego(7,5);
                    
        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<fila;k++)
            {
            panel_juego_client->SetColor(k,0,255,0,0);
            }
            
            
                    
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,5);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(0,1,255,0,0);
        panel_solucion->SetColor(1,2,255,0,0);
        panel_solucion->SetColor(2,3,255,0,0);
        panel_solucion->SetColor(3,4,255,0,0);
        panel_solucion->SetColor(4,3,255,0,0);
        panel_solucion->SetColor(5,2,255,0,0);
        panel_solucion->SetColor(6,1,255,0,0);
                        
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 4*********************************************/
    if(i==4)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SEVER  
        panel_flechas_serv=new Panel_Flechas(7,8);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERVER
        panel_juego_serv=new Panel_Juego(5,6);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<3;k++)
            {
            panel_juego_serv->SetColor(3,k,0,255,0);
            }
        for (k=0;k<3;k++)
            {
            panel_juego_serv->SetColor(2,k,255,0,0);
            }
                    
                    
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT   
        panel_flechas_client=new Panel_Flechas(7,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(5,6);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<3;k++)
            {
            panel_juego_client->SetColor(3,k,0,255,0);
            }
        for (k=0;k<3;k++)
            {
            panel_juego_client->SetColor(2,k,255,0,0);
            }
                    
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,6);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(2,1,255,0,0);
        panel_solucion->SetColor(2,2,255,0,0);
        panel_solucion->SetColor(2,3,255,0,0);
        panel_solucion->SetColor(2,4,0,255,0);
        panel_solucion->SetColor(1,4,0,255,0);
        panel_solucion->SetColor(3,4,0,255,0);
                        
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 5*********************************************/
        // PANTALLA CON MENSAJE SUBLIMINAL

    if(i==5)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERV   
        panel_flechas_serv=new Panel_Flechas(10,8);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERV
        panel_juego_serv=new Panel_Juego(8,6);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<columna;k++)
            {
            for (int j=0;j<5;j=j+2)
                {
                panel_juego_serv->SetColor(j,k,255,0,0);
                }
            }
        for (k=0;k<4;k++)
            {
            panel_juego_serv->SetColor(6,k,255,0,0);
            }
           
           
         delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(10,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(8,6);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<columna;k++)
            {
            for (int j=0;j<5;j=j+2)
                {
                panel_juego_client->SetColor(j,k,255,0,0);
                }
            }
        for (k=0;k<4;k++)
            {
            panel_juego_client->SetColor(6,k,255,0,0);
            }
                    
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(8,6);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        for (k=0;k<columna;k++)
            {
            for (int j=2;j<fila;j=j+2)
                {
                panel_solucion->SetColor(j,k,255,0,0);
                }
            }
        panel_solucion->SetColor(0,3,255,0,0);
        panel_solucion->SetColor(1,4,255,0,0);
        panel_solucion->SetColor(5,0,255,0,0);
        panel_solucion->SetColor(5,5,255,0,0);
                    
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 6*********************************************/
    if(i==6)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERV   
        panel_flechas_serv=new Panel_Flechas(9,9);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERV
        panel_juego_serv=new Panel_Juego(7,7);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=1;k<6;k++)
            {    
            panel_juego_serv->SetColor(6,k,255,0,0);    
            }
        for (k=0;k<columna;k++)
            {
            panel_juego_serv->SetColor(0,k,255,0,0);
            }

        panel_juego_serv->SetColor(3,4,0,0,255);
        panel_juego_serv->SetColor(3,2,0,0,255);
        panel_juego_serv->SetColor(2,3,0,0,255);
        panel_juego_serv->SetColor(4,3,0,0,255);
        panel_juego_serv->SetColor(3,3,0,0,255);
                    
         delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(9,9);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(7,7);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=1;k<6;k++)
            {    
            panel_juego_client->SetColor(6,k,255,0,0);    
            }
        for (k=0;k<columna;k++)
            {
            panel_juego_client->SetColor(0,k,255,0,0);
            }

        panel_juego_client->SetColor(3,4,0,0,255);
        panel_juego_client->SetColor(3,2,0,0,255);
        panel_juego_client->SetColor(2,3,0,0,255);
        panel_juego_client->SetColor(4,3,0,0,255);
        panel_juego_client->SetColor(3,3,0,0,255);           
         
         
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,7);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(0,3,255,0,0);
        panel_solucion->SetColor(1,4,255,0,0);
        panel_solucion->SetColor(2,5,255,0,0);
        panel_solucion->SetColor(3,6,255,0,0);
        panel_solucion->SetColor(1,2,255,0,0);
        panel_solucion->SetColor(2,1,255,0,0);
        panel_solucion->SetColor(3,0,255,0,0);
        panel_solucion->SetColor(4,1,255,0,0);
        panel_solucion->SetColor(5,2,255,0,0);
        panel_solucion->SetColor(6,3,255,0,0);
        panel_solucion->SetColor(5,4,255,0,0);
        panel_solucion->SetColor(4,5,255,0,0);
                        
        panel_solucion->SetColor(3,4,0,0,255);
        panel_solucion->SetColor(3,2,0,0,255);
        panel_solucion->SetColor(2,3,0,0,255);
        panel_solucion->SetColor(4,3,0,0,255);
        panel_solucion->SetColor(3,3,0,0,255);
                        
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 7*********************************************/
    if(i==7)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERV 
        panel_flechas_serv=new Panel_Flechas(9,11);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERV
        panel_juego_serv=new Panel_Juego(7,9);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<6;k++)
            {
            for (int j=0;j<3;j=j+2)
                {
                panel_juego_serv->SetColor(j,k,255,0,0);    
                }
            }

        panel_juego_serv->SetColor(3,4,0,255,0);
        
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(9,11);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(7,9);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<6;k++)
            {
            for (int j=0;j<3;j=j+2)
                {
                panel_juego_client->SetColor(j,k,255,0,0);    
                }
            }

        panel_juego_client->SetColor(3,4,0,255,0);
        
        
                 
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,9);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(1,6,255,0,0);
        panel_solucion->SetColor(2,5,255,0,0);
        panel_solucion->SetColor(2,8,255,0,0);
        panel_solucion->SetColor(3,2,255,0,0);
        panel_solucion->SetColor(3,3,255,0,0);
        panel_solucion->SetColor(3,8,255,0,0);
        panel_solucion->SetColor(4,4,255,0,0);
        panel_solucion->SetColor(4,8,255,0,0);
        panel_solucion->SetColor(5,5,255,0,0);
        panel_solucion->SetColor(5,6,255,0,0);
        panel_solucion->SetColor(5,7,255,0,0);
        panel_solucion->SetColor(1,7,255,0,0);

                        
        panel_solucion->SetColor(3,0,0,255,0);
                        
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 8*********************************************/
    if(i==8)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERV   
        panel_flechas_serv=new Panel_Flechas(12,12);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERV
        panel_juego_serv=new Panel_Juego(10,10);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=1;k<fila-2;k++)
            {
            for(int j=1;j<columna-1;j=j+2)
                {
                panel_juego_serv->SetColor(j,k,255,0,0);
                }
            }

        for (k=1;k<5;k++)
            {
            panel_juego_serv->SetColor(2,k,0,255,0);
            }

delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(12,12);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(10,10);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=1;k<fila-2;k++)
            {
            for(int j=1;j<columna-1;j=j+2)
                {
                panel_juego_client->SetColor(j,k,255,0,0);
                }
            }

        for (k=1;k<5;k++)
            {
            panel_juego_client->SetColor(2,k,0,255,0);
            }



        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(10,10);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        for (k=1;k<columna-1;k++)
            {
            for(int j=1;j<fila;j=j+7)
                {
                panel_solucion->SetColor(j,k,255,0,0);    
                }
            }
        for (k=1;k<fila-1;k++)
            {
            for(int j=1;j<columna;j=j+7)    
                {
                panel_solucion->SetColor(k,j,255,0,0);    
                }
            }

        panel_solucion->SetColor(3,6,0,255,0);
        panel_solucion->SetColor(4,3,0,255,0);
        panel_solucion->SetColor(5,3,0,255,0);
        panel_solucion->SetColor(6,6,0,255,0);
                        
        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 9*********************************************/
    if(i==9)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERVER 
        panel_flechas_serv=new Panel_Flechas(7,7);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERVER
        panel_juego_serv=new Panel_Juego(5,5);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();

        for (k=0;k<fila;k=k+2)
            {
            for(int j=0;j<columna;j=j+2)
                {
                panel_juego_serv->SetColor(j,k,0,0,255);
                }
            }
        panel_juego_serv->SetColor(1,0,255,0,0);
        panel_juego_serv->SetColor(3,0,255,0,0);
        panel_juego_serv->SetColor(0,1,255,0,0);
        panel_juego_serv->SetColor(4,1,255,0,0);
        panel_juego_serv->SetColor(0,3,255,0,0);
        panel_juego_serv->SetColor(4,3,255,0,0);
        panel_juego_serv->SetColor(1,4,255,0,0);
        panel_juego_serv->SetColor(3,4,255,0,0);
        
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT   
        panel_flechas_client=new Panel_Flechas(7,7);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO
        panel_juego_client=new Panel_Juego(5,5);
        
         columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();

        for (k=0;k<fila;k=k+2)
            {
            for(int j=0;j<columna;j=j+2)
                {
                panel_juego_client->SetColor(j,k,0,0,255);
                }
            }
        panel_juego_client->SetColor(1,0,255,0,0);
        panel_juego_client->SetColor(3,0,255,0,0);
        panel_juego_client->SetColor(0,1,255,0,0);
        panel_juego_client->SetColor(4,1,255,0,0);
        panel_juego_client->SetColor(0,3,255,0,0);
        panel_juego_client->SetColor(4,3,255,0,0);
        panel_juego_client->SetColor(1,4,255,0,0);
        panel_juego_client->SetColor(3,4,255,0,0);
        
        
               
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,5);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        for (int p=0;p<columna;p=p+2)
            {
            for(int m=0;m<fila;m=m+2)
                {
                panel_solucion->SetColor(m,p,0,0,255);
                }
            }
        for (int p=1;p<4;p=p+2)
            {
            for(int m=1;m<4;m++)
                {
                panel_solucion->SetColor(m,p,255,0,0);
                }
            }
        panel_solucion->SetColor(1,2,255,0,0);
        panel_solucion->SetColor(3,2,255,0,0);

        fondo.DefineColor();
    }
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 10*********************************************/
    if(i==10)
    {    
        delete panel_flechas_serv; // INICIALIZACION DEL PANEL FLECHAS SERVER
        panel_flechas_serv=new Panel_Flechas(13,8);

        delete panel_juego_serv; // INICIALIZACION DEL PANEL JUEGO SERVER
        panel_juego_serv=new Panel_Juego(11,6);

        columna=panel_juego_serv->GetColumna();
        fila=panel_juego_serv->GetFila();
        
        for (k=0;k<columna;k++)
            {
            panel_juego_serv->SetColor(3,k,255,0,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego_serv->SetColor(1,k,0,255,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego_serv->SetColor(5,k,0,255,0);
            }
        
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT 
        panel_flechas_client=new Panel_Flechas(13,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(11,6);

        columna=panel_juego_client->GetColumna();
        fila=panel_juego_client->GetFila();
        
        for (k=0;k<columna;k++)
            {
            panel_juego_client->SetColor(3,k,255,0,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego_client->SetColor(1,k,0,255,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego_client->SetColor(5,k,0,255,0);
            }
        
                   
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(11,6);
                
        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        panel_solucion->SetColor(0,2,255,0,0);
        panel_solucion->SetColor(0,3,255,0,0);
        panel_solucion->SetColor(1,4,255,0,0);
        panel_solucion->SetColor(2,4,255,0,0);
        panel_solucion->SetColor(1,1,255,0,0);
        panel_solucion->SetColor(2,1,255,0,0);

        panel_solucion->SetColor(4,3,0,255,0);
        panel_solucion->SetColor(5,2,0,255,0);
        panel_solucion->SetColor(5,3,0,255,0);
        panel_solucion->SetColor(5,4,0,255,0);
        panel_solucion->SetColor(6,3,0,255,0);
        panel_solucion->SetColor(8,3,0,255,0);
        panel_solucion->SetColor(9,2,0,255,0);
        panel_solucion->SetColor(9,3,0,255,0);
        panel_solucion->SetColor(9,4,0,255,0);
        panel_solucion->SetColor(10,3,0,255,0);


        fondo.DefineColor();
    }




} 
 

void Escenario::Ontimer()
{
	stringstream buffer;

	buffer<<pantalla<<endl;

// FLECHAS SERVIDOR
	for(int j=0;j<panel_flechas_serv->GetColumna();j++)
	{
		for (int i=0; i<panel_flechas_serv->GetFila();i++)
			{
			buffer<<panel_flechas_serv->casilla[i][j]->rojo<<endl;
			buffer<<panel_flechas_serv->casilla[i][j]->verde<<endl;
			buffer<<panel_flechas_serv->casilla[i][j]->azul<<endl;	
			}
	}
// FLECHAS CLIENTE
	for(int j=0;j<panel_flechas_client->GetColumna();j++)
	{
		for (int i=0; i<panel_flechas_client->GetFila();i++)
			{
			buffer<<panel_flechas_client->casilla[i][j]->rojo<<endl;
			buffer<<panel_flechas_client->casilla[i][j]->verde<<endl;
			buffer<<panel_flechas_client->casilla[i][j]->azul<<endl;
			}
	}
	
	
	// JUEGO SERVIDOR
	for(int j=0;j<panel_juego_serv->GetColumna();j++)
	{
		for (int i=0; i<panel_juego_serv->GetFila();i++)
			{
			buffer<<panel_juego_serv->casilla[i][j]->rojo<<endl;
			buffer<<panel_juego_serv->casilla[i][j]->verde<<endl;
			buffer<<panel_juego_serv->casilla[i][j]->azul<<endl;
			}
	}

// JUEGO CLIENTE
	for(int j=0;j<panel_juego_client->GetColumna();j++)
	{
		for (int i=0; i<panel_juego_client->GetFila();i++)
			{
			buffer<<panel_juego_client->casilla[i][j]->rojo<<endl;
			buffer<<panel_juego_client->casilla[i][j]->verde<<endl;
			buffer<<panel_juego_client->casilla[i][j]->azul<<endl;
			}
	}


	for(int j=0;j<panel_solucion->GetColumna();j++)
	{
		for (int i=0; i<panel_solucion->GetFila();i++)
			{
			buffer<<panel_solucion->casilla[i][j]->rojo<<endl;
			buffer<<panel_solucion->casilla[i][j]->verde<<endl;
			buffer<<panel_solucion->casilla[i][j]->azul<<endl;
			}
	}

		
	string mensaje=buffer.str();
	
	conexion.Send((char*)mensaje.c_str(),mensaje.length());
	
	
}

		
		
		



