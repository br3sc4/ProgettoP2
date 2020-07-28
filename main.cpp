#include "model.h"
#include "MODELS/automobile.h"
#include "MODELS/autoibrida.h"
#include "MODELS/bicicletta.h"
#include "CONTROLLERS/controller.h"
#include "VIEWS/view.h"
#include <QApplication>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;

    std::ifstream dBCitta("database/dataBaseCitta.txt");
    if (dBCitta.is_open()){
        string nomeCitta;
        while(dBCitta >> nomeCitta){
            model.addCity(new Citta(nomeCitta));
        }
    }else std::cout << "non riesco ad aprire il file dBCitta\n";
    dBCitta.close();

    model.addVehicle(0, new Bicicletta("Targa-Bici1", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle(0, new Automobile("Targa-Auto1", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));
    model.addVehicle(1, new Bicicletta("Targa-Bici2", "posizione", 10, 10, 10, 2000, 1000, Bicicletta::veloce));
    model.addVehicle(1, new Automobile("Targa-Auto2", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));
    model.addVehicle(1, new Automobile("Targa-Auto3", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));

    Controller controller(&model);
    View w(&controller);
    controller.setView(&w);
    w.show();

    return a.exec();
}

// fare controllo su add city per nomi di citta uguali
