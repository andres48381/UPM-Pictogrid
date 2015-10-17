#include "Casilla.h"
#include "glut.h"

Casilla::Casilla(int px,int py)
{
	x=px;
	y=py;
	rojo=verde=azul=250;
}

Casilla::~Casilla()
{
}

void Casilla::Dibuja()
{
float	i=x;
float	j=y;
					glColor3ub(rojo,verde,azul);
				
					glBegin(GL_POLYGON);
					glVertex3f(i,j,0.0f);
					glVertex3f(i,j+2,0.0f);
					glVertex3f(i+2,j+2,0.0f);
					glVertex3f(i+2,j,0.0f);
					glEnd();
}

void Casilla::SetPos(float px,float py)
{
	x=px;
	y=py;
}

void Casilla::SetColor(unsigned char r,unsigned char v,unsigned char a)
{
	rojo=r;
	verde=v;
	azul=a;
}

