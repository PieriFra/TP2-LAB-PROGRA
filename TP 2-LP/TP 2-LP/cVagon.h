#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <exception>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"
#include "cListaPasajeros.h"

using namespace std;

class cVagon
{//atributos
private:
	unsigned int ID;
	const unsigned int CantMax_Pasajeros;
	float peso_vagon, peso_pasajeros, largo_vagon;
	
public:
	cListaPasajeros *lista_pasajeros;
	//constructor
	cVagon(unsigned int ID, unsigned int CantMax_Pasajeros, float peso_vagon, float peso_pasajeros,
		float largo_vagon, cListaPasajeros *lista_pasajeros);
	~cVagon() {};//Destructor

	//metodos
	void SumarPesos(); 
	void AgregarPasajero(cPasajero *pasajero);

	unsigned int GetCantMaxPasajeros() { return CantMax_Pasajeros; }
	unsigned int get_id() { return ID; }
	void set_PesoPasajeros(float peso_pasajeros) { this->peso_pasajeros = peso_pasajeros; }
	float get_PesoVagon() { return peso_vagon; }
	float get_PesoPasajeros() { return peso_pasajeros; }
	float get_LargoVagon() { return largo_vagon; }

	void EcharPasajerosPesados();

	void imprimir();
	string to_string();
};

