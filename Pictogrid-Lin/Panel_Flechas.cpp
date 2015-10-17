// Panel_Flechas.cpp: implementation of the Panel_Flechas class.
//
//////////////////////////////////////////////////////////////////////

#include "Panel_Flechas.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



Panel_Flechas::~Panel_Flechas()
{
		


	

}

void Panel_Flechas::Tecla(unsigned char tecla)
{

	Buscador();

	switch(tecla)
	{
	case GLUT_KEY_LEFT:
		MoverFilaIzq(localizadorJ);
		break;
	case GLUT_KEY_RIGHT:
		MoverFilaDcha(localizadorJ);
		break;
	case GLUT_KEY_UP:
		MoverColumnaArriba(localizadorI);
		break;
	case GLUT_KEY_DOWN:
		MoverColumnaAbajo(localizadorI);
		break;
		
// para el cliente de momento
	/*case 'a':
		MoverFilaIzq(localizadorJ);
		break;
	case 'd':
		MoverFilaDcha(localizadorJ);
		break;
	case 'w':
		MoverColumnaArriba(localizadorI);
		break;
	case 's':
		MoverColumnaAbajo(localizadorI);
		break;
	*/
	
	}

}

bool Panel_Flechas::Buscador()
{

	for(int i=0;i<fila;i+=(fila-1))
	{
		for(int j=0;j<columna;j++)
		{
			if((casilla[i][j]->GetColorR())==255)
			{
				localizadorI=i;
				localizadorJ=j;
				if(j==0||j==columna-1)return false;
				return true;
			}
		}

	}


	for(int j=0;j<columna;j+=(columna-1))
		{
		for(int i=1;i<(fila-1);i++)
			{
			if((casilla[i][j]->GetColorR())==255)
				{
				localizadorI=i;
				localizadorJ=j;
				return true;
				}
			}
		}
}

