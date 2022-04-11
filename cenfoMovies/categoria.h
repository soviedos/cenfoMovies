#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class categoria
{
	private:
		string nombre;

		categoria* sgte;
		categoria* ant;

	public:
		categoria(); // constructor de la clase
		categoria(string); // constructor sobrecargado

		string getNombre();
		categoria* getSgte();
		categoria* getAnt();

		void setNombre(string);
		void setSgte(categoria*);
		void setAnt(categoria*);
};

