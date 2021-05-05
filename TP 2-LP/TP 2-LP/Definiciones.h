#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <sstream>
using namespace std;

enum class eEstacion {
	Hospitales = 1,
	ParquePtricio,
	Caseros,
	Inclan,
	Humberto,
	Venezuela,
	Once,
	Corrientes,
	Cordoba,
	SantaFe,
	LasHeras,
	FacultadDerecho,
	ENUM_MAX
};

string ConvertEstacionString(eEstacion estacion);

