#include "cListaVagones.h"

cListaVagones::cListaVagones(unsigned int tam)
{
	lista = new cVagon*[tam]; //pedimos memoria para crear la lista
	for (unsigned int i = 0; i < tam; i++)
	{
		//incializamos toda la lista en null
		lista[i] = NULL;
	}
	//incializamos los otros dos atributos del contructor
	this->tam = tam;
	n_vagones = 0;
}

bool cListaVagones::agregar_vagon(cVagon *vagon)
{
	/*El método tiene que lanzar una excepción en el caso de que el tren
	supere su peso o largo máximo de vagones*/
	
	//FALTA AGG EXCEPCION

	if (n_vagones < tam) //verfiamos que haya lugar
		lista[n_vagones++] = vagon;//agregamos el pasajero al final de la lista
	else return false; //no se pudo agregar (preguntar si se puede poner una excepcion)

	return true; //si se pudo agregar con normalidad
}

cVagon* cListaVagones::quitar_vagon(unsigned int ID)
{
	//¿elimina un vagon de manera aletoria o le pasamos el vagon espeifico que deseamos eliminar?
	//int pos = 1 + rand() % (n_vagones - 1); //generamos una posicion aletoria
	unsigned int pos = buscar_pos(ID);
	cVagon *aux = lista[pos]; //buscamos esa posicion en la lista

	//recorremos la lista desde esa posicion en adelante
	for (unsigned int i = 0; i < n_vagones - 1; i++)
	{
		//adelantamos un lugar todos los elementos de la lista
		lista[i] = lista[i + 1];
	}
	//ponemos el ultimo lugar en NULL.
	lista[n_vagones - 1] = NULL;

	return aux; //retornamos el vagon que quitamos de la lista
}

void cListaVagones::eliminar_vagon(unsigned int ID)
{
	unsigned int pos = buscar_pos(ID); //buscamos la posicion del vagon a eliminar
	if (pos >= n_vagones) //verificamos que exita la posicion
		return; //sale de la funcion ya que no se puede eliminar.

	cVagon *aux = quitar_vagon(pos); //llamamos a la funcion quitar para sacar al vagon de la lista

	if (aux != NULL) //verficamos que el elemento sea distinto de NULL.
		delete aux; //si es distinto de NULL lo eliminamos

    /* VEEEERR
	{
		throw new exception("no encontrado");
	}7*/
}

unsigned int cListaVagones::buscar_pos(unsigned int ID)
{
	unsigned int pos = 0; //nos creamos una variable para almacenar la poscion 
	for (unsigned int i = 0; i < n_vagones; i++) //recorremos la lista
	{
		if (lista[i]->get_id== ID) //buscamos los ID que coinciden 
			pos= i; //nos guardamos la posicon 
	}

	return pos; //retornamos la posicion 
}
