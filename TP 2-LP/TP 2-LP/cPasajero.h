#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;
class cPasajero
{
private:
	string DNI, nombre, estacion_origen, estacion_destino;
	float peso;
	tm fecha, hora_ascenso, hora_descenso;
	static int cont_pasajeros;
public:
	cPasajero(string DNI, string nombre, string estacion_origen, string estacion_destino,
		float peso, tm fecha, tm hora_ascenso, tm hora_descenso, static int cont_pasajeros);
	~cPasajero() {};

	friend class cVagon;

	void imprimir();
	string to_string();
};

