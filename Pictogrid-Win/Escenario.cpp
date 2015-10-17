// Escenario.cpp: implementation of the Escenario class.
//
//////////////////////////////////////////////////////////////////////

#include "Escenario.h"
#include "glut.h"
#include"OpenGL.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Escenario::Escenario()
{
	int a=4,b=4;//1º PANTALLA POR DEFECTO AL CREAR UN ESCENARIO
	panel_juego=new Panel_Juego(a,b);
	panel_solucion=new Panel_Solucion(a,b);
	panel_flechas=new Panel_Flechas(a+2,b+2);
	pantalla=1;

}

Escenario::~Escenario()
{
	delete panel_juego;
	delete panel_solucion;
	delete panel_flechas;
}

void Escenario::Dibuja()
{	
	panel_juego->DibujaPanel();
				

	glTranslatef(-2.1,-2.1,0);
	panel_flechas->DibujaPanel();	
	glTranslatef(2.1,2.1,0);
				
	glTranslatef(-24,0,0);
	glScalef(0.8,0.8,0.8);
	panel_solucion->DibujaPanel();
	glScalef(1.25,1.25,1.25);
	glTranslatef(24,0,0);

	fondo.Dibuja();

	OpenGL::Print("SOLUCION",45,350,255,255,255);
	OpenGL::Print("INSTRUCCIONES:",45,450,255,255,255);
	OpenGL::Print("Conseguir el panel solucion utilizando los cursores del teclado",45,470,200,200,200);
	OpenGL::Print("Las casillas rojas solo se pueden mover dentro del perimetro:",45,490,255,0,0);
	OpenGL::Print("Las casillas verdes pueden superar los obstaculos",45,510,0,255,0);
	OpenGL::Print("Las casillas azules son estaticas",45,530,0,0,255);

}
		
bool Escenario::CompruebaPanel()
{
	for(int j=0;j<panel_juego->GetColumna();j++)
	{
		for (int i=0; i<panel_juego->GetFila();i++)
			{
			if((panel_juego->casilla[i][j]->GetColorR()==panel_solucion->casilla[i][j]->GetColorR())
				&&(panel_juego->casilla[i][j]->GetColorV()==panel_solucion->casilla[i][j]->GetColorV())
				&&(panel_juego->casilla[i][j]->GetColorA()==panel_solucion->casilla[i][j]->GetColorA()));
					
			else 
				return false;

			}
	}
	return true;

}

void Escenario::Tecla(unsigned char key)
{

	if(key==' ')
	{
		if(panel_flechas->Buscador()){

		if(panel_flechas->GetLocalizadorI()==0)
			panel_juego->MoverFilaDcha(panel_flechas->GetLocalizadorJ()-1);

		if(panel_flechas->GetLocalizadorI()==((panel_flechas->GetFila())-1))
			panel_juego->MoverFilaIzq(panel_flechas->GetLocalizadorJ()-1);

		if(panel_flechas->GetLocalizadorJ()==0)
			panel_juego->MoverColumnaArriba(panel_flechas->GetLocalizadorI()-1);

		if(panel_flechas->GetLocalizadorJ()==((panel_flechas->GetColumna())-1))
			panel_juego->MoverColumnaAbajo(panel_flechas->GetLocalizadorI()-1);}
		
		
	}


	if(key=='+')//TRUCO
	{
		if(pantalla<10)pantalla++;
		InicializaEscenario();
	}
}

void Escenario::TeclaEspecial(unsigned char key)
{
	panel_flechas->Tecla(key);

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
            
        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<columna;k++)// INICIALIZACION DEL PANEL JUEGO
            {
            panel_juego->SetColor(0,k,255,0,0);
            }

        columna=panel_solucion->GetColumna();
        fila=panel_solucion->GetFila();

        for (k=0;k<fila;k++)// INICIALIZACION DEL PANEL SOLUCION
            {
            panel_solucion->SetColor(k,k,255,0,0);
            }

	

        fondo.DefineColor();//INICIACION FONDO ALEATORIO

    }


/******************************PANTALLA 2*********************************************/
    if(i==2)
    {    

        delete panel_flechas;//INICIALIZACION DEL PANEL FLECHAS
        panel_flechas=new Panel_Flechas(7,5);    
                
        delete panel_juego;// INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(5,3);
            
        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(0,k,0,255,0);
            }
        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(fila-1,k,0,255,0);
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

/*
///////////////////////////////////////////////////////////////////////////////////////
/******************************PANTALLA 2*********************************************/
    if(i==2)
    {    

        delete panel_flechas;//INICIALIZACION DEL PANEL FLECHAS
        panel_flechas=new Panel_Flechas(7,5);    
                
        delete panel_juego;// INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(5,3);
            
        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(0,k,0,255,0);
            }
        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(fila-1,k,0,255,0);
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(9,7);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(7,5);
                    
        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<fila;k++)
            {
            panel_juego->SetColor(k,0,255,0,0);
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(7,8);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(5,6);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<3;k++)
            {
            panel_juego->SetColor(3,k,0,255,0);
            }
        for (k=0;k<3;k++)
            {
            panel_juego->SetColor(2,k,255,0,0);
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(10,8);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(8,6);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<columna;k++)
            {
            for (int j=0;j<5;j=j+2)
                {
                panel_juego->SetColor(j,k,255,0,0);
                }
            }
        for (k=0;k<4;k++)
            {
            panel_juego->SetColor(6,k,255,0,0);
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(9,9);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(7,7);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=1;k<6;k++)
            {    
            panel_juego->SetColor(6,k,255,0,0);    
            }
        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(0,k,255,0,0);
            }

        panel_juego->SetColor(3,4,0,0,255);
        panel_juego->SetColor(3,2,0,0,255);
        panel_juego->SetColor(2,3,0,0,255);
        panel_juego->SetColor(4,3,0,0,255);
        panel_juego->SetColor(3,3,0,0,255);
                    
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(9,11);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(7,9);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<6;k++)
            {
            for (int j=0;j<3;j=j+2)
                {
                panel_juego->SetColor(j,k,255,0,0);    
                }
            }

        panel_juego->SetColor(3,4,0,255,0);
                
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(12,12);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(10,10);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=1;k<fila-2;k++)
            {
            for(int j=1;j<columna-1;j=j+2)
                {
                panel_juego->SetColor(j,k,255,0,0);
                }
            }

        for (k=1;k<5;k++)
            {
            panel_juego->SetColor(2,k,0,255,0);
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(7,7);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(5,5);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();

        for (k=0;k<fila;k=k+2)
            {
            for(int j=0;j<columna;j=j+2)
                {
                panel_juego->SetColor(j,k,0,0,255);
                }
            }
        panel_juego->SetColor(1,0,255,0,0);
        panel_juego->SetColor(3,0,255,0,0);
        panel_juego->SetColor(0,1,255,0,0);
        panel_juego->SetColor(4,1,255,0,0);
        panel_juego->SetColor(0,3,255,0,0);
        panel_juego->SetColor(4,3,255,0,0);
        panel_juego->SetColor(1,4,255,0,0);
        panel_juego->SetColor(3,4,255,0,0);
        
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
        for (p=1;p<4;p=p+2)
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
        delete panel_flechas; // INICIALIZACION DEL PANEL FLECHAS    
        panel_flechas=new Panel_Flechas(13,8);

        delete panel_juego; // INICIALIZACION DEL PANEL JUEGO
        panel_juego=new Panel_Juego(11,6);

        columna=panel_juego->GetColumna();
        fila=panel_juego->GetFila();
        
        for (k=0;k<columna;k++)
            {
            panel_juego->SetColor(3,k,255,0,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego->SetColor(1,k,0,255,0);
            }
        for (k=0;k<columna-1;k++)
            {
            panel_juego->SetColor(5,k,0,255,0);
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
 


		
		
		



