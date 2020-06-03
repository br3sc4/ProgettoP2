#include "VIEWS/window.h"

Window::Window(QWidget *parent) : QWidget(parent), _layout(new QVBoxLayout), _navigator(new QStackedWidget(this)),
    _citiesView(new CitiesListView("Cities", { "Città", "Numero veicoli" })), _vehiclesView(new VehicleListView),
    _vehicleDetailView(new VehicleDetailView) {
    _citiesView->setData({ "Pippo", "Pippo", "Pippo", "Pippo", "Pippo" });
    _navigator->addWidget(_citiesView);
    _navigator->addWidget(_vehiclesView);
    _navigator->addWidget(_vehicleDetailView);

    _layout->addWidget(_navigator);
    setLayout(_layout);
    setMinimumSize(600, 400);

    connect(_vehiclesView, SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_vehicleDetailView, SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_citiesView, SIGNAL(rowDoubleClicked(QTableWidgetItem*)), this, SLOT(goToVehiclesView(QTableWidgetItem*)));
    connect(_vehiclesView, SIGNAL(rowDoubleClicked(QTableWidgetItem*)), this, SLOT(goToVehicleDetailView(QTableWidgetItem*)));
}

Window::~Window() {
    delete _vehicleDetailView;
    delete _vehiclesView;
    delete _citiesView;
    delete _navigator;
    delete _layout;
}

void Window::goToVehiclesView(QTableWidgetItem* itemClicked) {
    _citiesView->resetTableSelection();
    // TODO: integrate controller
    QString title = "Elenco veicoli in " + QString::number(itemClicked->row());
    _vehiclesView->setTitle(title);
    _vehiclesView->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });
    _vehiclesView->setData({ "Pippo", "Pippo", "Pippo", "Pippo", "Pippo", "Pippo", "Pippo" });
    _navigator->setCurrentWidget(_vehiclesView);
}

void Window::goToVehicleDetailView(QTableWidgetItem *itemClicked) {
    _vehiclesView->resetTableSelection();
    // TODO: integrate controller
    QString title = "Veicolo " + QString::number(itemClicked->row());
    _vehicleDetailView->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });
    _vehicleDetailView->setData({ "Pippo" });
    _vehicleDetailView->setTitle(title);
    _navigator->setCurrentWidget(_vehicleDetailView);
}

void Window::goBack() {
    int currentView = _navigator->currentIndex();
    _navigator->setCurrentIndex(currentView - 1);
}
