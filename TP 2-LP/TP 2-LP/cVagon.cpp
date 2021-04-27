#include "cVagon.h"

cVagon::cVagon(unsigned int ID, unsigned int CantMax_Pasajeros, float peso_vagon, 
	float peso_pasajeros, float largo_vagon, cListaPasajeros lista_pasajeros): CantMax_Pasajeros(CantMax_Pasajeros)
{
	this->ID = ID;
	this->largo_vagon = largo_vagon;
	this->peso_pasajeros = peso_pasajeros;
	this->peso_vagon = peso_vagon;
	this->lista_pasajeros = lista_pasajeros; //verficar que este bien!!!
}

float cVagon::SumarPesos(float *peso_pasajeros, cPasajero lista_pasajeros[])
{
	/*modificar el peso al total cada vez que un pasajero baja o sube*/
	int tam = (sizeof(lista_pasajeros) / sizeof(lista_pasajeros[0]));
	float acum = 0;
	for (int i = 0; i < tam; i++)
	{
		acum = acum + lista_pasajeros[i].peso;
	}
	peso_pasajeros = &acum;
	return *peso_pasajeros; //pregunatar si asi esta bien!!!
}

void cVagon::SubirPasajero(cPasajero *pasajero)
{
	/*Además, para cumplir con los protocolos, la cantidad de pasajeros permitidos por vagón
	se reduce a un 25% de la habitual por lo que cuando el vagón está completo y quiere
	subirse otro pasajero puede suceder, de forma equiprobable, una de tres cosas:
	a) El pasajero no puede subir al vagón, se lanza una excepción indicando esto.
	b) Un pasajero aleatorio del vagón es echado para que pueda subir el nuevo
	pasajero.
	c) El pasajero sube igual, rompiendo los protocolos de COVID.*/

	int opcion = 1 + rand() % (4 - 1); //generamos numeros aletorios entre 1 y 3
	switch (opcion)
	{
	case 1: {
		int cant_covid = CantMax_Pasajeros* 25 / 100;
		try
		{
			//comportamient0 normal: que no se supere la cantidad estipulada por protocolo
			CantMax_Pasajeros < cant_covid;
		}
		catch (...)//comportamiento excepcional
		{
			cout << "La capcidad del vagon esta completa, el pasajero no puede abordar" << endl;
		}
		break; }
	case 2: {
		lista_pasajeros.QuitarPasajero(pasajero);
		break; }
	case 3: {
		lista_pasajeros.AgregarPasajero(pasajero);
		break; }
	}

}

void cVagon::imprimir()
{
	
}

string cVagon::to_string()
{
	return string();
}


