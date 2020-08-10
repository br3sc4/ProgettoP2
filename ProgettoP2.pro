#-------------------------------------------------
#
# Progetto Liberty
#
#-------------------------------------------------

QT += core gui widgets

TARGET = ProgettoP2
TEMPLATE = app
CONFIG += c++11
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11
RESOURCES = data.qrc
RC_ICONS = ExtraFiles/Icons/logo_app.ico
ICON = ExtraFiles/Icons/logo_app.icns

SOURCES += Exceptions/emptyexception.cpp \
    Exceptions/notinchargeexception.cpp \
    Exceptions/outofboundsexception.cpp \
    Exceptions/samecityexception.cpp \
    Models/autoibrida.cpp \
    Models/automobile.cpp \
    Models/automobileelettrica.cpp \
    Models/bicicletta.cpp \
    Models/citta.cpp \
    Models/monopattino.cpp \
    Models/moto.cpp \
    Models/motoelettrica.cpp \
    Models/motorecombustione.cpp \
    Models/motoreelettrico.cpp \
    Models/veicolo.cpp \
    Views/Components/backtopbar.cpp \
    Views/Components/basetopbar.cpp \
    Views/Components/statetableitem.cpp \
    Views/Wizard/addcitypage.cpp \
    Views/Wizard/citywizard.cpp \
    Views/Wizard/combustionenginepage.cpp \
    Views/Wizard/electricenginepage.cpp \
    Views/Wizard/selectcitypage.cpp \
    Views/Wizard/selectenginepage.cpp \
    Views/Wizard/vehiclefieldspage.cpp \
    Views/citieslistview.cpp \
    Views/vehicledetailview.cpp \
    Views/vehiclelistview.cpp \
    Views/viewinterface.cpp \
    loadDataBase.cpp \
    controller.cpp \
    view.cpp \
    main.cpp \
    model.cpp

HEADERS += Exceptions/emptyexception.h \
    Exceptions/notinchargeexception.h \
    Exceptions/outofboundsexception.h \
    Exceptions/samecityexception.h \
    Models/array.h \
    Models/autoibrida.h \
    Models/automobile.h \
    Models/automobileelettrica.h \
    Models/bicicletta.h \
    Models/citta.h \
    Models/monopattino.h \
    Models/moto.h \
    Models/motoelettrica.h \
    Models/motorecombustione.h \
    Models/motoreelettrico.h \
    Models/veicolo.h \
    Views/Components/backtopbar.h \
    Views/Components/basetopbar.h \
    Views/Components/statetableitem.h \
    Views/Wizard/addcitypage.h \
    Views/Wizard/citywizard.h \
    Views/Wizard/combustionenginepage.h \
    Views/Wizard/electricenginepage.h \
    Views/Wizard/selectcitypage.h \
    Views/Wizard/selectenginepage.h \
    Views/Wizard/vehiclefieldspage.h \
    Views/citieslistview.h \
    Views/vehicledetailview.h \
    Views/vehiclelistview.h \
    Views/viewinterface.h \
    controller.h \
    view.h \
    model.h
