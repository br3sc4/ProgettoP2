#include "MODELS/header/array.h"
#include "VIEWS/header/window.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Array<int> v;

    std::cout << "ciao";

    for (int i = 1; i <= 9; i++) {
        v.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;

    *(v.begin()) = 0;
    //v.insert(v.begin()+10, 0);
    *(++(v.begin())) = 2;

    v.erase(v.begin());

    std::cout << v << std::endl;

    v.clear();
    std::cout << v << std::endl;

    v.push_back(1);
    std::cout << v << std::endl;

    v.pop_back();
   std::cout << v << std::endl;

   Window w;
    w.show();
    return a.exec();

   return 0;
}
