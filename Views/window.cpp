#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent), _layout(new QVBoxLayout), _navigator(new QStackedWidget(this)),
    _citiesView(new BaseView()), _vehiclesView(new VehicleListView()) {
    _navigator->addWidget(_citiesView);

    btn = new QPushButton("next");

    _layout->addWidget(_navigator);
    _layout->addWidget(btn);
    setLayout(_layout);
    setMinimumSize(600, 400);

    connect(btn, SIGNAL(clicked()), this, SLOT(goToVehiclesView()));
}

Window::~Window() {
    delete btn;
    delete _layout;
    delete _citiesView;
    delete _vehiclesView;
}

void Window::goToVehiclesView() {
    _navigator->addWidget(_vehiclesView);
    int currentView = _navigator->currentIndex();
    _navigator->setCurrentIndex(currentView + 1);
    btn->hide();
    connect(_vehiclesView, SIGNAL(backButtonClicked()), this, SLOT(goBack()));
}

void Window::goBack() {
    int currentView = _navigator->currentIndex();
    _navigator->setCurrentIndex(currentView - 1);
    btn->show();
}
