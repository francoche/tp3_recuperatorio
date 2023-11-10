#ifndef ESTACIONH_H
#define ESTACIONH_H

#include "Boton.h"

class Estacionh : public Boton
{
public:
    Estacionh();
    bool salidaboton(int fila,int columna);
    bool entradaboton(int fila,int columna);
};

#endif // ESTACIONH_H
