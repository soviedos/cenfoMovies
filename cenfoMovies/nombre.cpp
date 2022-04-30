#include "nombre.h"

nombre::nombre()
{
	this->dato = NULL;
}

nombre::nombre(pelicula* _dato)
{
	this->dato = _dato;
}

pelicula* nombre::getDato()
{
	return this->dato;
}

nombre* nombre::getSgte()
{
	return this->sgte;
}

nombre* nombre::getAnte()
{
	return this->ante;
}

void nombre::setNombre(pelicula* _dato)
{
	this->dato = _dato;
}

void nombre::setSgte(nombre* _sgte)
{
	this->sgte = _sgte;
}

void nombre::setAnte(nombre* _ante)
{
	this->ante = _ante;
}
