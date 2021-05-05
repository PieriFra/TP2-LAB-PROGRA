#include "cEstaciones.h"
#include <sstream>

cEstaciones::cEstaciones(eEstacion nom_estacion)
{
	this->nom_estacion=nom_estacion;
}

string cEstaciones::to_string()
{
	return  "Nombre Estcion: " + ConvertEstacionString(nom_estacion) + "\n" ;
}

void cEstaciones::imprimir()
{
	cout << to_string() << endl;
}
