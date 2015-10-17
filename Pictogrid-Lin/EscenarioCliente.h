// Escenario.h: interface for the Escenario class.
//
//////////////////////////////////////////////////////////////////////
#include "Panel_Juego.h"
#include "Panel_Flechas.h"
#include "Panel_Solucion.h"
#include "Fondo.h"
#include "Socket.h"
#pragma once

class Escenario  
{
private:
	Panel_Juego *panel_juego_serv;//JUGADOR 1
	Panel_Flechas *panel_flechas_serv;///////
	
	Panel_Juego *panel_juego_client;//JUGADOR 2
	Panel_Flechas *panel_flechas_client;//////
	
	Panel_Solucion *panel_solucion;
		
	Fondo fondo;

	int pantalla;
	
	int marcador_serv, marcador_client;

public:
	Escenario();
	virtual ~Escenario();

	void Dibuja();
	void InicializaEscenario();
//	bool CompruebaPanel();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);

	void SetPantalla(int i){pantalla=i;}
	int GetPantalla(){return pantalla;};
	void Ontimer();
	
	Socket cliente;
	
	int pass;
	
};

