#include "cTren.h"

cTren::cTren(unsigned int ID, cLocomotora *locomotora, cListaVagones **lista_vagones,
	cListaViajes **lista_viajes)
{
	this->ID = ID;
	locomotora = NULL;
	//VER SI ESTA BIEN!!
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

