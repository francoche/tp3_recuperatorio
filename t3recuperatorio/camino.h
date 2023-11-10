#ifndef CAMINO_H
#define CAMINO_H

#include "Boton.h"

class Camino : public Boton
{
public:
    Camino();
    bool salidaboton(int fila,int columna);
    bool entradaboton(int fila,int columna);
};

#endif // CAMINO_H
