#include "Casilla.h"
#pragma once
using namespace std;
class Panel

{
	protected:
	
		int fila; //numero casillas de ancho
		int columna;  //numero casillas de alto

		float margen; //ancho ranura entre casillas
		int ancho;  //ancho lado de la casilla

		

		float limite_i;//limite del tablero en coordenadas x,y
		float limite_j;
		
		//friend istream& operator>>(istream& s, Panel& p);
		//friend ostream& operator<<(ostream& s, const Panel& p);


	public:
		friend class Escenario;

		Panel(int a=0,int b=0);
		Casilla *casilla[15][15];
		void DibujaPanel();

		int GetColumna(){return columna;};
		int GetFila(){return fila;};

		float Getlimitei(){return limite_i;};
		float Getlimitej(){return limite_j;};

		void SetColor(int ind,int marcador,unsigned char r,unsigned char v,unsigned char a);


};
