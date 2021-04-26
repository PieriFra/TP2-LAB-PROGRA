#include "cLocomotora.h"

cLocomotora::cLocomotora(const unsigned int num_chapa, unsigned int potencia, float peso,
	float peso_max, float largo):num_chapa(num_chapa)
{
	this->largo = largo;
	this->peso = peso;
	this->peso_max = peso_max;
	this->potencia = potencia;
}

void cLocomotora::imprimir()
{
}

string cLocomotora::to_string()
{
	return string();
}
