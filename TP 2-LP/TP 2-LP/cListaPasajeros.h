#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"
#define N 100

using namespace std;

class cListaPasajeros
{
private:
	cPasajero **lista;
	unsigned int n_pasajeros;
	unsigned int tam;
public:
	cListaPasajeros(unsigned int  tam = N);
	~cListaPasajeros() {};
	unsigned int get_n_pasajeros() { return n_pasajeros; }
	void QuitarPasajero(cPasajero*pasajero);
	bool AgregarPasajero(cPasajero*pasajero);
	

};

