#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cLocomotora.h"
#include "cListaViajes.h"
#include "cListaVagones.h"

using namespace std;

class cTren
{//Atributos
private:
	unsigned int ID;
	cLocomotora *locomotora;
	cListaViajes *lista_viajes;
	cListaVagones *lista_vagones;
public:
	cTren(unsigned int ID, cLocomotora *locomotora, cListaVagones *lista_vagones, 
		cListaViajes *lista_viajes); //constructor
	~cTren(){}; //Destructor

	//metodos
	unsigned int get_ID() { return ID; }
	cLocomotora *GetLocomotora() { return locomotora; }
	cListaVagones *GetListaVagones() { return lista_vagones; }
	
	string to_string();
	void imprimir();
	
	float PesoTotalTren();
	void VerificarPeso(); 
};

