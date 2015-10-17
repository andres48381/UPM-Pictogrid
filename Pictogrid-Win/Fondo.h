// Fondo.h: interface for the Fondo class.
//
//////////////////////////////////////////////////////////////////////


#pragma once


class Fondo  
{
public:
	Fondo();
	virtual ~Fondo();

	int x;
	int y;
	int z;

	void Dibuja();
	void DefineColor();
};


