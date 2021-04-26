#include "cRegistros.h"

cRegistros::cRegistros(unsigned int tam)
{
	lista = new cRegistro*[tam]; //pedimos memoria para crear la lista
	for (unsigned int i = 0; i < tam; i++)
	{
		//incializamos toda la lista en null
		lista[i] = NULL;
	}
	//incializamos los otros dos atributos del contructor
	this->tam = tam;
	n_registro = 0;
}