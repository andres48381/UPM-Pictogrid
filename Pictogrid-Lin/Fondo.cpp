// Fondo.cpp: implementation of the Fondo class.
//
//////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include "glut.h"
#include "Fondo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Fondo::Fondo()
{
	x=y=z=0;
}

Fondo::~Fondo()
{

}

void Fondo::Dibuja()
{
				glColor3ub(x,y,z); //FONDO ESCENARIO			
				glBegin(GL_POLYGON);
					glVertex3f(40,30,0.0f);
					glVertex3f(40,-30,0.0f);
					glVertex3f(-40,-30,0.0f);
					glVertex3f(-40,30,0.0f);
					glEnd();
}

void Fondo::DefineColor()
{
		x=rand()/255;
		y=rand()/255;
		z=rand()/255;
}