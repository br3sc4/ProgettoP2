#include "Model/array.h"
#include "Views/window.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Array<int> v;

    for (int i = 1; i <= 9; i++) {
        v.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;

    *(v.begin()) = 0;
    *(++(v.begin())) = 1;

    v.erase(v.begin());

    std::cout << v << std::endl;
//    Window w;
//    w.show();
//    return a.exec();
}
