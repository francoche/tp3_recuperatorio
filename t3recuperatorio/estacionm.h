#ifndef ESTACIONM_H
#define ESTACIONM_H

#include "Boton.h"

class Estacionm : public Boton
{
public:
    Estacionm();
    bool salidaboton(int fila,int columna);
    bool entradaboton(int fila,int columna);
};

#endif // ESTACIONM_H
