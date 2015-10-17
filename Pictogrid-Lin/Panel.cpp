#include "Panel.h"
#include <stdlib.h>
#include <iostream>
#include "glut.h"

using namespace std;
Panel::Panel(int a,int b)
{
margen=0.10f;//VALORES POR DEFECTO DEL ESCENARIO
ancho=2;

fila=a; //NUMERO DE CASILLAS EN UNA FILA
columna=b; //NUMERO DE CASILLAS EN UNA COLUMNA

int ind=0;
int marcador=0;

limite_i=(fila*ancho+(fila-1)*margen)-ancho+1;
limite_j=(columna*ancho+(columna-1)*margen)-ancho+1;
		
for(float i=0;i<=limite_i;i+=(ancho+margen))//CREACION DE OBJETOS CASILLA-CUADRICULA
	{
	for(float j=0;j<=limite_j;j+=(ancho+margen))
		{
		casilla[ind][marcador]=new Casilla();
		casilla[ind][marcador]->SetPos(i,j);//asignacion de la coordenada correspondiente a cada casilla
		marcador++;
		}
	marcador=0;
	ind++;
	}

}

void Panel::DibujaPanel()
{
	for (int j=0;j<columna;j++)
		{
		for (int i=0;i<fila;i++)
			{
			casilla[i][j]->Dibuja();
			}
		}
}


void Panel::SetColor(int ind,int marcador,unsigned char r,unsigned char v,unsigned char a)
{
	casilla[ind][marcador]->SetColor(r,v,a);
}
/*
istream& operator>>(istream& s, Panel& p)
{
	s>>p.fila>>p.columna;
	return s;
}
ostream& operator<<(ostream& s, const Panel& p)
{
	s<<p.fila<<" "<<p.columna<<std::endl;
	return s;
}*/
