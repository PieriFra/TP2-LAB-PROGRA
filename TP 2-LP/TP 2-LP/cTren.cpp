#include "cTren.h"
#include <sstream>

cTren::cTren(unsigned int ID, cLocomotora *locomotora, cListaVagones *lista_vagones,
	cListaViajes *lista_viajes)
{
	this->ID = ID;
	this->locomotora=locomotora;
	//VER SI ESTA BIEN!!
	this->lista_vagones = lista_vagones;
	this->lista_viajes = lista_viajes;

}

string cTren::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream st; /*creamos un buffer para concatenar todos los atributos de la clase*/
	st << "ID:" << ID << endl;
	if(locomotora!=NULL) //verificamos que el puntero no sea nulo
		st << "Locomotroa: " << locomotora->to_string()<< endl; 
	if (lista_vagones != NULL)
		st << "Lista de Vagones: " << lista_vagones->to_string() << endl;
	if (lista_viajes != NULL)
		st << "Lista de Viajes: " << lista_viajes->to_string() << endl;

	return st.str();
}

void cTren::imprimir()
{
	cout << to_string() << endl;
}

float cTren::PesoTotalTren()
{
	//obtenemos el tamaño de la lista
	unsigned int n = lista_vagones->get_n_vagones();
	float PesoTotal = 0;

	//recorremos la lista 
	for (unsigned int i = 0; i < n; i++)
	{
		if (lista_vagones->get_vagon(i) != NULL)//verificamos que los punteros sean distintos de nulo
		{
			//sumamos todos los pesos de los vagones y los pasajeros que hay en ellos
			PesoTotal = PesoTotal + (lista_vagones->get_vagon(i)->get_PesoPasajeros()
				+ lista_vagones->get_vagon(i)->get_PesoVagon());
		}
	}

	return PesoTotal;
}
void cTren::VerificarPeso()
{
	/*Antes de salir de la estación, el tren debe verificar que el peso total del tren no
	es mayor al peso que puede acarrear la locomotora. En caso de que esto se
	supere, se toma un vagón aleatorio y se echan a los 3 pasajeros más pesados.
	El proceso se repite hasta que el tren pueda salir de la estación*/

	float PesoTren = PesoTotalTren(); //obtenemos el peso total del tren
	//generamos una posicion aleatoria para acceder a un vagon cualquiera.
	int pos = 1 + rand() % lista_vagones->get_n_vagones() - 1; 
	if (PesoTren > locomotora->peso)
	{
		cVagon *aux= lista_vagones->get_vagon(pos); //accedemos a un vagon aleatorio
		aux->EcharPasajerosPesados(); //invocamos al metodo para echar a los tres pasajeros mas pesados
	}
}

