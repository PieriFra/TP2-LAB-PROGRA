#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <exception>
#include <string.h>
#include <time.h>
#include "cTren.h"
#include "cListaEstaciones.h"
#include "cListaRegistro.h"
#include "Funciones.h"
#include "cRegistro.h"
using namespace std;

cListaEstaciones *ListaEstaciones = new cListaEstaciones();

int main()
{
	/*Generar el main que deberá simular el funcionamiento del tren, deberá hacer que se mueva
	entre estaciones y en cada estación haga que suba y bajen pasajeros para generar más
	registros. Pruebe todos los métodos.*/

	cListaVagones *ListaVagones = new cListaVagones ();
	cListaViajes *ListaViajes = new cListaViajes();
	unsigned int ID = 1234;
	cLocomotora *Locomotora1 = new cLocomotora(22, 1500, 92, 60, 15.5, 60.5); //todos los pesos estan en toneladas, y los largos en metros
	cTren *tren1 = new cTren(ID, Locomotora1, ListaVagones, ListaViajes);
	
	cListaPasajeros *ListaPasajeros1 = new cListaPasajeros();
	cVagon *vagon1 = new cVagon(234, 30, 15, 0.0, 15.4, ListaPasajeros1);

	cListaPasajeros *ListaPasajeros2 = new cListaPasajeros();
	cVagon *vagon2= new cVagon(235, 30, 15, 0.0, 15.4, ListaPasajeros2);

	cListaPasajeros *ListaPasajeros3 = new cListaPasajeros();
	cVagon *vagon3= new cVagon(236, 30, 15, 0.0, 15.4, ListaPasajeros3);

	//agregamos tres vagones al tren 
	ListaVagones->agregar_vagon(vagon1, tren1->GetLocomotora());
	ListaVagones->agregar_vagon(vagon2, tren1->GetLocomotora());
	ListaVagones->agregar_vagon(vagon3, tren1->GetLocomotora());

	cListaRegistro *ListaRegistros = new cListaRegistro();

	//incializo la lista de estaciones
	cEstaciones *estacion1 = new cEstaciones(eEstacion::Hospitales);
	ListaEstaciones->AgregarEstacion(estacion1);
	cEstaciones *estacion2 = new cEstaciones(eEstacion::ParquePtricio);
	ListaEstaciones->AgregarEstacion(estacion2);
	cEstaciones *estacion3 = new cEstaciones(eEstacion::Caseros);
	ListaEstaciones->AgregarEstacion(estacion3);
	cEstaciones *estacion4 = new cEstaciones(eEstacion::Inclan);
	ListaEstaciones->AgregarEstacion(estacion4);
	cEstaciones *estacion5 = new cEstaciones(eEstacion::Humberto);
	ListaEstaciones->AgregarEstacion(estacion5);
	cEstaciones *estacion6 = new cEstaciones(eEstacion::Venezuela);
	ListaEstaciones->AgregarEstacion(estacion6);
	cEstaciones *estacion7 = new cEstaciones(eEstacion::Once);
	ListaEstaciones->AgregarEstacion(estacion7);
	cEstaciones *estacion8 = new cEstaciones(eEstacion::Corrientes);
	ListaEstaciones->AgregarEstacion(estacion8);
	cEstaciones *estacion9 = new cEstaciones(eEstacion::Cordoba);
	ListaEstaciones->AgregarEstacion(estacion9);
	cEstaciones *estacion10 = new cEstaciones(eEstacion::SantaFe);
	ListaEstaciones->AgregarEstacion(estacion10);
	cEstaciones *estacion11 = new cEstaciones(eEstacion::LasHeras);
	ListaEstaciones->AgregarEstacion(estacion11);
	cEstaciones *estacion12 = new cEstaciones(eEstacion::FacultadDerecho);
	ListaEstaciones->AgregarEstacion(estacion12);

	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm
	//nos creamos un pasajero infectado y cuatro pasajeros mas que hayan estado en contacto en los 
	//distinto casos, para testear el metodo SeguimientoEpidemiologico

	struct tm HoraSubida = { 0,45,15,0,0,0,0,0,0 };
	struct tm HoraBajada = { 0,15,16,0,0,0,0,0,0 };
	cPasajero *PasajeroInfectado = new cPasajero("34678982", "Florencia", eEstacion::Hospitales,
		eEstacion::Corrientes, 60.5, *ltm, HoraSubida, HoraBajada);
	cRegistro *registro = new cRegistro(PasajeroInfectado->get_DNI(), *ltm, PasajeroInfectado->get_HoraBajada(),
		PasajeroInfectado->get_HoraSubida(), tren1->get_ID(), vagon1->get_id());
	ListaRegistros->AgregarRegistro(registro);
	ListaPasajeros1->AgregarPasajero(PasajeroInfectado);

	struct tm HoraSubida1 = { 0,30,14,0,0,0,0,0,0 };
	struct tm HoraBajada1 = { 0,10,15,0,0,0,0,0,0 };
	cPasajero *Pasajero1 = new cPasajero("34765982", "Patricio", eEstacion::Caseros,
		eEstacion::Cordoba, 60.5, *ltm, HoraSubida1, HoraBajada1);
	cRegistro *registro1 = new cRegistro(Pasajero1->get_DNI(), *ltm, Pasajero1->get_HoraBajada(),
		Pasajero1->get_HoraSubida(), tren1->get_ID(), vagon1->get_id());
	ListaRegistros->AgregarRegistro(registro1);
	ListaPasajeros1->AgregarPasajero(Pasajero1);

	struct tm HoraSubida2 = { 0,40,15,0,0,0,0,0,0 };
	struct tm HoraBajada2 = { 0,30,16,0,0,0,0,0,0 };
	cPasajero *Pasajero2 = new cPasajero("4568982", "Laura", eEstacion::Once,
		eEstacion::LasHeras, 60.5, *ltm, HoraSubida2, HoraBajada2);
	cRegistro *registro2 = new cRegistro(Pasajero2->get_DNI(), *ltm, Pasajero2->get_HoraBajada(),
		Pasajero2->get_HoraSubida(), tren1->get_ID(), vagon1->get_id());
	ListaRegistros->AgregarRegistro(registro2);
	ListaPasajeros1->AgregarPasajero(Pasajero2);

	struct tm HoraSubida3 = { 0,50,15,0,0,0,0,0,0 };
	struct tm HoraBajada3 = { 0,05,16,0,0,0,0,0,0 };
	cPasajero *Pasajero3 = new cPasajero("22765982", "Gonzalo", eEstacion::SantaFe,
		eEstacion::FacultadDerecho, 60.5, *ltm, HoraSubida3, HoraBajada3);
	cRegistro *registro3 = new cRegistro(Pasajero3->get_DNI(), *ltm, Pasajero3->get_HoraBajada(),
		Pasajero3->get_HoraSubida(), tren1->get_ID(), vagon1->get_id());
	ListaRegistros->AgregarRegistro(registro3);
	ListaPasajeros1->AgregarPasajero(Pasajero3);


	struct tm HoraSubida4 = { 0,30,15,0,0,0,0,0,0 };
	struct tm HoraBajada4 = { 0,40,16,0,0,0,0,0,0 };
	cPasajero *Pasajero4 = new cPasajero("44765982", "Laura", eEstacion::Once,
		eEstacion::LasHeras, 60.5, *ltm, HoraSubida2, HoraBajada2);
	cRegistro *registro4 = new cRegistro(Pasajero4->get_DNI(), *ltm, Pasajero4->get_HoraBajada(),
		Pasajero4->get_HoraSubida(), tren1->get_ID(), vagon1->get_id());
	ListaRegistros->AgregarRegistro(registro4);
	ListaPasajeros1->AgregarPasajero(Pasajero4);

	ListaRegistros->imprimir();

	//invocamos al método SeguiminetoEpidemiologico
	string ListaDNI = ListaRegistros->SeguimientoEpidemiologico(PasajeroInfectado->get_DNI());
	cout << "Pasajeros en contacto con un caso postivo COVID-19: " << endl;
	cout << ListaDNI << endl;

	//Recorremos la lista de Estaciones para que el tren vaya avanzando de una a la otra
	/*for (unsigned int i = 0; i < ListaEstaciones->get_n_estaciones(); i++)
	{
		//obtenemos la estacion en la que se encuentra el tren
		eEstacion EstacionActual = ListaEstaciones->get_estacion(i)->GetNomEstacion();
		cout << "Usted se encuentra en la estacion: " << ConvertEstacionString(EstacionActual) << endl;
		cout << "Ingrese sus Datos. " << endl;

		cViaje *Viaje = new cViaje(*ltm, *ltm, *ltm, eEstacion::Hospitales, EstacionActual,
			eEstacion::FacultadDerecho);
		ListaViajes->AgregarViaje(Viaje);
		//subimos un pasajero a un vagon x del tren 
		SubirPasajero(tren1, EstacionActual, ListaRegistros);
		//bajamos un pasajro de un vagon x del tren 
		BajarPasajero(ListaVagones, EstacionActual); //Recordar añadir lista de registros
		//antes de salir de la estacion, verificamos que el peso y largo del tren no superen los maximos
		tren1->VerificarPeso();
		ListaViajes->imprimir();
		delete Viaje;

		//imprimimos las listas para verificar que se hayan ejecutado de manera correcta los metodos
		ListaPasajeros1->imprimir();
		ListaPasajeros2->imprimir();
		ListaPasajeros3->imprimir();
		ListaRegistros->imprimir();
	}*/
	 
	//Probamos todos los metodos que no utilizamos hata ahora
	//eliminamos un vagon del tren, para probar este metodo y el metodo quitar que esta contemplado en el primero
	ListaVagones->eliminar_vagon(vagon1->get_id());

	//Probamos el método subir Pasajero
	//nose creamos un vagon que este lleno
	cVagon *VagonCompleto = new cVagon(9910, 20, 15, 0, 15.4, ListaPasajeros1);
	cPasajero *Pasajero = new cPasajero("44765982", "Delfina", eEstacion::Once,
		eEstacion::LasHeras, 60.5, *ltm, HoraSubida2, HoraBajada2);
	//Una posibilidad es que se lance una excepcion
	//Agarramos la excepcion e imprimimos en pantalla que la capacidad de vagon esta completa
	try
	{
		VagonCompleto->AgregarPasajero(Pasajero); //probamos el metodos
	}
	catch (exception* ex)
	{
		cout <<ex->what()<< endl;
		delete ex;
	}
	//Si no se lanza la excepcion, pueden suceder otras dos cosas
	//Imprimos la lista de Pasjeros del vagon para ver si se hecho un pasajero alaetorio o si se rompieron los protcolos de covid
	VagonCompleto->imprimir();

	//Probamos el metodo AgregarVagones, el mismo lanza una excepcion si se supera el largo o peso maximo que puede acarrear el tren
	//Segun los datos ingresado en locomotora y en cada vagon que agg a la lista de vagones, agg un nuevo vagon se superarian el largo y peso max
	
	vagon2->imprimir();

	try
	{
		ListaVagones->agregar_vagon(VagonCompleto, tren1->GetLocomotora()); //probamos el metodo agg un nuevo vagon 
	}
	catch (exception *ex)
	{
		cout << ex->what() << endl;
		delete ex;
	}


	delete Pasajero1;
	delete Pasajero2;
	delete Pasajero3;
	delete Pasajero4;
	delete PasajeroInfectado;
	delete tren1;
	delete vagon2;
	delete vagon3;
	delete Locomotora1;
	ListaEstaciones->~cListaEstaciones();
	ListaPasajeros1->~cListaPasajeros();
	ListaPasajeros2->~cListaPasajeros();
	ListaPasajeros3->~cListaPasajeros();
	ListaRegistros->~cListaRegistro();
	ListaVagones->~cListaVagones();
	ListaViajes->~cListaViajes();

	
}