#include <iostream>
#include <stdlib.h>
#include "listaAsociacion.h"
#include "pelicula.h"
#include "categoria.h"
#include "listaPeliculas.h"
#include "listaCategorias.h"

int idAsociacion = 0;

listaAsociacion::listaAsociacion()
{
    this->cab = NULL;
    this->largo = 0;
}

asociacion* listaAsociacion::getCab()
{
    return this->cab;
}

int listaAsociacion::getLargo()
{
    return this->largo;
}

void listaAsociacion::setCab(asociacion* _cab)
{
    this->cab = _cab;
}

void listaAsociacion::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones miscelaneas***************

bool listaAsociacion::agregarPelicula(int _id, string _nombre)
{
    bool agregado = false;
    pelicula* pel = NULL;
    categoria* cat = NULL;

    if (pel != NULL && cat != NULL) {
        asociacion* nuevo = new asociacion(idAsociacion, _id, _nombre, pel, cat);
        if (cab == NULL) {
            setCab(nuevo);
            setLargo(1);
            agregado = true;
        }
        else if (getLargo() == 1) {
            if (idAsociacion < getCab()->getAsociacion()) {
                nuevo->setSgte(cab);
                nuevo->setAnte(NULL);
                cab->setAnte(nuevo);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if (idAsociacion > getCab()->getAsociacion()) {
                nuevo->setSgte(NULL);
                nuevo->setAnte(cab);
                cab->setSgte(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
        }
        else if (getLargo() > 1) {
            asociacion* aux = getCab();

            while (aux->getSgte() != NULL && !agregado) {
                if (idAsociacion < aux->getAsociacion()) {
                    nuevo->setSgte(cab);
                    nuevo->setAnte(NULL);
                    cab->setAnte(nuevo);
                    setCab(nuevo);
                    setLargo(getLargo() + 1);
                    agregado = true;
                }
                else if (idAsociacion > aux->getAsociacion() && idAsociacion < aux->getAsociacion()) {
                    nuevo->setSgte(aux->getSgte());
                    nuevo->setAnte(aux);
                    aux->getSgte()->setAnte(nuevo);
                    aux->setSgte(nuevo);
                    setLargo(getLargo() + 1);
                    agregado = true;
                }
                else {
                    aux = aux->getSgte();
                }
            }
            if (aux->getSgte() == NULL && idAsociacion > aux->getAsociacion()) {
                aux->setSgte(nuevo);
                nuevo->setAnte(aux);
                nuevo->setSgte(NULL);
                setLargo(getLargo() + 1);
                agregado = true;
            }
        }
        if (agregado) {
            idAsociacion++;
            //listaCategorias::->agregarCantPeliculas(_nombre);
        }
    }
    return agregado;
}

void listaAsociacion::consultarPelCategoria(string _nombre)
{
    asociacion* aux = getCab();
    bool encontrada = false;

    while (aux != NULL) {
        if (aux->getNombreCategoria() == _nombre) {
            cout << "Nombre de la categoria: " << aux->getNombreCategoria() << endl;
            cout << "Cantidad de peliculas asociadas: " << aux->getAsocCategoria()->getCantPeliculasAsoc() << endl;
            cout << "Codigo de la pelicula: " << aux->getAsocPelicula()->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getAsocPelicula()->getNombre() << endl;
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

void listaAsociacion::consultarCatalogCodigoNombre()
{
    asociacion* aux = getCab();
    cout << "Largo de la lista: " << largo << endl;
    cout << endl;

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;
    }
    else {
        while (aux != NULL) {
            cout << "Nombre de la categoria: " << aux->getNombreCategoria() << endl;
            cout << "Codigo de la pelicula: " << aux->getAsocPelicula()->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getAsocPelicula()->getNombre() << endl;
            cout << endl;
        }
        cout << "fin" << endl;
    }
}



