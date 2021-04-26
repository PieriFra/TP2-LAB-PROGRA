#include "cListaPasajeros.h"

cListaPasajeros::cListaPasajeros(unsigned int tam)
{
	lista = new cPasajero*[tam]; //pedimos memoria para crear la lista
		for (unsigned int i = 0; i < tam; i++)
		{
			//incializamos toda la lista en null
			lista[i] = NULL;
		}
		//incializamos los otros dos atributos del contructor
		this->tam = tam;
		n_pasajeros = 0;
}

void cListaPasajeros::QuitarPasajero(cPasajero *pasajero)
{
	int pos = 1 + rand() % (n_pasajeros - 1); //generamos una posicion aletoria

	cPasajero *aux = lista[pos]; //buscamos esa posicion en la lista

	//recorremos la lista desde esa posicion en adelante
	for (unsigned int i = 0; i < n_pasajeros - 1; i++) 
	{
		//adelantamos un lugar todos los elementos de la lista
		lista[i] = lista[i + 1];
	}
	//en el ultimo lugar agregamos el nuevo pasajero.
	lista[n_pasajeros - 1] = pasajero; 
}

bool cListaPasajeros::AgregarPasajero(cPasajero * pasajero)
{
	if (n_pasajeros < tam) //verfiamos que haya lugar
		lista[n_pasajeros++] = pasajero;//agregamos el pasajero al final de la lista
	else return false; //no se pudo agregar (preguntar si se puede poner una excepcion)

	return true; //si se pudo agregar con normalidad
}
