#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define N  5
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cViaje.h"

using namespace std;

class cListaViajes
{
	//atributos
private:
	cViaje **lista;
	unsigned int tam;
	unsigned int n_viajes;
public:
	cListaViajes(unsigned int tam = N); //constructor
	~cListaViajes(); //destructor

	//metodos
	bool AgregarViaje(cViaje*viaje);
	void redimencionalizar();
	string to_string();
	void imprimir();

};

