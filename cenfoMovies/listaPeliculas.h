#pragma once
#include <iostream>
#include <stdlib.h>
#include "pelicula.h"

using namespace std;

class listaPeliculas
{
	private:
		pelicula* cab;
		int largo;

	public:
		listaPeliculas(); // Constructor de la clase

		pelicula* getCab();
		int getLargo();

		void setCab(pelicula*);
		void setLargo(int);

		// **********Operaciones del TAD**********

		bool agregarPelicula(int, string, int, string, int, int); // Las peliculas van ordenadas ascendentemente por id.
		bool retirarPelicula(int); 
		pelicula* consultarPelicula(int);
		bool modificarPelicula(int);

		void listarCatalogoPorCodigo();
		listaPeliculas* listarCatalogoPorNombre();
		listaPeliculas* listarCatalogoPorHilera(int);
		listaPeliculas* listarCatalogoPorRango(int);
		listaPeliculas* listarCatalogoPorLimite(int);
		listaPeliculas* listarPeliculasSinCategoria();

		bool eliminarPeliculasPorLimite(int);
};

