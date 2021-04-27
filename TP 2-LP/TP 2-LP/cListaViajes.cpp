#include "cListaViajes.h"

cListaViajes::cListaViajes(unsigned int tam)
{
	lista = new cViaje*[tam]; //pedimos memoria para crear la lista
	for (unsigned int i = 0; i < tam; i++)
	{
		//incializamos toda la lista en null
		lista[i] = NULL;
	}
	//incializamos los otros dos atributos del contructor
	this->tam = tam;
	n_vagones = 0;
}
