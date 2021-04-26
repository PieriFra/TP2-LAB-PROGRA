#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cLocomotora.h"
#include "cVagon.h"
#include "cViaje.h"

using namespace std;
class cTren
{
private:
	unsigned int ID;
	cLocomotora locomotora;
	cVagon lista_vagones;
	cViaje lista_viajes;

public:
	cTren(unsigned int ID, cLocomotora locomotora, cVagon lista_vagones, cViaje lista_vaijes);
	~cTren(){};

	string to_string();
	void imprimir();

	void VerificarPeso();
};

