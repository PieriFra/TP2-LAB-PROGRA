#pragma once
#define N 5
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cViaje.h"

using namespace std;

class cListaViajes
{
private:
	cViaje **lista;
	unsigned int tam;
	unsigned int n_vagones;
public:
	cListaViajes(unsigned int tam = N); //verificar tamaño de la lista
	~cListaViajes() {};

};

