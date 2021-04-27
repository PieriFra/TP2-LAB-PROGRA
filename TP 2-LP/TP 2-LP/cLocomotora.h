#pragma once
#include <string.h>
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;

class cLocomotora
{
private:
	const unsigned int num_chapa;
	unsigned int potencia;
	float peso, peso_max, largo, largo_max;
public:
	cLocomotora(const unsigned int num_chapa, unsigned int potencia, float peso, 
		float peso_max, float largo, float largo_max);
	~cLocomotora() {};

	void imprimir();
	string to_string();
};

