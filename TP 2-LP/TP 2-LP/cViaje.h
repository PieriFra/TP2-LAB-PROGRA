#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

class cViaje
{
private:
	tm fecha, hora_partida, hora_llegada;
	string estacion_origen, estacion_actual, estacion_final;

public:
	cViaje(tm fecha, tm hora_partida, tm hora_llegada, string estacion_origen,
		string estacion_actual, string estacion_final);
	~cViaje() { };

	void imprimir();
	string to_string();
};

