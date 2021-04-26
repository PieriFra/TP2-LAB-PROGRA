#include "cRegistro.h"

cRegistro::cRegistro(string DNI, tm fehca, tm hora_bajada, tm hora_subida, unsigned int ID_tren, unsigned int ID_vagon)
{
	this->DNI = DNI;
	this->fecha = fecha;
	this->hora_bajada = hora_bajada;
	this->hora_subida= hora_subida;
	this->ID_tren = ID_tren;
	this->ID_vagon = ID_vagon;

}

void cRegistro::imprimir()
{
}

string cRegistro::to_string()
{
	return string();
}
