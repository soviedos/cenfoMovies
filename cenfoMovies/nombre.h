#pragma once
#include <iostream>
#include <stdlib.h>
#include "pelicula.h"

using namespace std;

class nombre
{
private:
	pelicula* dato;

	nombre* sgte;
	nombre* ante;

public:
	nombre(); // constructor de la clase
	nombre(pelicula*); // constructor sobrecargado

	pelicula* getDato();
	nombre* getSgte();
	nombre* getAnte();

	void setNombre(pelicula*);
	void setSgte(nombre*);
	void setAnte(nombre*);
};

