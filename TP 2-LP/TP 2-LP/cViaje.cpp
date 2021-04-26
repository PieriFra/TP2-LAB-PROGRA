#include "cViaje.h"

cViaje::cViaje(tm fecha, tm hora_partida, tm hora_llegada, string estacion_origen, string estacion_actual, string estacion_final)
{
	this->estacion_actual = estacion_actual;
	this->estacion_final = estacion_final;
	this->estacion_origen = estacion_origen;
	this->fecha = fecha;
	this->hora_llegada=hora_llegada;
	this->hora_partida = hora_partida;

}

void cViaje::imprimir()
{
}

string cViaje::to_string()
{
	return string();
}
