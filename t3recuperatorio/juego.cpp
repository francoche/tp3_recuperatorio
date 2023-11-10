#include "juego.h"

Juego::Juego()
{

}

void Juego::setfilas(int a)
{
    this->filas=a;
}

void Juego::setcolumnas(int a)
{
    this->columnas=a;
}

void Juego::setultimofila(int a)
{
    this->ultimofila=a;
}

void Juego::setultimocolumna(int a)
{
    this->ultimocolumna=a;
}



void Juego::crearmatriz()
{
    this->matrizjuego = new Boton**[this->filas];
    for (int i = 0; i< filas; i++) {
        this->matrizjuego[i] = new Boton*[this->columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        Boton*aux=new Camino();
        this->matrizjuego[i][j]=aux;
        this->matrizjuego[i][j]->setocupado(false);
        //this->matrizjuego[i][j]->setcamino(true);
    }
    }



}

void Juego::crearcamino(int fila, int columna)
{
    Boton*aux=new Camino();
    matrizjuego[fila][columna]=aux;
    matrizjuego[fila][columna]->setcamino(true);
    matrizjuego[fila][columna]->setocupado(true);
}

void Juego::borrarmatriz()
{
   for (int i = 0; i< filas; i++) {
       delete [] matrizjuego[i];
   }
   delete [] matrizjuego;
}

void Juego::crearestaciones(int &a,int &b,int &c,int &d)
{
    srand(time(NULL));
    int f1,c1,f2,c2,t,t2;
    t=1+rand()%4;
    switch (t) {
    case 1:{f1=rand()%filas;
            c1=rand()%columnas;
            Boton*aux=new Estacionn();
            matrizjuego[f1][c1]=aux;
            break;}
    case 2:{f1=rand()%filas;
            c1=rand()%columnas;
            Boton*aux=new Estacionm();
            matrizjuego[f1][c1]=aux;
            break;}
    case 3:{f1=rand()%filas;
            c1=1+rand()%(columnas-2);
            Boton*aux=new Estacionh();
            matrizjuego[f1][c1]=aux;
            break;}
    case 4:{f1=1+rand()%(filas-2);
            c1=rand()%columnas;
            Boton*aux=new Estacionv();
            matrizjuego[f1][c1]=aux;
            break;}

    }
    matrizjuego[f1][c1]->setfila(f1);
    matrizjuego[f1][c1]->setcolumna(c1);
    matrizjuego[f1][c1]->settipo(t);
    matrizjuego[f1][c1]->setestacion(true);
    matrizjuego[f1][c1]->setocupado(true);
    std::cout<<"fila1 "<<matrizjuego[f1][c1]->getfila()<<std::endl;
    std::cout<<"columna1 "<<matrizjuego[f1][c1]->getcolumna()<<std::endl;
    std::cout<<"tipo 1 "<<matrizjuego[f1][c1]->gettipo()<<std::endl;
    std::cout<<"camino1 "<<matrizjuego[f1][c1]->getcamino()<<std::endl;
    std::cout<<"estacion1 "<<matrizjuego[f1][c1]->getestacion()<<std::endl;
    std::cout<<"ocupado1 "<<matrizjuego[f1][c1]->getocupado()<<std::endl;
    setultimocolumna(c1);
    setultimofila(f1);
    a=f1;
    b=c1;
    t2=1+rand()%4;
    switch (t2) {
    case 1:{f2=rand()%filas;
            c2=rand()%columnas;
            break;}
    case 2:{f2=rand()%filas;
            c2=rand()%columnas;
            break;}
    case 3:{f2=rand()%filas;
            c2=1+rand()%(columnas-2);
            break;}
    case 4:{f2=1+rand()%(filas-2);
            c2=rand()%columnas;
            break;}

    }
    while(this->matrizjuego[f2][c2]->getocupado() || esadshacente(f2,c2)){
        std::cout<<"esadshacente u ocupado"<<std::endl;
        switch (t2) {
        case 1:{f2=rand()%filas;
                c2=rand()%columnas;
                break;}
        case 2:{f2=rand()%filas;
                c2=rand()%columnas;
                break;}
        case 3:{f2=rand()%filas;
                c2=1+rand()%(columnas-2);
                break;}
        case 4:{f2=1+rand()%(filas-2);
                c2=rand()%columnas;
                break;}

        }
    }
    switch (t2) {
    case 1:{Boton*aux=new Estacionn();
            matrizjuego[f2][c2]=aux;
            break;}
    case 2:{Boton*aux=new Estacionm();
           matrizjuego[f2][c2]=aux;
            break;}
    case 3:{Boton*aux=new Estacionh();
            matrizjuego[f2][c2]=aux;
            break;}
    case 4:{Boton*aux=new Estacionv();
            matrizjuego[f2][c2]=aux;
            break;}

    }
    c=f2;
    d=c2;
    matrizjuego[f2][c2]->setfila(f2);
    matrizjuego[f2][c2]->setcolumna(c2);
    matrizjuego[f2][c2]->settipo(t2);
    matrizjuego[f2][c2]->setestacion(true);
    std::cout<<"fila2 "<<matrizjuego[f2][c2]->getfila()<<std::endl;
    std::cout<<"columna2 "<<matrizjuego[f2][c2]->getcolumna()<<std::endl;
    std::cout<<"tipo 2 "<<matrizjuego[f2][c2]->gettipo()<<std::endl;
    std::cout<<"estacion2 "<<matrizjuego[f2][c2]->getestacion()<<std::endl;


}

void Juego::crearproximaestacion()
{
    int cont=0;
    int cont2=0;
    srand(time(NULL));
    int f1,c1,t;
    t=1+rand()%4;
    switch (t) {
    case 1:{f1=rand()%filas;
            c1=rand()%columnas;
            matrizjuego[f1][c1]=new Estacionn();
            break;}
    case 2:{f1=rand()%filas;
            c1=rand()%columnas;
            matrizjuego[f1][c1]=new Estacionm();
            break;}
    case 3:{f1=rand()%filas;
            c1=1+rand()%(columnas-2);
            matrizjuego[f1][c1]=new Estacionh();
            break;}
    case 4:{f1=1+rand()%(filas-2);
            c1=rand()%columnas;
            matrizjuego[f1][c1]=new Estacionv();
            break;}

    }
    while (matrizjuego[f1][c1]->getocupado() || esadshacente(f1,c1)) {

        switch (t) {
        case 1:{f1=rand()%filas;
                c1=rand()%columnas;
                break;}
        case 2:{f1=rand()%filas;
                c1=rand()%columnas;
                break;}
        case 3:{f1=rand()%filas;
                c1=1+rand()%(columnas-2);
                break;}
        case 4:{f1=1+rand()%(filas-2);
                c1=rand()%columnas;
                break;}

        }
        cont++;
        if(cont>30){
            cont=0;
            cont2++;

            t=1+rand()%4;
            if(cont2>30){

                return;
            }
        }
}
        matrizjuego[f1][c1]->setfila(f1);
        matrizjuego[f1][c1]->setcolumna(c1);
        matrizjuego[f1][c1]->settipo(t);
        //matrizjuego[f1][c1]->setestacion(true);

}

bool Juego::esadshacente(int fila, int columna)
{
   std::cout<<"hola"<<std::endl;
  if(fila-1>=0 && this->matrizjuego[fila-1][columna]->getocupado()){
       std::cout<<"hola1"<<std::endl;
      return true;
  }
  if(fila+1<=(this->filas-1) && this->matrizjuego[fila+1][columna]->getocupado()){
       std::cout<<"hola2"<<std::endl;
      return true;
  }
  if(columna-1>=0 && this->matrizjuego[fila][columna-1]->getocupado()){
       std::cout<<"hola3"<<std::endl;
      return true;
  }
  if(columna+1<(this->columnas-1) && this->matrizjuego[fila][columna+1]->getocupado()){
       std::cout<<"hola4"<<std::endl;
      return true;
  }
  return false;
}

bool Juego::chehearestacionallado(int fila, int columna)
{

   if(fila-1>=0 && this->matrizjuego[fila-1][columna]->getocupado()){

       return matrizjuego[fila-1][columna]->salidaboton(fila,columna);
   }
   if(fila+1<=(this->filas-1) && this->matrizjuego[fila+1][columna]->getocupado()){

       return matrizjuego[fila+1][columna]->salidaboton(fila,columna);;
   }
   if(columna-1>=0 && this->matrizjuego[fila][columna-1]->getocupado()){

       return matrizjuego[fila][columna-1]->salidaboton(fila,columna);
   }
   if(columna+1<(this->columnas-1) && this->matrizjuego[fila][columna+1]->getocupado()){

       return matrizjuego[fila][columna+1]->salidaboton(fila,columna);
   }

   return false;
}



bool Juego::esadshacenteultimo(int fila, int columna)
{
    std::cout<<"filaultimo "<<this->ultimofila<<std::endl;
    std::cout<<"filaultimo "<<this->ultimocolumna<<std::endl;
    if(this->ultimofila==fila-1 && this->ultimocolumna==columna){
        return true;
    }
    if(this->ultimofila==fila+1 && this->ultimocolumna==columna){
        return true;
    }
    if(this->ultimofila==fila && this->ultimocolumna==columna-1){
        return true;
    }
    if(this->ultimofila==fila && this->ultimocolumna==columna+1){
        return true;
    }
    return false;
}

bool Juego::clikalladodelcamino(int fila, int columna)
{

   if(fila-1>=0 && this->matrizjuego[fila-1][columna]->getcamino()){

       return true;
   }
   if(fila+1<=(this->filas-1) && this->matrizjuego[fila+1][columna]->getcamino()){

       return true;
   }
   if(columna-1>=0 && this->matrizjuego[fila][columna-1]->getcamino()){

       return true;
   }
   if(columna+1<(this->columnas-1) && this->matrizjuego[fila][columna+1]->getcamino()){

       return true;
   }
   return false;
}

void Juego::getmatrtriz(Boton ***a)
{
    a = new Boton* *[this->filas];
    for (int i = 0; i< filas; i++) {
        a[i] = new Boton*[this->columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        a[i][j]=this->matrizjuego[i][j];
    }
    }
}

int Juego::devolvertipo(int fila, int columna)
{

   return matrizjuego[fila][columna]->gettipo();


}






