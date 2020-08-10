#include "controller.h"
#include "view.h"
#include <QApplication>
#include "loadDataBase.cpp"
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model model;    

    loadCitta(model);
    loadVeicoli(model);

    Controller controller(&model);
    View w(&controller);
    controller.setView(&w);
    w.show();

    return a.exec();
}
