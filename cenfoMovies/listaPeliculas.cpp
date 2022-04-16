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
		setCab(new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias));
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
            largo++;
            agregado = true;
        }
        else if (_id > getCab()->getId()) {
            pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
            nuevo->setSgte(NULL);
            nuevo->setAnte(cab);
            cab->setSgte(nuevo);
            largo++;
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
                largo++;
                agregado = true;
            }
            else if (_id > aux->getId() && _id < aux->getSgte()->getId()) {
                pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
                nuevo->setSgte(aux->getSgte());
                nuevo->setAnte(aux);
                aux->setSgte(nuevo);
                largo++;
                agregado = true;
            }
            else {
                aux = aux->getSgte();
            }
        }
        if (aux->getSgte() == NULL) {
            pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
            aux->setSgte(nuevo);
            nuevo->setAnte(aux);
            nuevo->setSgte(NULL);
            agregado = true;
        }
    }
    return agregado;
}

bool listaPeliculas::retirarPelicula(int)
{
    return false;
}

pelicula* listaPeliculas::consultarPelicula(int)
{
    return nullptr;
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
