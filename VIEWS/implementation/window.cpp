#include "VIEWS/header/window.h"

Window::Window(QWidget *parent) : QWidget(parent), _layout(new QVBoxLayout), _navigator(new QStackedWidget(this)),
    _citiesView(new BaseView()), _vehiclesView(new VehicleListView()), _vehicleDetailView(new VehicleDetailView()) {
    _navigator->addWidget(_citiesView);
    _navigator->addWidget(_vehiclesView);
    _navigator->addWidget(_vehicleDetailView);

    _layout->addWidget(_navigator);
    setLayout(_layout);
    setMinimumSize(600, 400);

    connect(_vehiclesView, SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_vehicleDetailView, SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_citiesView, SIGNAL(selectedCity(QTableWidgetItem*)), this, SLOT(goToVehiclesView(QTableWidgetItem*)));
    connect(_vehiclesView, SIGNAL(selectedVehicle(QTableWidgetItem*)), this, SLOT(goToVehicleDetailView(QTableWidgetItem*)));
}

Window::~Window() {
    delete _layout;
    delete _citiesView;
    delete _vehiclesView;
    delete _vehicleDetailView;
}

void Window::goToVehiclesView(QTableWidgetItem* itemClicked) {
    // TODO: integrate controller
    QString title = "Elenco veicoli in " + QString::number(itemClicked->row());
    _vehiclesView->setTitle(title);
    _navigator->setCurrentWidget(_vehiclesView);
}

void Window::goToVehicleDetailView(QTableWidgetItem *itemClicked) {
    // TODO: integrate controller
    QString title = "Veicolo: " + QString::number(itemClicked->row());
    _vehicleDetailView->setTitle(title);
    _navigator->setCurrentWidget(_vehicleDetailView);
}

void Window::goBack() {
    _citiesView->resetTable();
    _vehiclesView->resetTable();
    _vehicleDetailView->resetTable();
    int currentView = _navigator->currentIndex();
    _navigator->setCurrentIndex(currentView - 1);
}
