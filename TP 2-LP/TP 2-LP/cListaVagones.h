#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include "cVagon.h"
#include "cLocomotora.h"
using namespace std;

class cListaVagones
{//atributos
private:
	cVagon **lista;
	unsigned int tam;
	unsigned int n_vagones;
public:
	cListaVagones(unsigned int tam = N); //constructor
	~cListaVagones();//destructor
	//metodos
	void redimencionalizar();
	void agregar_vagon(cVagon *vagon, cLocomotora *locomotora);
	cVagon* quitar_vagon(unsigned int ID);
	void eliminar_vagon(unsigned int ID);
	unsigned int buscar_pos(unsigned int ID);
	cVagon* get_vagon(int i) { return lista[i]; }
	unsigned int get_n_vagones() { return n_vagones; }
	float CalcularPesoTotal();
	string to_string();
	void imprimir();
	
};


