#include "model.h"
#include "MODELS/automobile.h"
#include "MODELS/autoibrida.h"
#include "MODELS/bicicletta.h"
#include "VIEWS/window.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;

    model.addCity(new Citta("Prova"));
    model.addVehicle("Prova", new Bicicletta("Bici", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle("Prova", new Automobile("Auto", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));

    std::cout << model.getCity("Prova")->getNome() << " " << model.getCity("Prova")->getVeicoli() << std::endl;

    Window w;
    w.show();

    return a.exec();
}
