#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

class cLocomotora
{//Atributos
private:
	const unsigned int num_chapa;
	unsigned int potencia;
	float peso, peso_max, largo, largo_max;
public:
	cLocomotora(const unsigned int num_chapa, unsigned int potencia, float peso, float peso_max, 
		 float largo, float largo_max);//Constructor
	~cLocomotora() {};//destructor

	friend class cTren;

	//metodos
	//void SetPesoMax(float peso_max) { this->peso_max; }
	//void SetLargoMax(float largo_max) { this->largo_max; }
	float get_pesomax() { return peso_max;  }
	float get_largomax() { return largo_max; }
	void imprimir();
	string to_string();
};

