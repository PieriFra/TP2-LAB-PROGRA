#include "cPasajero.h"
#include <sstream>

cPasajero::cPasajero(string DNI, string nombre, eEstacion estacion_origen, eEstacion estacion_destino, 
	float peso, tm fecha, tm hora_ascenso, tm hora_descenso /*static int cont_pasajeros*/)
{
	this->DNI = DNI;
	this->estacion_destino = estacion_destino;
	this->estacion_origen = estacion_origen;
	this->fecha = fecha;
	this->hora_ascenso = hora_ascenso;
	this->hora_descenso = hora_descenso;
	this->nombre = nombre;
	this->peso = peso;
	//this->cont_pasajeros++;
}

string cPasajero::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream sp; /*creamos un buffer para concatenar todos los atributos de la clase*/

	sp << "Nombre: " << nombre << endl;
	sp << "DNI: " << DNI << endl;
	sp << "Peso: " << peso << endl;
	sp << "Fecha: " << fecha.tm_mday<<"/"<<fecha.tm_mon << endl;
	sp << "Estacion de Origen: " << ConvertEstacionString(estacion_origen) << endl;
	sp << "Estacion de Destino: " << ConvertEstacionString(estacion_destino) << endl;
	sp << "Hora de Ascenso: " << hora_ascenso.tm_hour << ":" << hora_ascenso.tm_min << endl;
	sp << "Hora de Descenso: " << hora_descenso.tm_hour << ":" << hora_descenso.tm_min << endl;

	return sp.str();
}
void cPasajero::imprimir()
{
	cout << to_string() << endl;
}

