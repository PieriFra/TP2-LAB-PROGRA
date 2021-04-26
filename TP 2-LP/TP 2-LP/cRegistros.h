#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cRegistro.h"

using namespace std;

class cRegistros
{
private:
	cRegistro **lista;
	unsigned int n_registro;
	unsigned int tam;
public:
	unsigned int get_n_pasajeros() { return n_registro; }
	cRegistros(unsigned int  tam = 100);//verificar tamaño de la lista
	~cRegistros() {};
	
};

