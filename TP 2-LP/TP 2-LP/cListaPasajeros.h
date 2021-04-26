#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"

using namespace std;

class cListaPasajeros
{
private:
	//hola jose y eze
	cPasajero **lista;
	unsigned int n_pasajeros;
	unsigned int tam;
public:
	unsigned int get_n_pasajeros() { return n_pasajeros; }
	cListaPasajeros(unsigned int  tam = 100);
	~cListaPasajeros() {};
	void QuitarPasajero(cPasajero *pasajero);
	bool AgregarPasajero(cPasajero *pasajero);
};

