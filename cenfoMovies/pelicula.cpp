#include "pelicula.h"

pelicula::pelicula()
{
}

pelicula::pelicula(int, string, int, string, int)
{
}

int pelicula::getId()
{
    return 0;
}

string pelicula::getNombre()
{
    return string();
}

int pelicula::getAnno()
{
    return 0;
}

string pelicula::getDirector()
{
    return string();
}

int pelicula::getCantSolicitudes()
{
    return 0;
}

pelicula* pelicula::getSgte()
{
    return nullptr;
}

pelicula* pelicula::getAnt()
{
    return nullptr;
}

void pelicula::setId(int)
{
}

void pelicula::setNombre(string)
{
}

void pelicula::setAnno(int)
{
}

void pelicula::setDirector(string)
{
}

void pelicula::setCantSolicitudes(int)
{
}

void pelicula::setSgte(pelicula*)
{
}

void pelicula::setAnt(pelicula*)
{
}
