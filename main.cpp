#include "CONTROLLERS/controller.h"
#include "VIEWS/view.h"
#include <QApplication>
#include "loadDataBase.cpp"

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
