#include "cViaje.h"
#include "Definiciones.h"
#include <sstream>

cViaje::cViaje(tm fecha, tm hora_partida, tm hora_llegada, eEstacion estacion_origen, 
	eEstacion estacion_actual, eEstacion estacion_final)
{
	this->estacion_actual = estacion_actual;
	this->estacion_final = estacion_final;
	this->estacion_origen = estacion_origen;
	this->fecha = fecha;
	this->hora_llegada=hora_llegada;
	this->hora_partida = hora_partida;

}
string cViaje::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream sv; /*creamos un buffer para concatenar todos los atributos de la clase*/
	sv << "Fecha: " << fecha.tm_mday<<"/"<<fecha.tm_mon<<"/"<<fecha.tm_year << endl;
	sv << "Estacion de Origen: " << ConvertEstacionString(estacion_origen) << endl;
	sv << "Estacion de Destino: " << ConvertEstacionString(estacion_final) << endl;
	sv << "Estacion de Actual: " << ConvertEstacionString(estacion_actual) << endl;
	sv << "Hora Partida: " << hora_partida.tm_hour<<":"<<hora_partida.tm_min << endl;
	sv << "Hora Llegada: " << hora_llegada.tm_hour << ":" << hora_llegada.tm_min << endl;

	return sv.str();
}

void cViaje::imprimir()
{
	cout << to_string() << endl;
}

