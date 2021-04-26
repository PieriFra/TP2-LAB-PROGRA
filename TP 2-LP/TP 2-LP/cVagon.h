#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"
#include "cListaPasajeros.h"

using namespace std;

class cVagon
{
private:
	unsigned int ID;
	const unsigned int CantMax_Pasajeros;
	float peso_vagon, peso_pasajeros, largo_vagon;
	cListaPasajeros lista_pasajeros; //ver si esta bien!!
public:

	cVagon(unsigned int ID, unsigned int CantMax_Pasajeros, float peso_vagon, float peso_pasajeros,
		float largo_vagon, cListaPasajeros lista_pasajeros);
	~cVagon() {};

	float SumarPesos(float *peso_pasajeros, cPasajero lista_pasajeros[]);
	void SubirPasajero(cPasajero *pasajero);

	unsigned int GetCantMaxPasajeros() { return CantMax_Pasajeros; }
	unsigned int get_id() { return ID; }
	void imprimir();
	string to_string();
};

