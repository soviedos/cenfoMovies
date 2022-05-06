#include <iostream>
#include <stdlib.h>
#include "listaCategorias.h"
#include "listaAsociacion.h"

listaAsociacion* LA = new listaAsociacion();

listaCategorias::listaCategorias()
{
    this->cab = NULL;
    this->largo = 0;
}

categoria* listaCategorias::getCab()
{
    return this->cab;
}

int listaCategorias::getLargo()
{
    return this->largo;
}

void listaCategorias::setCab(categoria* _cab)
{
    this->cab = _cab;
}

void listaCategorias::setLargo(int _largo)
{
    this->largo = _largo;
}

bool listaCategorias::agregarCategoria(string _nombre, int _cantPeliculas)
{
    bool agregado = false;

    if (cab == NULL) {
        categoria* nuevo = new categoria(_nombre, _cantPeliculas);
        setCab(nuevo);
        setLargo(1);
        agregado = true;
    }
    else if (getLargo() == 1) {
        if (_nombre.compare(getCab()->getNombre()) < 0) {
            categoria* nuevo = new categoria(_nombre, _cantPeliculas);
            nuevo->setSgte(cab);
            setCab(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
        else if (_nombre.compare(getCab()->getNombre()) > 0) {
            categoria* nuevo = new categoria(_nombre, _cantPeliculas);
            nuevo->setSgte(NULL);
            cab->setSgte(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    else if (getLargo() > 1) {
        categoria* aux = getCab();

        while (aux->getSgte() != NULL && !agregado) {
            if (_nombre.compare(getCab()->getNombre()) < 0) {
                categoria* nuevo = new categoria(_nombre, _cantPeliculas);
                nuevo->setSgte(cab);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if ((_nombre.compare(aux->getNombre()) > 0) && (_nombre.compare(aux->getSgte()->getNombre()) < 0)) {
                categoria* nuevo = new categoria(_nombre, _cantPeliculas);
                nuevo->setSgte(aux->getSgte());
                aux->setSgte(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else {
                aux = aux->getSgte();
            }
        }
        if (aux->getSgte() == NULL && _nombre.compare(aux->getNombre()) > 0) {
            categoria* nuevo = new categoria(_nombre, _cantPeliculas);
            aux->setSgte(nuevo);
            nuevo->setSgte(NULL);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    return agregado;
}

bool listaCategorias::cerrar(string _nombre)
{
    bool eliminada = false;
    categoria* aux = getCab();
    categoria* ante = NULL;

    while (aux != NULL) {
        if ((_nombre.compare(aux->getNombre()) == 0)) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux == cab && largo > 1) {
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() != NULL) {
                ante->setSgte(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() == NULL) {
                ante->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
        }
        else {
            ante = aux;
            aux = aux->getSgte();
        }
    }
    return eliminada;
}

bool listaCategorias::modificarCategoria(string _nombre)
{
    bool modificada = false;
    categoria* aux = getCab();

    while (aux != NULL) {
        if ((_nombre.compare(aux->getNombre()) == 0)) {
            string nombre = aux->getNombre();
            int cantPeliculasAsoc = aux->getCantPeliculasAsoc();
            cout << "Ingresar el nuevo nombre de la categoria: ";
            cin >> nombre;
            cerrar(aux->getNombre());
            agregarCategoria(nombre, cantPeliculasAsoc);
            modificada = true;
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
    return modificada;
}

void listaCategorias::consultarCategoria(string _nombre)
{
    categoria* aux = getCab();
    bool encontrada = false;

    while (aux != NULL) {
        if ((_nombre.compare(aux->getNombre()) == 0)) {
            cout << "Nombre de la categoria: " << aux->getNombre() << endl;
            cout << "Cantidad de peliculas asociadas a la categoria: " << aux->getCantPeliculasAsoc() << endl;
            cout << endl;
            encontrada = true;
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
    if (!encontrada) {
        cout << "No se pudo encontrar la categoria en el catalogo" << endl;
    }
}

void listaCategorias::catalogoCategorias()
{
    categoria* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            cout << "Nombre de la categoria: " << aux->getNombre() << endl;
            cout << "Cantidad de peliculas asociadas: " << aux->getCantPeliculasAsoc() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

bool listaCategorias::agregarPelicula(int _pelicula, string _nombre)
{
    bool agregada = false;
    agregada = LA->agregarPelicula(_pelicula, _nombre);
    return agregada;
}

void listaCategorias::retirarPelicula(int _pelicula, string _nombre)
{
}

void listaCategorias::consultarPeliculaCategoria(string _nombre)
{
    LA->consultarPelCategoria(_nombre);
}

void listaCategorias::catalogoCategoriasCodigoNombre()
{

}

void listaCategorias::catalogoCategoriasDetalles()
{
}

categoria* listaCategorias::retornarCategoria(string _nombre)
{
    categoria* aux = NULL;

    if (cab != NULL) {
        aux = getCab();
        bool encontrado = false;

        while (aux != NULL && !encontrado) {
            if (aux->getNombre() == _nombre)
                encontrado = true;
            else
                aux = aux->getSgte();
        }
    }
    return aux;
}

void listaCategorias::agregarCantPeliculas(string _nombre)
{
    categoria* aux = getCab();

    while (aux != NULL) {
        if ((_nombre.compare(aux->getNombre()) == 0)) {
            aux->setCantPeliculasAsoc(aux->getCantPeliculasAsoc() +1);
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
}
