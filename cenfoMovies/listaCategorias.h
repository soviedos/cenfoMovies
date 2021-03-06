#pragma once
#include <iostream>
#include <stdlib.h>
#include "categoria.h"

using namespace std;

class listaCategorias
{
	private:
		categoria* cab;
		int largo;


	public:
		listaCategorias(); // Constructor de la clase

		categoria* getCab();
		int getLargo();

		void setCab(categoria*);
		void setLargo(int);

		// **********Operaciones del TAD**********

		bool agregarCategoria(string, int);
		bool cerrar(string);
		bool modificarCategoria(string);
		void consultarCategoria(string);
		void catalogoCategorias();
		bool agregarPelicula(int, string);
		void retirarPelicula(int, string);
		void consultarPeliculaCategoria(string);
		void catalogoCategoriasCodigoNombre();
		void catalogoCategoriasDetalles();

		// **********Operaciones miscelaneas**********

		categoria* retornarCategoria(string);
		void agregarCantPeliculas(string);
};

