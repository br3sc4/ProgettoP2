#-------------------------------------------------
#
# Progetto Liberty
#
#-------------------------------------------------

QT += core gui
QT += widgets

TARGET = ProgettoP2
TEMPLATE = app
CONFIG += c++11
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = resource.qrc

SOURCES += EXCEPTIONS/implementation/emptyexception.cpp \
    EXCEPTIONS/implementation/outofboundsexception.cpp \
    MODELS/implementation/autoibrida.cpp \
    MODELS/implementation/automobile.cpp \
    MODELS/implementation/automobileelettrica.cpp \
    MODELS/implementation/bicicletta.cpp \
    MODELS/implementation/monopattino.cpp \
    MODELS/implementation/moto.cpp \
    MODELS/implementation/motoelettrica.cpp \
    MODELS/implementation/motorecombustione.cpp \
    MODELS/implementation/motoreelettrico.cpp \
    MODELS/implementation/veicolo.cpp \
    VIEWS/implementation/baseview.cpp \
    VIEWS/implementation/vehicledetailview.cpp \
    VIEWS/implementation/vehiclelistview.cpp \
    VIEWS/implementation/window.cpp \
    main.cpp

HEADERS += EXCEPTIONS/header/emptyexception.h \
    EXCEPTIONS/header/outofboundsexception.h \
    MODELS/header/array.h \
    MODELS/header/autoibrida.h \
    MODELS/header/automobile.h \
    MODELS/header/automobileelettrica.h \
    MODELS/header/bicicletta.h \
    MODELS/header/monopattino.h \
    MODELS/header/moto.h \
    MODELS/header/motoelettrica.h \
    MODELS/header/motorecombustione.h \
    MODELS/header/motoreelettrico.h \
    MODELS/header/veicolo.h \
    VIEWS/header/baseview.h \
    VIEWS/header/vehicledetailview.h \
    VIEWS/header/vehiclelistview.h \
    VIEWS/header/window.h
