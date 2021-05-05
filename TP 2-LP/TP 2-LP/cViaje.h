#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "Definiciones.h"

using namespace std;

class cViaje
{//Atributos
private:
	tm fecha, hora_partida, hora_llegada;
	eEstacion estacion_origen, estacion_actual, estacion_final;

public:
	cViaje(tm fecha, tm hora_partida, tm hora_llegada, eEstacion estacion_origen,
		eEstacion estacion_actual, eEstacion estacion_final);//Constructor
	~cViaje() { };//Destructor

	//metodos
	void set_HoraLlegada(tm HoraLlegada) { HoraLlegada = hora_llegada; }
	void imprimir();
	string to_string();
};

