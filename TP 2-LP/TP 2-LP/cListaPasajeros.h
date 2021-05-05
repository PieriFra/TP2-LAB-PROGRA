#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"
#define N 30
using namespace std;
typedef struct tm sTM;

class cListaPasajeros
{
	//atributos
private:
	cPasajero **lista;
	unsigned int n_pasajeros;
	unsigned int tam;
public:
	cListaPasajeros(unsigned int  tam = N); //constructor
	~cListaPasajeros(); //destructor

	friend class cVagon; //la hacemos amiga de la clase vagon

	//metodos
	void redimencionalizar();
	unsigned int get_n_pasajeros() { return n_pasajeros; }
	unsigned int buscar_pos(string DNI);
	cPasajero *QuitarPasajeroAleatorio(cPasajero*pasajero);
	cPasajero *QuitarPasajero (cPasajero*pasajero);
	bool AgregarPasajero(cPasajero*pasajero);
	void EliminarPasajero(cPasajero*pasajero);
	cPasajero* GetPasajero(int i);
	void OrdenarLista();
	string to_string();
	void imprimir();
};

