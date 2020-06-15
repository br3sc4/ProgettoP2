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

    model.addCity(new Citta("Milano"));
    model.addVehicle(0, new Bicicletta("Targa-Bici1", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle(0, new Automobile("Targa-Auto1", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));
    model.addCity(new Citta("Roma"));
    model.addVehicle(1, new Bicicletta("Targa-Bici2", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle(1, new Automobile("Targa-Auto2", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));
    model.addVehicle(1, new Automobile("Targa-Auto3", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));

//    try {
//        model.moveVehicle(0, 1, 1);
//    } catch (std::exception e) {
//        std::cerr << e.what() << std::endl;
//    }

//    std::cout << model.getCity(1)->getVeicoli()->back()->targa() << " " << model.getCity(1)->getVeicoli()->back()->chilometraggio() << std::endl;

    Controller controller(&model);
    View w(&controller);
    controller.setView(&w);
    w.show();

    return a.exec();
}
