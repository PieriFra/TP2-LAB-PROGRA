#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define N 100
#define TAM 0
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cRegistro.h"

using namespace std;

class cListaRegistro
{//Atributos
private:
	cRegistro **lista;
	unsigned int n_registro;
	unsigned int tam;
public:
	unsigned int get_n_pasajeros() { return n_registro; } 
	cListaRegistro(unsigned int  tam = N); //constructor
	~cListaRegistro(); //Destructor

	//metodos
	void redimencionalizar();
	bool CompararHorarios(tm HoraSubida, tm HoraBajada, cRegistro *registro);
	bool AgregarRegistro(cRegistro*registro);
	cRegistro *BuscarPos(string DNI);
	string SeguimientoEpidemiologico(string DNI);
	string to_string();
	void imprimir();
};

