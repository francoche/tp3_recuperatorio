#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(aumentartiempo()));
    this->ui->pushButton_2->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearjuego()
{
    //int cant = 10;
    this->filas=this->ui->spinBox->value();
    this->columnas=this->ui->spinBox_2->value();
    this->botones = new QPushButton**[filas];
    for (int i = 0; i< filas; i++) {
        this->botones[i] = new QPushButton*[columnas];
        for(int j =0; j < columnas; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");
            connect(botones[i][j], SIGNAL(clicked()), this, SLOT(graficador()));

            this->ui->gridLayout->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                //this->botones[i][j]->setText(".");
            } );
        }
    }
    juego.setfilas(filas);
    juego.setcolumnas(columnas);
}


void MainWindow::on_pushButton_clicked()
{
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(true);
    int a,b,c,d;
    crearjuego();
    juego.crearmatriz();
    juego.crearestaciones(a,b,c,d);
    //this->timer.start(1000);
    //juego.getmatrtriz(Auxmatriz);
    int aux=juego.devolvertipo(a,b);
    int aux2=juego.devolvertipo(c,d);
    //std::cout<<aux<<std::endl;
    botones[a][b]->setEnabled(false);
    botones[a][b]->setText("estacion"+QString::number(aux));
    botones[c][d]->setText("estacion"+QString::number(aux2));
}

void MainWindow::reset()
{
    this->ui->lcdNumber->display(cronometro.get_tiempo());
}

void MainWindow::aumentartiempo()
{
    if(this->cronometro.get_tiempo()<10){
        this->cronometro.setaumentar();
        reset();
    }else{

        QMessageBox::information(this,"perdiste","perdiste");
        on_pushButton_2_clicked();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->pushButton->setEnabled(true);
    this->ui->pushButton_2->setEnabled(false);
    this->timer.stop();
    this->cronometro.setreset();
    reset();
    juego.borrarmatriz();
}
void MainWindow::graficador()
{
    QPushButton * Aux = (QPushButton *)sender();
    int auxfila=0;
    int auxcolumna=0;
    for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    if (botones[i][j] == Aux) {
                        auxfila = i;
                        auxcolumna = j;
                        break;
                    }
                }
            }
    std::cout<<"auxfila "<<auxfila<<std::endl;
    std::cout<<"auxcoluma "<<auxcolumna<<std::endl;
    if(juego.esadshacenteultimo(auxfila,auxcolumna) && juego.chehearestacionallado(auxfila,auxcolumna)){
      botones[auxfila][auxcolumna]->setText(".");
      juego.setultimofila(auxfila);
      juego.setultimocolumna(auxcolumna);
      juego.crearcamino(auxfila,auxcolumna);
}else if(juego.esadshacenteultimo(auxfila,auxcolumna) && !juego.esadshacente(auxfila,auxcolumna)){
      botones[auxfila][auxcolumna]->setText(".");
      juego.setultimofila(auxfila);
      juego.setultimocolumna(auxcolumna);
      juego.crearcamino(auxfila,auxcolumna);
    }
}

