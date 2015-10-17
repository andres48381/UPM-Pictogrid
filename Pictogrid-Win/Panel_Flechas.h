// Panel_Flechas.h: interface for the Panel_Flechas class.
//
//////////////////////////////////////////////////////////////////////


#pragma once


#include "Panel_Interaccion.h"

class Panel_Flechas : public Panel_Interaccion 
{

	int localizadorI;
	int localizadorJ;

public:
	Panel_Flechas(int a,int b):Panel_Interaccion(a,b)
	{	
		for(int k=0;k<fila;k++)
		{
			for(int j=0;j<columna;j++)
			{
				casilla[k][j]->SetColor(150,150,150);//BUCLE FOR PARA COLOREAR LAS CASILLAS
			}
		}
		for(int i=1;i<fila-1;i++)
		{
			for(int j=1;j<columna-1;j++)
			{
				casilla[i][j]->SetColor(255,200,10);
			}
		}

	casilla[0][0]->SetColor(255,200,10);
	};

	virtual ~Panel_Flechas();

	void Tecla(unsigned char tecla);
	bool Buscador();
	int GetLocalizadorI(){return localizadorI;};
	int GetLocalizadorJ(){return localizadorJ;};

};


