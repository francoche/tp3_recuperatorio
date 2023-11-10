#ifndef ESTACIONV_H
#define ESTACIONV_H

#include "Boton.h"

class Estacionv : public Boton
{
public:
    Estacionv();
    bool salidaboton(int fila,int columna);
    bool entradaboton(int fila,int columna);
};

#endif // ESTACIONV_H
