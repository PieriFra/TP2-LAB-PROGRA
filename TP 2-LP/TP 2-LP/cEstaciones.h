#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Definiciones.h"
using namespace std;


class cEstaciones
{//atributos
private:
	eEstacion nom_estacion;

public:
	friend class cListaEstaciones; //la hacemos amiga de la clase ListasEstaciones
	cEstaciones(eEstacion nom_estacion); //constructor
	~cEstaciones() {}; //Destructor
	//metodos
	string to_string();
	void imprimir();
	eEstacion GetNomEstacion() { return nom_estacion; }
	void SetNomEstacion(eEstacion nom_estacion) { this->nom_estacion; }
};

