#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class categoria
{
	private:
		string nombre;
		int cantPeliculasAsoc;

		categoria* sgte;

	public:
		categoria(); // constructor de la clase
		categoria(string, int); // constructor sobrecargado

		string getNombre();
		int getCantPeliculasAsoc();
		categoria* getSgte();

		void setNombre(string);
		void setCantPeliculasAsoc(int);
		void setSgte(categoria*);
};

