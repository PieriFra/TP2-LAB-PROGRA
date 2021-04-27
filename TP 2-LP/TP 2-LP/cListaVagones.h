#pragma once
#define N 10
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cVagon.h"
#include "cTren.h"

using namespace std;

class cListaVagones
{
private:
	cVagon **lista;
	unsigned int tam;
	unsigned int n_vagones;
public:
	cListaVagones(unsigned int tam=N); //verificar tamaño de la lista
	~cListaVagones() {};

	bool agregar_vagon(cVagon *vagon);
	cVagon* quitar_vagon(unsigned int ID);
	void eliminar_vagon(unsigned int ID);
	unsigned int buscar_pos(unsigned int ID);
};


