#include "cListaPasajeros.h"
#include <sstream>

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

cListaPasajeros::~cListaPasajeros()
{
	if (lista != NULL)
	{
		for (unsigned int i = 0; i < n_pasajeros; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}
}

void cListaPasajeros::redimencionalizar()
{
	lista = new cPasajero* [tam];
	for (unsigned int i = 0; i < tam; i++)
	{
		lista[i] = NULL;
	}

}

unsigned int cListaPasajeros::buscar_pos(string DNI)
{
	unsigned int pos = 0; //nos creamos una variable para almacenar la poscion 
	for (unsigned int i = 0; i < n_pasajeros; i++) //recorremos la lista
	{
		if (lista[i]->get_DNI() == DNI) //buscamos los ID que coinciden 
			pos = i; //nos guardamos la posicon 
	}

	return pos; //retornamos la posicion 
}

cPasajero* cListaPasajeros::QuitarPasajeroAleatorio(cPasajero *pasajero)
{
	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm
	pasajero->Set_HoraDescenso(*ltm); //modificamos la hora de ascenso

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

	return lista[pos]; //retornamos el pasajero que quitamos de la lista
}

cPasajero* cListaPasajeros::QuitarPasajero(cPasajero * pasajero)
{
	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm
	pasajero->Set_HoraDescenso(*ltm); //modificamos la hora de ascenso

	unsigned int pos = buscar_pos(pasajero->get_DNI());
	cPasajero *aux = lista[pos]; //buscamos esa posicion en la lista

	//recorremos la lista desde esa posicion en adelante
	for (unsigned int i = 0; i < n_pasajeros - 1; i++)
	{
		//adelantamos un lugar todos los elementos de la lista
		lista[i] = lista[i + 1];
	}
	//ponemos el ultimo lugar en NULL.
	lista[n_pasajeros - 1] = NULL;

	return lista[pos]; //retornamos el pasajero que quitamos de la lista
}
	
bool cListaPasajeros::AgregarPasajero(cPasajero * pasajero)
{
	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm

	pasajero->Set_HoraAscenso(*ltm); //modificamos la hora de ascenso
	if (n_pasajeros < tam) //verfiamos que haya lugar
		lista[n_pasajeros++] = pasajero;//agregamos el pasajero al final de la lista e incrementamos la cantidad de pasajeros en la lista
	else return false; //no se pudo agregar (preguntar si se puede poner una excepcion)
	
	return true; //si se pudo agregar con normalidad
}

void cListaPasajeros::EliminarPasajero(cPasajero *pasajero)
{
	cPasajero *aux = QuitarPasajero(pasajero); //llamamos a la funcion quitar para sacar al vagon de la lista

	if (aux != NULL) //verficamos que el elemento sea distinto de NULL.
		delete aux; //si es distinto de NULL lo eliminamos
}

cPasajero * cListaPasajeros::GetPasajero(int i)
{
	return lista[i];	
}

void cListaPasajeros::OrdenarLista()
{
	//ordenamos la lista de mayor a menor peso
	unsigned int contcambios, i, k;
	cPasajero *aux;
	for (i = 0; i < n_pasajeros - 1; i++)
	{
		contcambios = 0;
		for (k = 0; k < n_pasajeros - 1; k++)
		{
			if (GetPasajero(i)->get_peso() < GetPasajero(i+1)->get_peso())
			{
				aux = lista[i];
				lista[i] = lista[i + 1];
				lista[i + 1] = aux;

				contcambios++;
			}
		}
		if (contcambios == 0)
			break;
	}
}

string cListaPasajeros::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream slp; /*creamos un buffer para concatenar todos los atributos de la clase*/

	slp << "Lista de Pasajeros: " << endl;
	if (lista != NULL) {
		for (unsigned int i = 0; i < n_pasajeros; i++)
		{
			if (lista[i] != NULL)
				slp << lista[i]->to_string() << endl;
		}
	}
	return slp.str();
}

void cListaPasajeros::imprimir()
{
	cout << to_string() << endl;
}

