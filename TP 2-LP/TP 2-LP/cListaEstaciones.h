#pragma once
#define N 12
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include "cEstaciones.h"
using namespace std;

class cListaEstaciones
{
private: //atributos
	cEstaciones **lista;
	unsigned int tam;
	unsigned int n_estaciones;
public:
	cListaEstaciones(unsigned int tam = N); //constructor
	~cListaEstaciones();//destructor
	//metodos
	void redimencionalizar();
	string to_string();
	void imprimir();
	bool AgregarEstacion(cEstaciones*estacion);
	int get_n_estaciones() { return n_estaciones; }
	cEstaciones *get_estacion(int i) { return lista[i]; }
};

