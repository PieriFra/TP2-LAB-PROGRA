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

cListaVagones::~cListaVagones()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_vagones; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[]lista;
	}

}

void cListaVagones::redimencionalizar()
{
	lista = new cVagon*[tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}
}

void cListaVagones::agregar_vagon(cVagon *vagon, cLocomotora *locomotora)
{
	/*El método tiene que lanzar una excepción en el caso de que el tren
	supere su peso o largo máximo de vagones*/
	if (vagon != NULL)
	{
		float peso_tot = CalcularPesoTotal();
		float largo_total = ((n_vagones)*(vagon->get_LargoVagon())); //obtenemos el largo actual de los n vagones que tiene el tren
		if (locomotora != NULL)
		{
			if (locomotora->get_largomax() < largo_total && locomotora->get_pesomax() < peso_tot)
				throw new exception("Se supera el largo o el peso total de vagones. No se puede agregar otro vagon.");
		}
	}
	if (vagon!=NULL)
	{
		if (n_vagones < tam) //verfiamos que haya lugar
			lista[n_vagones++] = vagon; //agregamos el vagon al final de la lista
	}
	
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
	cVagon *aux = quitar_vagon(ID); //llamamos a la funcion quitar para sacar al vagon de la lista

	if (aux != NULL) //verficamos que el elemento sea distinto de NULL.
		delete aux; //si es distinto de NULL lo eliminamos
}

unsigned int cListaVagones::buscar_pos(unsigned int ID)
{
	unsigned int pos = 0; //nos creamos una variable para almacenar la poscion 
	for (unsigned int i = 0; i < n_vagones; i++) //recorremos la lista
	{
		if (lista[i]->get_id()== ID) //buscamos los ID que coinciden 
			pos= i; //nos guardamos la posicon 
	}

	return pos; //retornamos la posicion 
}

float cListaVagones::CalcularPesoTotal()
{
	//Calcula el peso total de los n vagones en la lista
	float PesotTotal = 0; //Declaramos un acumulador
	//Recorremos la lista de vagones
	lista[2]->get_PesoPasajeros();
	for (unsigned int i = 0; i < n_vagones; i++)
	{
		//en el acumulador guardamos la la suma de los pesos de los n vagones
		PesotTotal = PesotTotal + (lista[i]->get_PesoPasajeros() + lista[i]->get_PesoVagon());
	}
	
	return PesotTotal; //Retornamos el peso total calculado
}

string cListaVagones::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream slv; /*creamos un buffer para concatenar todos los atributos de la clase*/
	
	slv << "Lista de Vagones: " << endl;
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_vagones; i++)
		{
			if (lista[i] != NULL)
				slv << lista[i]->to_string() << endl;
		}
	}
	return slv.str();
}

void cListaVagones::imprimir()
{
	cout << to_string() << endl;
}

