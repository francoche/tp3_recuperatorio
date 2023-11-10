#ifndef JUEGO_H
#define JUEGO_H
#include "Boton.h"
#include "estacionh.h"
#include "estacionm.h"
#include "estacionn.h"
#include "estacionv.h"
#include "camino.h"
#include<cstdlib>
#include<ctime>
#include <iostream>

class Juego
{
private:
    Boton* **matrizjuego;
    int filas;
    int columnas;
    int ultimofila=false;
    int ultimocolumna=false;

public:
    Juego();
    void setfilas(int a);
    void setcolumnas(int a);
    void setultimofila(int a);
    void setultimocolumna(int a);
    void crearmatriz();
    void crearcamino(int fila,int columna);
    void borrarmatriz();
    void crearestaciones(int &a,int &b,int &c,int &d);
    void crearproximaestacion();
    bool esadshacente(int fila,int columna);
    bool chehearestacionallado(int fila,int columna);
    bool esadshacenteultimo(int fila,int columna);
    bool clikalladodelcamino(int fila,int columna);
    void getmatrtriz(Boton*** a);
    int devolvertipo(int fila,int columna);


};

#endif // JUEGO_H
