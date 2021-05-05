#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Definiciones.h"
#include "cPasajero.h"
#include "cListaVagones.h"
#include "cListaEstaciones.h"
#include "cListaRegistro.h"
#include "cRegistro.h"
#include "cTren.h"
using namespace std;

int menu();
eEstacion EstacionDestino();
cPasajero *CargarPasajero(eEstacion EstacionOrigen);
void SubirPasajero(cTren *Tren, eEstacion EstacionActual, cListaRegistro *Registros);
void BajarPasajero(cListaVagones *ListaVagones, eEstacion EstacionActual);