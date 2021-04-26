#include "cPasajero.h"

cPasajero::cPasajero(string DNI, string nombre, string estacion_origen, string estacion_destino, 
	float peso, tm fecha, tm hora_ascenso, tm hora_descenso, static int cont_pasajeros)
{
	this->DNI = DNI;
	this->estacion_destino = estacion_destino;
	this->estacion_origen = estacion_origen;
	this->fecha = fecha;
	this->hora_ascenso = hora_ascenso;
	this->hora_descenso = hora_descenso;
	this->nombre = nombre;
	this->peso = peso;
	this->cont_pasajeros++;
}

void cPasajero::imprimir()
{
}

string cPasajero::to_string()
{
	return string();
}
