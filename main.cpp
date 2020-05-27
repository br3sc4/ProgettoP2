#include "Model/array.h"
#include "Views/window.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Array<int> v(10, 1);

    for (auto it = v.begin(); it != v.end(); it++) {
        *it = 10;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (auto it = v.cbegin(); it != v.cend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
//    Window w;
//    w.show();
//    return a.exec();
}
