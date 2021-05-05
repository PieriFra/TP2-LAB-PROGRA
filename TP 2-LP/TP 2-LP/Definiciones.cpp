#include "Definiciones.h"

string ConvertEstacionString(eEstacion estacion)
{
	
		switch (estacion)
		{
		case eEstacion::Hospitales:
			return "Hospitales";
			break;
		case eEstacion::ParquePtricio:
			return "Parque Patricios";
			break;
		case eEstacion::Caseros:
			return "Caseros";
			break;
		case eEstacion::Inclan:
			return "Inclan";
			break;
		case eEstacion::Humberto:
			return "Humberto";
			break;
		case eEstacion::Venezuela:
			return "Venezuela";
			break;
		case eEstacion::Once:
			return "Once";
			break;
		case eEstacion::Corrientes:
			return "Corrientes";
			break;
		case eEstacion::Cordoba:
			return "Cordoba";
			break;
		case eEstacion::SantaFe:
			return "Santa Fe";
			break;
		case eEstacion::LasHeras:
			return "Las Heras";
			break;
		case eEstacion::FacultadDerecho:
			return "Facultad de Derecho";
			break;
		
		}	
}
