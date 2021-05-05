#include "cListaViajes.h"
#include <sstream>

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
	n_viajes = 0;
}

cListaViajes::~cListaViajes()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_viajes; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}
}

bool cListaViajes::AgregarViaje(cViaje *viaje)
{
	if (n_viajes < tam) //verfiamos que haya lugar
		lista[n_viajes++] = viaje;//agregamos el pasajero al final de la lista e incrementamos la cantidad de pasajeros en la lista
	else return false; //no se pudo agregar (preguntar si se puede poner una excepcion)

	return true; //si se pudo agregar con normalidad
}

void cListaViajes::redimencionalizar()
{
	lista = new cViaje*[tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}
}

string cListaViajes::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream slv; /*creamos un buffer para concatenar todos los atributos de la clase*/

	slv << "Lista de Viajes: " << endl;
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_viajes; i++)
		{
			if (lista[i] != NULL)
				slv << lista[i]->to_string() << endl;
		}
	}
	return slv.str();
}

void cListaViajes::imprimir()
{
	cout << to_string() << endl;
}
