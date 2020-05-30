QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Exceptions/emptyexception.cpp \
    Exceptions/outofboundsexception.cpp \
    Model/autoibrida.cpp \
    Model/automobile.cpp \
    Model/automobileelettrica.cpp \
    Model/bicicletta.cpp \
    Model/monopattino.cpp \
    Model/moto.cpp \
    Model/motoelettrica.cpp \
    Model/motorecombustione.cpp \
    Model/motoreelettrico.cpp \
    Model/veicolo.cpp \
    Views/baseview.cpp \
    Views/vehicledetailview.cpp \
    Views/vehiclelistview.cpp \
    Views/window.cpp \
    main.cpp

HEADERS += \
    Exceptions/emptyexception.h \
    Exceptions/outofboundsexception.h \
    Model/array.h \
    Model/autoibrida.h \
    Model/automobile.h \
    Model/automobileelettrica.h \
    Model/bicicletta.h \
    Model/monopattino.h \
    Model/moto.h \
    Model/motoelettrica.h \
    Model/motorecombustione.h \
    Model/motoreelettrico.h \
    Model/veicolo.h \
    Views/baseview.h \
    Views/vehicledetailview.h \
    Views/vehiclelistview.h \
    Views/window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
