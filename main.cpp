#include "model.h"
#include "MODELS/automobile.h"
#include "MODELS/autoibrida.h"
#include "MODELS/bicicletta.h"
#include "CONTROLLERS/controller.h"
#include "VIEWS/view.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;

    model.addCity(new Citta("Prova"));
    model.addVehicle("Prova", new Bicicletta("Bici", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle("Prova", new Automobile("Auto", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));
    model.addCity(new Citta("Prova2"));
    model.addVehicle("Prova2", new Bicicletta("Bici", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle("Prova2", new Automobile("Auto", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));

    Controller controller(&model);
    View w(&controller);
    controller.setView(&w);
    w.show();

    return a.exec();
}
