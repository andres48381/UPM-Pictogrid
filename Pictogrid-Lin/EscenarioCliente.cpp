// Escenario.cpp: implementation of the Escenario class.
//
//////////////////////////////////////////////////////////////////////

#include "EscenarioCliente.h"
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

	cliente.Connect("10.0.2.15",12000);

}

Escenario::~Escenario()
{
	delete panel_juego_serv;
	delete panel_solucion;
	delete panel_flechas_serv;
	
	delete panel_juego_client;
	delete panel_flechas_client;
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

// ARREGLOS VISUALES DE PANTALLAS
	
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

void Escenario::Tecla(unsigned char key)
{
	
	char cad[100];
sprintf(cad,"%c",key);
cliente.Send(cad,strlen(cad)+1);

}

void Escenario::TeclaEspecial(unsigned char key)
{
char cad[100];
sprintf(cad,"%c",key);
cliente.Send(cad,strlen(cad)+1);


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
            
        delete panel_flechas_client;//INICIALIZACION DEL PANEL FLECHAS CLIENTE
        panel_flechas_client=new Panel_Flechas(7,5);    
                
        delete panel_juego_client;// INICIALIZACION DEL PANEL JUEGO CLIENTE
        panel_juego_client=new Panel_Juego(5,3);
	

        delete panel_solucion;//INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,3);
   	               
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
                    
           
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENTE   
        panel_flechas_client=new Panel_Flechas(9,7);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENTE
        panel_juego_client=new Panel_Juego(7,5);
                    
             
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,5);
              

                        
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
                   
                    
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT   
        panel_flechas_client=new Panel_Flechas(7,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(5,6);

                    
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,6);
                
                       
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

         
           
         delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(10,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(8,6);

                    
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(8,6);
                
                    
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
                    
         delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(9,9);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(7,7);
      
           
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,7);
                
                        
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

        
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(9,11);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(7,9);

                 
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(7,9);


                        
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


		delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT    
        panel_flechas_client=new Panel_Flechas(12,12);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(10,10);

        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(10,10);

                        
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

           
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT   
        panel_flechas_client=new Panel_Flechas(7,7);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO
        panel_juego_client=new Panel_Juego(5,5);
        
               
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(5,5);
 

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

          
        delete panel_flechas_client; // INICIALIZACION DEL PANEL FLECHAS CLIENT 
        panel_flechas_client=new Panel_Flechas(13,8);

        delete panel_juego_client; // INICIALIZACION DEL PANEL JUEGO CLIENT
        panel_juego_client=new Panel_Juego(11,6);

                   
        delete panel_solucion; // INICIALIZACION DEL PANEL SOLUCION
        panel_solucion=new Panel_Solucion(11,6);
                
    
        fondo.DefineColor();
    }
    


}
     void Escenario::Ontimer()
	{
		char cad[500000];
		int len=10000;
		
	
				
		cliente.Receive(cad,len);
		
		string mensaje(cad,len);
		stringstream buffer(mensaje);
		
	
		buffer>>pass;//RECIBE EL NV. PANTALLA DE SERVIDOR
			
			// FLECHAS SERVIDOR
			for(int j=0;j<panel_flechas_serv->GetColumna();j++)
			{
				for (int i=0; i<panel_flechas_serv->GetFila();i++)
				{
				buffer>>panel_flechas_serv->casilla[i][j]->rojo;
				buffer>>panel_flechas_serv->casilla[i][j]->verde;
				buffer>>panel_flechas_serv->casilla[i][j]->azul;			
				}
			}
			// FLECHAS CLIENTE
			for(int j=0;j<panel_flechas_client->GetColumna();j++)
			{
				for (int i=0; i<panel_flechas_client->GetFila();i++)
				{
				buffer>>panel_flechas_client->casilla[i][j]->rojo;
				buffer>>panel_flechas_client->casilla[i][j]->verde;
				buffer>>panel_flechas_client->casilla[i][j]->azul;
				}
			}
			
			
			// JUEGO SERVIDOR
			for(int j=0;j<panel_juego_serv->GetColumna();j++)
			{
				for (int i=0; i<panel_juego_serv->GetFila();i++)
				{
				buffer>>panel_juego_serv->casilla[i][j]->rojo;
				buffer>>panel_juego_serv->casilla[i][j]->verde;
				buffer>>panel_juego_serv->casilla[i][j]->azul;
				}
			}
			
			// JUEGO CLIENTE
			for(int j=0;j<panel_juego_client->GetColumna();j++)
			{
				for (int i=0; i<panel_juego_client->GetFila();i++)
				{
				buffer>>panel_juego_client->casilla[i][j]->rojo;
				buffer>>panel_juego_client->casilla[i][j]->verde;
				buffer>>panel_juego_client->casilla[i][j]->azul;
				}
			}
			
						
			for(int j=0;j<panel_solucion->GetColumna();j++)
			{
				for (int i=0; i<panel_solucion->GetFila();i++)
				{
				buffer>>panel_solucion->casilla[i][j]->rojo;
				buffer>>panel_solucion->casilla[i][j]->verde;
				buffer>>panel_solucion->casilla[i][j]->azul;
				}
			}	
	
}
		
	


		
		
		



