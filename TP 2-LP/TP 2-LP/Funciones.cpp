#include "Funciones.h"


int menu()
{
	int opcion = 0;

	cout << "Bienvendio! Ingrese el numero de su estacion de destino." << endl;
	cout << "1. Hospitales" << endl;
	cout << "2. Parque Patricios" << endl;
	cout << "3. Caseros" << endl;
	cout << "4. Inclan" << endl;
	cout << "5. Humberto" << endl;
	cout << "6. Venezuela" << endl;
	cout << "7. Once" << endl;
	cout << "8. Corrientes" << endl;
	cout << "9. Cordoba" << endl;
	cout << "10. Santa Fe" << endl;
	cout << "11. Las Heras" << endl;
	cout << "12. Facultad de Derecho" << endl;
	cout << "13. Salir" << endl;

	cin >> opcion;
	return opcion;
}
eEstacion EstacionDestino()
{
	int opcion = 0;
	do
	{
		opcion = menu(); //invocamos la funcion menu
		//nos creamos un menu
		switch (opcion)
		{
		case 1: {
			return eEstacion::Hospitales;
			//return estacion.Estacion1;
			break; }
		case 2: {
			return eEstacion::ParquePtricio;
			break; }
		case 3: {
			return eEstacion::Caseros;
			break; }
		case 4: {
			return eEstacion::Inclan;
			break; }
		case 5: {
			return eEstacion::Humberto;
			break; }
		case 6: {
			return eEstacion::Venezuela;
			break; }
		case 7: {
			return eEstacion::Once;
			break; }
		case 8: {
			return eEstacion::Corrientes;
			break; }
		case 9: {
			return eEstacion::Cordoba;
			break; }
		case 10: {
			return eEstacion::SantaFe;
			break; }
		case 11: {
			return eEstacion::LasHeras;
			break; }
		case 12: {
			return eEstacion::FacultadDerecho;
			break; }
		}
		system("pause");
		system("cls");

	} while (opcion != 12);
}
cPasajero *CargarPasajero(eEstacion EstacionOrigen) {

	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm
	string nombre, DNI;
	float peso;
	cout << "Ingrese su nombre: ";
	cin >> nombre;
	cout << "Ingrese su DNI: ";
	cin >> DNI;
	cout << "Ingrese su peso: ";
	cin >> peso;
	eEstacion EstacionDest = EstacionDestino();

	cPasajero *pasajero1 = new cPasajero (DNI, nombre, EstacionOrigen, EstacionDest, peso, *ltm, *ltm, *ltm);
	return pasajero1;
}
void SubirPasajero(cTren *tren, eEstacion EstacionActual, cListaRegistro *Registros) {
	
	/*nos genramos un numero aleatorio entre 1 y la cantidad de elementos de la lista de vagones
	para subir pasajeros de manera aleatoria a distinos vagones*/
	unsigned int n_vagon = tren->GetListaVagones()->get_n_vagones();
	int vagon_aleatorio = 1 + rand() % (n_vagon - 1);

	time_t hoy = time(0); //obtenemos la fecha actual
	tm *ltm = localtime(&hoy); //la convertimos al tipo de dato tm

	//llamamos a la funcion cargar pasajero para cargar los datos del pasajero que sube al tren
	cPasajero *Pasajero = CargarPasajero(EstacionActual);
	unsigned int ID_tren, ID_vagon;
	ID_tren = tren->get_ID();
	ID_vagon = tren->GetListaVagones()->get_vagon(vagon_aleatorio)->get_id();
	cRegistro *registro = new cRegistro(Pasajero->get_DNI(), *ltm, Pasajero->get_HoraBajada(),
		Pasajero->get_HoraSubida(), ID_tren, ID_vagon);
	Registros->AgregarRegistro(registro);
	if(tren != NULL)
		tren->GetListaVagones()->get_vagon(vagon_aleatorio)->AgregarPasajero(Pasajero);
}
void BajarPasajero(cListaVagones *ListaVagones, eEstacion EstacionActual) {
	
	if (ListaVagones != NULL)
	{
		//recorremos la lista de vagones 
		for (unsigned int i = 0; i < ListaVagones->get_n_vagones(); i++)
		{
			cVagon *vagon_actual = ListaVagones->get_vagon(i);
			if (vagon_actual != NULL)
			{
				unsigned int n_pasajeros = vagon_actual->lista_pasajeros->get_n_pasajeros();
				//Recorro la lista de pasajero del vagon en el que me encuentro
				for (unsigned int k = 0; k < n_pasajeros; k++)
				{
					//verficamos en cada vagon cuales son los pasajeros que deben bajar en esta estación
					//Es decir que buscamos auqellos pasajeros que su etaciones de destino coincida con la actual
					if (EstacionActual == vagon_actual->lista_pasajeros->GetPasajero(k)->get_EstacionDestino())
					{
						//si coincide con la estacion actual nos copiamos el pasajero a una variable aux
						cPasajero *aux = vagon_actual->lista_pasajeros->GetPasajero(k);
						//Accedemos a la lista del vagon actual y quitamos al pasajero correspondiente
						vagon_actual->lista_pasajeros->EliminarPasajero(aux);
						vagon_actual->SumarPesos(); //modifico el peso total de los pasajeros
					}
				}
			}

		}
	}

}