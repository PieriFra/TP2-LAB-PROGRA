#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include "Funciones.h"
#include "cVagon.h"
using namespace std;

void excep_SubirPasajero(cVagon vagon){
	/*El pasajero no puede subir al vagón, se lanza una excepción indicando esto.*/

	int cant_covid = vagon.GetCantMaxPasajeros()* 25 / 100;
	try
	{
		//comportamient normal: que no se supere la cantidad estipulada por protocolo
		vagon.GetCantMaxPasajeros() < cant_covid;
	}
	catch (...)//comportamiento excepcional
	{
		cout << "La capcidad del vagon esta completa, el pasajero no puede abordar" << endl;
	}
}
void EcharPasajero(cVagon *vagon) {
	/*Un pasajero aleatorio del vagón es echado para que pueda subir el nuevo
	pasajero.*/

	int rand_pasajero = 1 + rand() % (26 - 1); 
	for (int i = 0; i < length; i++)
	{

	}
}