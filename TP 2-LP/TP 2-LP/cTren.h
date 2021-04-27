#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cLocomotora.h"
#include "cListaVagones.h"
#include "cListaViajes.h"

using namespace std;
class cTren
{
private:
	unsigned int ID;
	cLocomotora *locomotora;
	cListaVagones **lista_vagones;
	cListaViajes **lista_viajes;

public:
	cTren(unsigned int ID, cLocomotora *locomotora, cListaVagones **lista_vagones, cListaViajes **lista_vaijes);
	~cTren(){};


	cLocomotora GetLocomotora() { return *locomotora; }
	cListaVagones **GetListaVagones() { return lista_vagones; }

	string to_string();
	void imprimir();

	void VerificarPeso();
};

