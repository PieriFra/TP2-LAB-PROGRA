#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "cPasajero.h"

using namespace std;

class cRegistro
{//Atributos
private:
	string DNI;
	tm fecha, hora_bajada, hora_subida;
	unsigned int ID_tren, ID_vagon; //Se deben generar aleatoriamente
public:
	cRegistro(string DNI, tm fecha, tm hora_bajada, tm hora_subida, unsigned int ID_tren,
		unsigned int ID_vagon); //constructor
	~cRegistro() {}; //Destructor
	
	friend class cListaRegistro;

	//metodos
	string GetDNI() { return DNI; }
	void SetDNI(string DNI) { this->DNI = DNI; }
	void imprimir();
	string to_string();
};

