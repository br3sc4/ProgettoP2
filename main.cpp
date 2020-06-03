#include "MODELS/array.h"
#include "MODELS/automobile.h"
#include "MODELS/moto.h"
#include "MODELS/bicicletta.h"
#include "VIEWS/window.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Array<> v;

    v.push_back(new Bicicletta("Pippo", "posizione", 10, 2000, 1000, Bicicletta::veloce));
    v.push_back(new Automobile("Auto", "pos", 100, 60, 20, Automobile::diesel, 1600, 60, 4));

    for (Array<>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << (*it)->targa() << " ";
    }
    std::cout << std::endl;

    std::cout << v << std::endl;    // stampa l'indirizzo perché è un array di puntatori

    Window w;
    w.show();

    return a.exec();
}
