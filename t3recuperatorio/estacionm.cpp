#include "estacionm.h"

Estacionm::Estacionm()
{

}

bool Estacionm::salidaboton(int fila, int columna)
{
    if(fila==this->fila+1 && columna==this->columna){
        return true;
    }
    if(fila==this->fila-1 && columna==this->columna){
        return true;
    }
    if(fila==this->fila && columna==this->columna+1){
        return true;
    }
    if(fila==this->fila && columna==this->columna-1){
        return true;
    }
    return false;

}

bool Estacionm::entradaboton(int fila, int columna)
{

}
