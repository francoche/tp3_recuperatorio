#ifndef BOTON_H
#define BOTON_H


class Boton
{
protected:
    int fila;
    int columna;
    int tipo;
    bool estacion=false;
    bool camino=false;
    bool ocupado=false;
public:
    Boton();
    void setfila(int a);
    void setcolumna(int a);
    void settipo(int a);
    void setestacion(bool a);
    void setcamino(bool a);
    void setocupado(bool a);
    int getfila();
    int getcolumna();
    int gettipo();
    bool getestacion();
    bool getcamino();
    bool getocupado();
    bool virtual salidaboton(int fila,int columna)=0;
    bool virtual entradaboton(int fila,int columna)=0;
};

#endif // BOTON_H
