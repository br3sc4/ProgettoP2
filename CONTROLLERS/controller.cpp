#include "controller.h"
#include <ostream>

Controller::Controller(Model* model, QObject* parent): QObject(parent),
    _view(nullptr), _model(model), _currentCity(), _currentVehicle() {}

void Controller::setView(View *view) {
    _view = view;

    connect(_view->getCitiesListView(), SIGNAL(rowClicked(int, int)), this, SLOT(goToVehiclesView(int, int)));
    connect(_view->getVehicleListView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getVehicleListView(), SIGNAL(rowClicked(int, int)), this, SLOT(goToVehicleDetailView(int, int)));
    connect(_view->getVehicleDetailView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getVehicleDetailView(), SIGNAL(maintenanceChanged(int)), this, SLOT(toggleMaintenance(int)));
    connect(_view->getVehicleDetailView(), SIGNAL(removeButtonClicked()), this, SLOT(removeVehicle()));
}

Array<Citta *> Controller::getCities() const {
    return _model->getCities();
}

Array<Veicolo*> Controller::getVehicles() const {
    return *(_model->getCity(_currentCity)->getVeicoli());
}

Veicolo* Controller::getVehicle() const {
    return _model->getVehicle(_currentCity, _currentVehicle);
}

void Controller::goToVehiclesView(int row, int column) {
    _view->getCurrentView()->resetTableSelection();
    VehicleListView* vehicles = _view->getVehicleListView();
    _currentCity = _model->getCity(row)->getNome();

    QString title = "Elenco veicoli in " + QString::fromStdString(_currentCity);
    vehicles->setTitle(title);
    vehicles->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });
    vehicles->update();
    _view->setCurrentView(vehicles);
}

void Controller::goToVehicleDetailView(int row, int column) {
    _view->getCurrentView()->resetTableSelection();
    VehicleDetailView* vehicleDetail = _view->getVehicleDetailView();
    _currentVehicle = _model->getVehicle(_currentCity, row)->targa();

    QString title = "Veicolo " + QString::fromStdString(_currentVehicle);
    vehicleDetail->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });
    vehicleDetail->update();
    vehicleDetail->setTitle(title);
    _view->setCurrentView(vehicleDetail);
}

void Controller::goBack() {
    unsigned int currentView = _view->getCurrentIndex();
    _view->setCurrentIndex(currentView - 1);
    _view->getCurrentView()->update();
}

void Controller::toggleMaintenance(int state) {
    _model->getVehicle(_currentCity, _currentVehicle)->setServeAssistenza(state);
}

void Controller::removeVehicle() {
    _model->removeVehicle(_currentCity, _currentVehicle);
    _view->getVehicleListView()->update();
    goBack();
}
