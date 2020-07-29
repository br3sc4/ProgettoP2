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
RESOURCES =

SOURCES += EXCEPTIONS/emptyexception.cpp \
    CONTROLLERS/controller.cpp \
    EXCEPTIONS/notinchargeexception.cpp \
    EXCEPTIONS/outofboundsexception.cpp \
    EXCEPTIONS/samecityexception.cpp \
    MODELS/autoibrida.cpp \
    MODELS/automobile.cpp \
    MODELS/automobileelettrica.cpp \
    MODELS/bicicletta.cpp \
    MODELS/citta.cpp \
    MODELS/monopattino.cpp \
    MODELS/moto.cpp \
    MODELS/motoelettrica.cpp \
    MODELS/motorecombustione.cpp \
    MODELS/motoreelettrico.cpp \
    MODELS/veicolo.cpp \
    VIEWS/Wizard/addcitypage.cpp \
    VIEWS/Wizard/citywizard.cpp \
    VIEWS/Wizard/combustionenginepage.cpp \
    VIEWS/Wizard/electricenginepage.cpp \
    VIEWS/Wizard/selectcitypage.cpp \
    VIEWS/Wizard/selectenginepage.cpp \
    VIEWS/Wizard/vehiclefieldspage.cpp \
    VIEWS/baseabstractview.cpp \
    VIEWS/basebackabstractview.cpp \
    VIEWS/citieslistview.cpp \
    VIEWS/vehicledetailview.cpp \
    VIEWS/vehiclelistview.cpp \
    VIEWS/view.cpp \
    loadDataBase.cpp \
    main.cpp \
    model.cpp

HEADERS += EXCEPTIONS/emptyexception.h \
    CONTROLLERS/controller.h \
    EXCEPTIONS/notinchargeexception.h \
    EXCEPTIONS/outofboundsexception.h \
    EXCEPTIONS/samecityexception.h \
    MODELS/array.h \
    MODELS/autoibrida.h \
    MODELS/automobile.h \
    MODELS/automobileelettrica.h \
    MODELS/bicicletta.h \
    MODELS/citta.h \
    MODELS/monopattino.h \
    MODELS/moto.h \
    MODELS/motoelettrica.h \
    MODELS/motorecombustione.h \
    MODELS/motoreelettrico.h \
    MODELS/veicolo.h \
    VIEWS/Wizard/addcitypage.h \
    VIEWS/Wizard/citywizard.h \
    VIEWS/Wizard/combustionenginepage.h \
    VIEWS/Wizard/electricenginepage.h \
    VIEWS/Wizard/selectcitypage.h \
    VIEWS/Wizard/selectenginepage.h \
    VIEWS/Wizard/vehiclefieldspage.h \
    VIEWS/baseabstractview.h \
    VIEWS/basebackabstractview.h \
    VIEWS/citieslistview.h \
    VIEWS/vehicledetailview.h \
    VIEWS/vehiclelistview.h \
    VIEWS/view.h \
    model.h
