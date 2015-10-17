#include "Casilla.h"
#pragma once
class Panel

{
	protected:
	
		int fila; //numero casillas de ancho
		int columna;  //numero casillas de alto

		float margen; //ancho ranura entre casillas
		int ancho;  //ancho lado de la casilla

		Casilla *casilla[15][15];

		float limite_i;//limite del tablero en coordenadas x,y
		float limite_j;

	public:
		friend class Escenario;

		Panel(int a=0,int b=0);

		void DibujaPanel();

		int GetColumna(){return columna;};
		int GetFila(){return fila;};

		float Getlimitei(){return limite_i;};
		float Getlimitej(){return limite_j;};

		void SetColor(int ind,int marcador,unsigned char r,unsigned char v,unsigned char a);


};