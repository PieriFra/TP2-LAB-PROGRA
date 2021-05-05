#include "cRegistro.h"
#include <sstream>

cRegistro::cRegistro(string DNI, tm fecha, tm hora_bajada, tm hora_subida, unsigned int ID_tren, unsigned int ID_vagon)
{
	this->DNI = DNI;
	this->fecha = fecha;
	this->hora_bajada = hora_bajada;
	this->hora_subida= hora_subida;
	this->ID_tren = ID_tren;
	this->ID_vagon = ID_vagon;
}

string cRegistro::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream sr; /*creamos un buffer para concatenar todos los atributos de la clase*/
	
	sr << "DNI: " << DNI << endl;
	sr << "Fecha: " << fecha.tm_mday << "/" << fecha.tm_mon << endl;
	sr << "ID Tren: " << ID_tren << endl;
	sr << "ID Vagon " << ID_vagon << endl;
	sr << "Hora de Ascenso: " << hora_subida.tm_hour << ":" << hora_subida.tm_min << endl;
	sr << "Hora de Descenso: " << hora_bajada.tm_hour << ":" << hora_bajada.tm_min << endl;

	return sr.str();
}

void cRegistro::imprimir()
{
	cout << to_string() << endl;
}
