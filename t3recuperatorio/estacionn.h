#ifndef ESTACIONN_H
#define ESTACIONN_H

#include "Boton.h"

class Estacionn : public Boton
{
public:
    Estacionn();
    bool salidaboton(int fila,int columna);
    bool entradaboton(int fila,int columna);
};

#endif // ESTACIONN_H
