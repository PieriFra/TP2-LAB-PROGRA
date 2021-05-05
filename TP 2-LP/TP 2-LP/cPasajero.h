#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include"Definiciones.h"
using namespace std;
typedef struct tm sTM;

class cPasajero
{//Atributos
private:
	string DNI, nombre;
	eEstacion estacion_origen, estacion_destino;
	float peso;
	tm fecha, hora_ascenso, hora_descenso;
	//static int cont_pasajeros;
public:
	cPasajero(string DNI, string nombre, eEstacion estacion_origen, eEstacion estacion_destino,
		float peso, tm fecha, tm hora_ascenso, tm hora_descenso /*static int cont_pasajeros*/); //constructor
	~cPasajero() {};//Destructor

	friend class cVagon;//la hacemos amiga de la clase vagon
	friend class cListaPasajeros; //la hacemos amiga de la clase listapasajeros
	//metodos
	string get_DNI(){return DNI;}
	float get_peso() { return peso; }
	eEstacion get_EstacionDestino() { return estacion_destino; }
	void Set_EstacionOrigen(eEstacion estacion_origen) { this->estacion_origen = estacion_origen; }
	void Set_EstacionDestino(eEstacion estacion_destino) { this->estacion_destino = estacion_destino; }
	void Set_HoraAscenso(tm hora_ascenso) { this->hora_ascenso = hora_ascenso; }
	void Set_HoraDescenso(tm hora_descenso) { this->hora_descenso = hora_descenso; }
	tm get_HoraSubida() { return hora_ascenso; }
	tm get_HoraBajada() { return hora_descenso; }

	void imprimir();
	string to_string();
};

