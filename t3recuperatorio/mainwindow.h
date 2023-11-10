#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include<QTimer>
#include <QMessageBox>
#include "cronometro.h"
#include "juego.h"
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearjuego();
    void reset();

private slots:
    void on_pushButton_clicked();
    void aumentartiempo();
    void on_pushButton_2_clicked();
    void graficador();

private:
    Ui::MainWindow *ui;
    QPushButton *** botones;
    QTimer timer;
    Cronometro cronometro;
    Boton ***Auxmatriz;
    Juego juego;
    int filas;
    int columnas;
};
#endif // MAINWINDOW_H
