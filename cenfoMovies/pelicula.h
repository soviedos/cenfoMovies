#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class pelicula
{
	private:
		int id;
		string nombre;
		int anno;
		string director;
		int cantSolicitudes;

		pelicula* sgte;
		pelicula* ant;

	public:
		pelicula(); // constructor de la clase
		pelicula(int, string, int, string, int); // constructor sobrecargado

		int getId();
		string getNombre();
		int getAnno();
		string getDirector();
		int getCantSolicitudes();
		pelicula* getSgte();
		pelicula* getAnt();

		void setId(int);
		void setNombre(string);
		void setAnno(int);
		void setDirector(string);
		void setCantSolicitudes(int);
		void setSgte(pelicula*);
		void setAnt(pelicula *);
};
