#include "estacionh.h"

Estacionh::Estacionh()
{

}

bool Estacionh::salidaboton(int fila, int columna)
{
    if(fila==this->fila && columna==this->columna-1){
        return true;
    }
    if(fila==this->fila && columna==this->columna+1){
        return true;
    }
    return false;
}

bool Estacionh::entradaboton(int fila, int columna)
{

}
