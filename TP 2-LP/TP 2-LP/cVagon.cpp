#include "cVagon.h"
#include <sstream>

cVagon::cVagon(unsigned int ID, unsigned int CantMax_Pasajeros, float peso_vagon,
	float peso_pasajeros, float largo_vagon, cListaPasajeros *lista_pasajeros) : CantMax_Pasajeros(CantMax_Pasajeros)
{
	this->ID = ID;
	this->largo_vagon = largo_vagon;
	this->peso_pasajeros = peso_pasajeros;
	this->peso_vagon = peso_vagon;
	this->lista_pasajeros = lista_pasajeros;

}

void cVagon::SumarPesos()
{
	/*modificar el peso al total cada vez que un pasajero baja o sube*/

	unsigned int n = lista_pasajeros->get_n_pasajeros();

	float acum = 0;
	for (unsigned int i = 0; i < n; i++) //recorremos la lista de pasajeros
	{
		if (lista_pasajeros->GetPasajero(i) == NULL) //verificamos que el ptr no seal nulo
			return;
		//accedemos a los pesos de los pasajeros de la lista y los sumamos
		acum = acum + lista_pasajeros->GetPasajero(i)->get_peso();
	}
	set_PesoPasajeros(acum); //modificamos el valor del peso total de los pasajeros
}

void cVagon::AgregarPasajero(cPasajero *pasajero)
{
	/*Además, para cumplir con los protocolos, la cantidad de pasajeros permitidos por vagón
	se reduce a un 25% de la habitual por lo que cuando el vagón está completo y quiere
	subirse otro pasajero puede suceder, de forma equiprobable, una de tres cosas:
	a) El pasajero no puede subir al vagón, se lanza una excepción indicando esto.
	b) Un pasajero aleatorio del vagón es echado para que pueda subir el nuevo
	pasajero.
	c) El pasajero sube igual, rompiendo los protocolos de COVID.*/
	//obtenemos el 25% de la capcidad maxima 

	unsigned int cant_covid = CantMax_Pasajeros * 25 / 100;
	if (lista_pasajeros->get_n_pasajeros() < cant_covid)
	{
		(lista_pasajeros)->AgregarPasajero(pasajero); //Se sube un pasajero al vagon de manera normal
		SumarPesos(); //modifico el peso total de los pasajeros
	}
	else
	{
		//en caso de que el vagon este lleno 
		unsigned int opcion = 1+ rand() % (4 - 1); //generamos numeros aletorios entre 1 y 3
		
		switch (opcion)
		{ 
		case 1: 
		{
			throw new exception("La capacidad del vagon esta completa, el pasajero no puede abordar.");
				break;  }
		case 2: {
			(lista_pasajeros)->QuitarPasajeroAleatorio(pasajero); //echa un pasajero aletorio
			SumarPesos(); //modifico el peso total de los pasajeros
			break; }
		case 3: {
			(lista_pasajeros)->AgregarPasajero(pasajero);//sube al pasajero de todos modos, rompiendo con los protocolos
			SumarPesos(); //modifico el peso total de los pasajeros
			break; }
		}

	}
	
	
}

void cVagon::EcharPasajerosPesados()
{
	lista_pasajeros->OrdenarLista(); //ordenamos la lista de mayor a menos segun los pesos
	//verifiacamos que haya mas de tres pasajeros en la lista
	if (lista_pasajeros->n_pasajeros < 3) 
		return;
	//nos quedamos con las tres primeras posiciones de la lista, que son los tres pasajeros mas pesados
	for (int i = 0; i < 3; i++) 
	{  //los quitamos y eleminamos de la lista
		lista_pasajeros->EliminarPasajero(lista_pasajeros->GetPasajero(i));
	}
}

string cVagon::to_string()
{
	/*Este metodo convierte todo los atributos de la clase a un tipo de dato string*/
	stringstream sv; /*creamos un buffer para concatenar todos los atributos de la clase*/
	sv << "ID: " << ID << endl;
	sv << "Peso Vagon: " << peso_vagon << endl;
	sv << "Largo Vagon: " << largo_vagon << endl;
	sv << "Cantidad Maxima de Pasajeros: " << CantMax_Pasajeros << endl;
	sv << "Peso Pasajeros: " << peso_pasajeros << endl;
	if (lista_pasajeros != NULL)
		sv <<endl<< lista_pasajeros->to_string() << endl;
	
	return sv.str();
}

void cVagon::imprimir()
{
	cout << to_string() << endl;
}



