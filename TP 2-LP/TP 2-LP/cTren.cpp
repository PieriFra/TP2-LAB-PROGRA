#include "cTren.h"

cTren::cTren(unsigned int ID, cLocomotora locomotora, cVagon lista_vagones, cViaje lista_viajes)
{
	this->ID = ID;
	this->locomotora = locomotora;
	this->lista_vagones = lista_vagones;
	this->lista_viajes = lista_viajes;
}

string cTren::to_string()
{
	return string();
}

void cTren::imprimir()
{
}

void cTren::VerificarPeso()
{
}

