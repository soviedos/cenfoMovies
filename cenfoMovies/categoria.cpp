#include "categoria.h"

categoria::categoria()
{
    this->nombre = "";
    this->cantPeliculasAsoc = 0;
    this->sgte = NULL;
}

categoria::categoria(string _nombre, int _asoc)
{
    this->nombre = _nombre;
    this->cantPeliculasAsoc = _asoc;
    this->sgte = NULL;
}

string categoria::getNombre()
{
    return this->nombre;
}

int categoria::getCantPeliculasAsoc()
{
    return this->cantPeliculasAsoc;
}

categoria* categoria::getSgte()
{
    return this->sgte;
}


void categoria::setNombre(string _nombre)
{
    this->nombre = _nombre;
}

void categoria::setCantPeliculasAsoc(int _cant)
{
    this->cantPeliculasAsoc = _cant;
}

void categoria::setSgte(categoria* _sgte)
{
    this->sgte = _sgte;
}

