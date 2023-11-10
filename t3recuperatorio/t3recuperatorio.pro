QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boton.cpp \
    camino.cpp \
    cronometro.cpp \
    estacionh.cpp \
    estacionm.cpp \
    estacionn.cpp \
    estacionv.cpp \
    juego.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    boton.h \
    camino.h \
    cronometro.h \
    estacionh.h \
    estacionm.h \
    estacionn.h \
    estacionv.h \
    juego.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
