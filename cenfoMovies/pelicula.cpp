#include "pelicula.h"

pelicula::pelicula()
{
}

pelicula::pelicula(int _id, string _nombre, int _anio, string _director, int _cantSolicitudes, int _cantCategorias)
{
    this->id = _id;
    this->nombre = _nombre;
    this->anio = _anio;
    this->director = _director;
    this->cantSolicitudes = _cantSolicitudes;
    this->cantCategorias = _cantCategorias;
    this->sgte;
    this->ant;
}

int pelicula::getId()
{
    return this->id;
}

string pelicula::getNombre()
{
    return this->nombre;
}

int pelicula::getAnio()
{
    return this->anio;
}

string pelicula::getDirector()
{
    return this->director;
}

int pelicula::getCantSolicitudes()
{
    return this->cantSolicitudes;
}

int pelicula::getCantCategorias()
{
    return this->cantCategorias;
}

pelicula* pelicula::getSgte()
{
    return this->sgte;
}

pelicula* pelicula::getAnt()
{
    return this->ant;
}

void pelicula::setId(int _id)
{
    this->id = _id;
}

void pelicula::setNombre(string _nombre)
{
    this->nombre = _nombre;
}

void pelicula::setAnio(int _anio)
{
    this->anio = _anio;
}

void pelicula::setDirector(string _director)
{
    this->director = _director;
}

void pelicula::setCantSolicitudes(int _cantSolicitudes)
{
    this->cantSolicitudes = _cantSolicitudes;
}

void pelicula::setCantCategorias(int _cantCategorias)
{
    this->cantCategorias = _cantCategorias;
}

void pelicula::setSgte(pelicula* _sgte)
{
    this->sgte = _sgte;
}

void pelicula::setAnt(pelicula* _ante)
{
    this->ant = _ante;
}