#include "cListaRegistro.h"
#include <sstream>

cListaRegistro::cListaRegistro(unsigned int tam)
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

cListaRegistro::~cListaRegistro()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_registro; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}
}

void cListaRegistro::redimencionalizar()
{
	lista = new cRegistro*[tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}
}

bool cListaRegistro::CompararHorarios(tm HoraSubida, tm HoraBajada, cRegistro *registro)
{
	/*la funcion comprara los horarios subida y bajda de los pasajaeros con los horarios de subida 
	y bajda del registro infectado que pasamos como parametro. Se retorna 1,2,3,4 segun los posibles
	casos que se plantean en el TP*/

	if (HoraSubida.tm_hour <= registro->hora_subida.tm_hour &&
		HoraSubida.tm_min < registro->hora_subida.tm_min &&
		HoraBajada.tm_hour <= registro->hora_bajada.tm_hour &&
		HoraBajada.tm_min < registro->hora_bajada.tm_min)
			return true;
	if (HoraSubida.tm_hour >= registro->hora_subida.tm_hour && 
		HoraSubida.tm_min > registro->hora_subida.tm_min && 
		HoraBajada.tm_hour <= registro->hora_bajada.tm_hour &&
		HoraBajada.tm_min < registro->hora_bajada.tm_min)
			return true;
	if (HoraSubida.tm_hour >= registro->hora_subida.tm_hour &&
		HoraSubida.tm_min > registro->hora_subida.tm_min &&
		HoraBajada.tm_hour >= registro->hora_bajada.tm_hour &&
		HoraBajada.tm_min > registro->hora_bajada.tm_min)
			return true;
	if (HoraSubida.tm_hour <= registro->hora_subida.tm_hour &&
		HoraSubida.tm_min < registro->hora_subida.tm_min &&
		HoraBajada.tm_hour >= registro->hora_bajada.tm_hour &&
		HoraBajada.tm_min > registro->hora_bajada.tm_min)
			return true;
	
	return false;
}

bool cListaRegistro::AgregarRegistro(cRegistro *registro)
{
	if (n_registro < tam) //verfiamos que haya lugar
		lista[n_registro++] = registro;//agregamos el pasajero al final de la lista e incrementamos la cantidad de pasajeros en la lista
	else return false; //no se pudo agregar 

	return true; //si se pudo agregar con normalidad
}

cRegistro* cListaRegistro::BuscarPos(string DNI)
{
	unsigned int pos = 0; //nos creamos una variable para almacenar la poscion buscada
	for (unsigned int i = 0; i < n_registro; i++) //recorremos la lista
	{
		if (lista[i]->GetDNI() == DNI) //buscamos los DNI que coinciden 
			return lista[i]; //retornamos la posicion encontrada
	}

	
}

string cListaRegistro::SeguimientoEpidemiologico(string DNI)
{
	/*Realizar el seguimiento epidemiológico de un pasajero. Deberá poder pasarle un pasajero
	como DNI y obtener una lista de todos los DNIs de pasajeros que estuvieron en el mismo
	rango horario en el mismo vagón del mismo tren.*/

	//buscamos en la lista y nos almacenamos en un aux al pasajero infectado
	cRegistro *PInfectado = BuscarPos(DNI);//buscamos la posicion del pasajero infectado
	int cont = 0; //TAM total del array

	string *lista_dni = NULL;
	for (unsigned int i = 0; i < n_registro; i++)
	{
		if (PInfectado->ID_tren == lista[i]->ID_tren && PInfectado->ID_vagon == lista[i]->ID_vagon)
		{
			if (CompararHorarios(lista[i]->hora_subida, lista[i]->hora_bajada, PInfectado))
			{
				cont++; //voy contando la cantidad de pasajeros que tenemos que agregar
				string *aux = new string[cont]; //nos creamos un aux
				if (cont > 1) {
					for (int k = 0; k < cont - 1; k++)
					{
						aux[k] = lista_dni[k]; //copiamos en el aux la info que tenemos en la lista hasta ahora
					}
				}
				delete[] lista_dni;	//para que sea null	
				lista_dni = aux; //copiamos la info que teniamos antes mas el nuevo espacio en memoria
				lista_dni[cont-1] = (lista[i])->GetDNI(); //Copiamos el nuevo dni
			}
		}
	}
	
	stringstream DNIs;
	for (int i = 0; i < cont; i++)
	{
		DNIs << "DNI: " << lista_dni[i] << endl;
	}
	return DNIs.str(); //Devuevlo la lista de dni
}

string cListaRegistro::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream slr; /*creamos un buffer para concatenar todos los atributos de la clase*/

	slr << "Lista de Registros: " << endl;
	if (lista != NULL) {
		for (unsigned int i = 0; i < n_registro; i++)
		{
			if (lista[i] != NULL)
				slr << lista[i]->to_string() << endl;
		}
	}
	
	return slr.str();

}

void cListaRegistro::imprimir()
{
	cout << to_string() << endl;
}

