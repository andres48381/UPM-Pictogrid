// Escenario.h: interface for the Escenario class.
//
//////////////////////////////////////////////////////////////////////
#include "Panel_Juego.h"
#include "Panel_Flechas.h"
#include "Panel_Solucion.h"
#include"Fondo.h"

#pragma once

class Escenario  
{
private:
	Panel_Juego *panel_juego;
	Panel_Solucion *panel_solucion;
	Panel_Flechas *panel_flechas;
	Fondo fondo;

	int pantalla;

public:
	Escenario();
	virtual ~Escenario();

	void Dibuja();
	void InicializaEscenario();
	bool CompruebaPanel();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);

	void SetPantalla(int i){pantalla=i;}
	int GetPantalla(){return pantalla;};


};

