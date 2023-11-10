#include "Boton.h"

Boton::Boton()
{

}

void Boton::setfila(int a)
{
    this->fila=a;
}

void Boton::setcolumna(int a)
{
    this->columna=a;
}

void Boton::settipo(int a)
{
    this->tipo=a;
}

void Boton::setestacion(bool a)
{
    this->estacion=a;
}

void Boton::setcamino(bool a)
{
    this->camino=a;
}

void Boton::setocupado(bool a)
{
    this->ocupado=a;
}

int Boton::getfila()
{
    return this->fila;
}

int Boton::getcolumna()
{
    return this->columna;
}

int Boton::gettipo()
{
    return this->tipo;
}

bool Boton::getestacion()
{
    return this->estacion;
}

bool Boton::getcamino()
{
    return this->camino;
}

bool Boton::getocupado()
{
    return this->ocupado;
}
