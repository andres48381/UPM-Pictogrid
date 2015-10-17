// Panel_Interaccion.h: interface for the Panel_Interaccion class.
//
//////////////////////////////////////////////////////////////////////

#pragma once


#include "Panel.h"

class Panel_Interaccion : public Panel  
{
public:
	Panel_Interaccion(int a,int b):Panel(a,b){};
	virtual ~Panel_Interaccion();

		void MoverFilaIzq(int k);
		void MoverFilaDcha(int k);
		void MoverColumnaArriba(int k);
		void MoverColumnaAbajo(int k);

};


