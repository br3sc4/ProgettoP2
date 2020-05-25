//#include "baseview.h"
#include "Views/baseview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseView w("Elenco città");
    w.setMinimumSize(600, 400);
    w.show();
    return a.exec();
}
