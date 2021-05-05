#include "cLocomotora.h"
#include <sstream>

cLocomotora::cLocomotora(const unsigned int num_chapa, unsigned int potencia, float peso, 
	float peso_max, float largo, float largo_max):num_chapa(num_chapa)
{
	this->largo_max = largo_max;
	this->peso_max = peso_max;
	this->largo = largo;
	this->peso = peso;
	this->potencia = potencia;
}

string cLocomotora::to_string()
{
	/*Este metodo convierte todo los atributos de la
	clase a un tipo de dato string*/
	stringstream sl; /*definimos un buffer de tipo stringstream para concatenar
	todos los atributos de la clase*/
	sl << "Potencia: " << potencia << endl;
	sl << "Peso: " << peso << endl;
	sl << "Peso Maximo: " << peso_max << endl;
	sl << "Largo: " << largo << endl;
	sl << "Largo Maximo: " << largo_max << endl;

	return sl.str();
}

void cLocomotora::imprimir()
{
	cout << to_string() << endl;
}

