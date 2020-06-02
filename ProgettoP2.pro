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

SOURCES += EXCEPTIONS/emptyexception.cpp \
    EXCEPTIONS/notinchargeexception.cpp \
    EXCEPTIONS/outofboundsexception.cpp \
    MODELS/autoibrida.cpp \
    MODELS/automobile.cpp \
    MODELS/automobileelettrica.cpp \
    MODELS/bicicletta.cpp \
    MODELS/monopattino.cpp \
    MODELS/moto.cpp \
    MODELS/motoelettrica.cpp \
    MODELS/motorecombustione.cpp \
    MODELS/motoreelettrico.cpp \
    MODELS/veicolo.cpp \
    VIEWS/baseview.cpp \
    VIEWS/vehicledetailview.cpp \
    VIEWS/vehiclelistview.cpp \
    VIEWS/window.cpp \
    main.cpp

HEADERS += EXCEPTIONS/emptyexception.h \
    EXCEPTIONS/notinchargeexception.h \
    EXCEPTIONS/outofboundsexception.h \
    MODELS/array.h \
    MODELS/autoibrida.h \
    MODELS/automobile.h \
    MODELS/automobileelettrica.h \
    MODELS/bicicletta.h \
    MODELS/monopattino.h \
    MODELS/moto.h \
    MODELS/motoelettrica.h \
    MODELS/motorecombustione.h \
    MODELS/motoreelettrico.h \
    MODELS/veicolo.h \
    VIEWS/baseview.h \
    VIEWS/vehicledetailview.h \
    VIEWS/vehiclelistview.h \
    VIEWS/window.h
