#include "controller.h"

Controller::Controller(Model* model, QObject* parent): QObject(parent),
    _view(nullptr), _model(model) {}

void Controller::setView(View *view) {
    _view = view;

    connect(_view->getCitiesListView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehiclesView(int)));
    connect(_view->getVehicleListView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getVehicleListView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehicleDetailView(int)));
    connect(_view->getVehicleDetailView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getVehicleDetailView(), SIGNAL(maintenanceChanged(int)), this, SLOT(toggleMaintenance(int)));
    connect(_view->getVehicleDetailView(), SIGNAL(removeButtonClicked()), this, SLOT(removeVehicle()));
    connect(_view->getVehicleDetailView(), SIGNAL(createMoveDialog()), this, SLOT(createMoveModal()));
    connect(view->getVehicleDetailView(), SIGNAL(vehicleMove(int)), this, SLOT(saveChage(int)));
}

Array<Citta*> Controller::getCities() const {
    return _model->getCities();
}

Array<Veicolo*> Controller::getVehicles() const {
    return _model->getCity(_currentCityIndex)->getVeicoli();
}

Veicolo* Controller::getVehicle() const {
    return _model->getVehicle(_currentCityIndex, _currentVehicleIndex);
}

QString Controller::getCurrentCity() const {
    QString title = _view->getVehicleListView()->getTitle();
    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
}

QString Controller::getCurrentVehicle() const {
    QString title = _view->getVehicleDetailView()->getTitle();
    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
}

void Controller::addCity(const std::string& nome) {
    _model->addCity(new Citta(nome));
    _view->getCurrentView()->update();
}

void Controller::addVehicle(unsigned int city, Veicolo* const vehicle) {
    _model->addVehicle(city, vehicle);
    _view->getCurrentView()->update();
}

void Controller::goToVehiclesView(int row) {
    _view->getCurrentView()->resetTableSelection();
    VehicleListView* vehicles = _view->getVehicleListView();
    _currentCityIndex = row;

    vehicles->setTitle("Flotta di " + QString::fromStdString(_model->getCity(row)->getNome()));
    vehicles->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });
    vehicles->update();
    _view->setCurrentView(vehicles);
}

void Controller::goToVehicleDetailView(int row) {
    _view->getCurrentView()->resetTableSelection();
    VehicleDetailView* vehicleDetail = _view->getVehicleDetailView();
    _currentVehicleIndex = row;

    vehicleDetail->setHederStrings({ "Targa", "Posizione", "Chilometraggio" });    
    vehicleDetail->setTitle("Veicolo " + QString::fromStdString(_model->getVehicle(_currentCityIndex, row)->targa()));
    vehicleDetail->update();
    _view->setCurrentView(vehicleDetail);
}

void Controller::goBack() const {
    unsigned int currentView = _view->getCurrentIndex();
    _view->setCurrentIndex(currentView - 1);
    _view->getCurrentView()->update();
}

void Controller::toggleMaintenance(int state) const {
    _model->getVehicle(_currentCityIndex, _currentVehicleIndex)->setServeAssistenza(state);
}

void Controller::createMoveModal() const {
    std::string city = getCurrentCity().toStdString();
    _view->getVehicleDetailView()->createMoveDialog(city);
}

void Controller::removeVehicle() const {
    Veicolo* vehicle = _model->removeVehicle(_currentCityIndex, _currentVehicleIndex);
    _view->getVehicleListView()->update();
    goBack();
    std::stringstream msg;
    msg << "Veicolo \"" << vehicle->targa() << "\" rimosso dalla flotta.";
    _view->getCurrentView()->showMessage(QString::fromStdString(msg.str()));
}

void Controller::saveChage(int row) const {
    try {
        Veicolo* vehicle = _model->getVehicle(_currentCityIndex, _currentVehicleIndex);
        _model->moveVehicle(_currentCityIndex, row, _currentVehicleIndex);
        goBack();
        std::stringstream msg;
        msg << "Veicolo \"" << vehicle->targa() << "\" spostato a " << _model->getCity(row)->getNome() << ".";
        _view->getCurrentView()->showMessage(QString::fromStdString(msg.str()));
    } catch (std::exception* e) {
        _view->getCurrentView()->showMessage(e->what());
    }
}
