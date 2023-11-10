#include "estacionv.h"

Estacionv::Estacionv()
{

}

bool Estacionv::salidaboton(int fila, int columna)
{
   if(fila==this->fila-1 && columna==this->columna){
       return true;
   }
   if(fila==this->fila+1 && columna==this->columna){
       return true;
   }
   return false;
}

bool Estacionv::entradaboton(int fila, int columna)
{

}
