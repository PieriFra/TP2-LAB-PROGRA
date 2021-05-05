#include "cListaEstaciones.h"

cListaEstaciones::cListaEstaciones(unsigned int tam)
{
	lista = new cEstaciones*[tam]; //pedimos memoria para crear la lista
		//incializamos toda la lista con los nombre correspondientes en cada estacion
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}
		//incializamos los otros dos atributos del contructor
		this->tam = tam;
		n_estaciones = 0;
	
}

cListaEstaciones::~cListaEstaciones()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_estaciones; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}
}


void cListaEstaciones::redimencionalizar()
{
	lista = new cEstaciones*[tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}
}

string cListaEstaciones::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream sle; /*creamos un buffer para concatenar todos los atributos de la clase*/
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_estaciones; i++)
		{
			if (lista[i] != NULL)
				sle << lista[i]->to_string() << endl;
		}
	}
	return sle.str();
}

void cListaEstaciones::imprimir()
{
	cout << to_string() << endl;
}

bool cListaEstaciones::AgregarEstacion(cEstaciones * estacion)
{
	if (n_estaciones < tam) //verfiamos que haya lugar
		lista[n_estaciones++] = estacion;//agregamos el pasajero al final de la lista 
										//e incrementamos la cantidad de pasajeros en la lista
	else return false; //no se pudo agregar (preguntar si se puede poner una excepcion)
	return true; //si se pudo agregar con normalidad
}
