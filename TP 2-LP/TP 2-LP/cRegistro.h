#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

class cRegistro
{
private:
	string DNI;
	tm fecha, hora_bajada, hora_subida;
	unsigned int ID_tren, ID_vagon; //Se deben generar aleatoriamente
public:
	cRegistro(string DNI, tm fehca, tm hora_bajada, tm hora_subida, unsigned int ID_tren,
		unsigned int ID_vagon);
	~cRegistro() {};

	void imprimir();
	string to_string();
};

