#include "listaPeliculas.h"

listaPeliculas::listaPeliculas()
{
    this->cab = NULL;
    this->largo = 0;
}

pelicula* listaPeliculas::getCab()
{
    return this->cab;
}

int listaPeliculas::getLargo()
{
    return this->largo;
}

void listaPeliculas::setCab(pelicula* _cab)
{
    this->cab = _cab;
}

void listaPeliculas::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones del TAD***************

bool listaPeliculas::agregarPelicula(int _id, string _nombre, int _anio, string _director, int _cantSolicitudes, int _cantCategorias)
{
    bool agregado = false;

	if (cab == NULL) {
        pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
		setCab(nuevo);
		setLargo(1);
		agregado = true;
	}
	else if (getLargo() == 1){
        if (_id < getCab()->getId()) {
            pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
            nuevo->setSgte(cab);
            nuevo->setAnte(NULL);
            cab->setAnte(nuevo);
            setCab(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
        else if (_id > getCab()->getId()) {
            pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
            nuevo->setSgte(NULL);
            nuevo->setAnte(cab);
            cab->setSgte(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    else if (getLargo() > 1) {
        pelicula* aux = getCab();

        while (aux->getSgte() != NULL && !agregado) {
            if (_id < aux->getId()) {
                pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
                nuevo->setSgte(cab);
                nuevo->setAnte(NULL);
                cab->setAnte(nuevo);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if (_id > aux->getId() && _id < aux->getSgte()->getId()) {
                pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
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
        if (aux->getSgte() == NULL && _id > aux->getId()) {
            pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
            aux->setSgte(nuevo);
            nuevo->setAnte(aux);
            nuevo->setSgte(NULL);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    return agregado;
}

bool listaPeliculas::retirarPelicula(int _id)
{
    bool eliminada = false;
    pelicula* aux = getCab();
    pelicula* sgte = NULL;

    while (aux != NULL || !eliminada) {
        if (aux->getId() == _id) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() != NULL) {
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() == NULL) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
        }
        else {
            aux = aux->getSgte();
        }
    }
    return eliminada;
}

void listaPeliculas::consultarPelicula(int _id)
{
    pelicula* aux = getCab();
    bool encontrada = false;

    while (aux != NULL) {
        if (aux->getId() == _id) {
            cout << "Identificacion: " << aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getCantSolicitudes() << endl;
            cout << endl;
            encontrada = true;
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
    if (!encontrada) {
        cout << "No se pudo encontrar la pelicula en el catalogo" << endl;
    }
}

bool listaPeliculas::modificarPelicula(int)
{
    return false;
}

void listaPeliculas::listarCatalogoPorCodigo()
{
    pelicula* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            cout << "Identificacion: " <<aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getCantSolicitudes() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

listaPeliculas* listaPeliculas::listarCatalogoPorNombre()
{
    return nullptr;
}

listaPeliculas* listaPeliculas::listarCatalogoPorHilera(int)
{
    return nullptr;
}

listaPeliculas* listaPeliculas::listarCatalogoPorRango(int)
{
    return nullptr;
}

listaPeliculas* listaPeliculas::listarCatalogoPorLimite(int)
{
    return nullptr;
}

listaPeliculas* listaPeliculas::listarPeliculasSinCategoria()
{
    return nullptr;
}

bool listaPeliculas::eliminarPeliculasPorLimite(int)
{
    return false;
}
