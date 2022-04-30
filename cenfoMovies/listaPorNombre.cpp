#include <iostream>
#include <stdlib.h>
#include "listaPorNombre.h"
#include "pelicula.h"

listaPorNombre::listaPorNombre()
{
    this->cab = NULL;
    this->largo = 0;
}

nombre* listaPorNombre::getCab()
{
    return this->cab;
}

int listaPorNombre::getLargo()
{
    return this->largo;
}

void listaPorNombre::setCab(nombre* _cab)
{
    this->cab = _cab;
}

void listaPorNombre::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones***************

void listaPorNombre::agregarPeliculaPorNombre(pelicula* _aux)
{
    bool agregado = false;
    nombre* nuevo = new nombre(_aux);

    if (cab == NULL) {
        setCab(nuevo);
        setLargo(1);
        agregado = true;
    }
    else if (getLargo() == 1) {
        if (_aux->getNombre() < getCab()->getDato()->getNombre()) {
            nuevo->setSgte(cab);
            nuevo->setAnte(NULL);
            cab->setAnte(nuevo);
            setCab(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
        else if (_aux->getNombre() > getCab()->getDato()->getNombre()) {
            nuevo->setSgte(NULL);
            nuevo->setAnte(cab);
            cab->setSgte(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    else if (getLargo() > 1) {
        nombre* aux = getCab();

        while (aux->getSgte() != NULL && !agregado) {
            if (_aux->getNombre() < aux->getDato()->getNombre()) {
                nuevo->setSgte(cab);
                nuevo->setAnte(NULL);
                cab->setAnte(nuevo);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if (_aux->getNombre() > aux->getDato()->getNombre() && _aux->getNombre() < aux->getSgte()->getDato()->getNombre()) {
                nuevo->setSgte(aux->getSgte());
                nuevo->setAnte(aux);
                aux->setSgte(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else {
                aux = aux->getSgte();
            }
        }
        if (aux->getSgte() == NULL && _aux->getNombre() > aux->getDato()->getNombre()) {
            aux->setSgte(nuevo);
            nuevo->setAnte(aux);
            nuevo->setSgte(NULL);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
}

void listaPorNombre::listarCatalogoPorNombre()
{
    nombre* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            cout << "Identificacion: " << aux->getDato()->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getDato()->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getDato()->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDato()->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getDato()->getCantSolicitudes() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

void listaPorNombre::retirarPelicula(int _id)
{
    nombre* aux = getCab();
    nombre* sgte = NULL;

    while (aux != NULL) {
        if (aux->getDato()->getId() == _id) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() != NULL) {
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() == NULL) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
        }
        else {
            aux = aux->getSgte();
        }
    }
}

void listaPorNombre::eliminarPorLimite(int _limite)
{
    bool borrada = false;
    nombre* aux = getCab();
    nombre* sgte = NULL;

    while (aux != NULL) {
        if (aux->getDato()->getNombre() == "") {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() != NULL) {
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() == NULL) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
        }
        /*
        borrada = false;
        if (aux->getDato()->getAnio() < _limite) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                aux = getCab();
            }
            if (aux->getSgte() != NULL && aux != cab && !borrada) {
                sgte = aux->getSgte();
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                borrada = true;
                aux = sgte;
            }
            if (aux->getSgte() == NULL && aux != cab && !borrada) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                aux = NULL;
            }
        }
        */
        else {
            aux = aux->getSgte();
        }
    }
}


