#include "controller.h"
#include <typeinfo>
#include <algorithm>

Controller::Controller(Model* model, QObject* parent): QObject(parent),
    _view(nullptr), _model(model) {}

void Controller::setView(View *view) {
    _view = view;

    connect(_view->getCitiesListView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehiclesView(int)));
    connect(_view->getCitiesListView(), SIGNAL(deleteCityButtonClicked(unsigned)), this, SLOT(deleteCity(unsigned)));
    connect(_view->getVehicleListView(), SIGNAL(backButtonClicked()), this, SLOT(goBack()));
    connect(_view->getVehicleListView(), SIGNAL(rowClicked(int)), this, SLOT(goToVehicleDetailView(int)));
    connect(_view->getVehicleListView(), SIGNAL(sort(bool)), this, SLOT(sortVeiclesByState(bool)));
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
    QString title = _view->getVehicleListView()->title();
    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
}

QString Controller::getCurrentVehicle() const {
    QString title = _view->getVehicleDetailView()->title();
    return title.split(QLatin1Char(' ')).last().split(QLatin1Char('<')).first();
}

void Controller::addCity(const std::string& nome) {
    _model->addCity(new Citta(nome));
    dynamic_cast<ViewInterface*>(_view->currentWidget())->reload();
}

void Controller::addVehicle(unsigned int city, Veicolo* const vehicle) {
    _model->addVehicle(city, vehicle);
    dynamic_cast<ViewInterface*>(_view->currentWidget())->reload();
}

bool Controller::searchCity(const std::string& nome) const {
    return _model->searchCity(nome);
}

bool Controller::searchVehicle(unsigned int city, const std::string& vehicle) const {
    return _model->searchVehicle(city, vehicle);
}

void Controller::sortVeiclesByState(bool ascending) const {
    _model->sortVehicleByState(_currentCityIndex, ascending);
}

void Controller::showMessage(const QString& msg) const {
    _view->showMessage(msg);
}

void Controller::goToVehiclesView(int row) {
    VehicleListView* vehicles = _view->getVehicleListView();
    _currentCityIndex = row;

    vehicles->setTitle("Flotta di " + QString::fromStdString(_model->getCity(row)->getNome()));
    vehicles->setHederStrings({ "Tipologia", "Targa", "Stato", "Serve assistenza", "In riserva", "Autonomia", "Fattore green", "Fattore utilizzo" });
    vehicles->reload();
    _view->setCurrentWidget(vehicles);
}

void Controller::goToVehicleDetailView(int row) {
    VehicleDetailView* vehicleDetail = _view->getVehicleDetailView();
    _currentVehicleIndex = row;

    vehicleDetail->setTitle("Veicolo " + QString::fromStdString(_model->getVehicle(_currentCityIndex, row)->targa()));
    vehicleDetail->reload();
    _view->setCurrentWidget(vehicleDetail);
}

void Controller::goBack() const {
    int currentView = _view->currentIndex();    
    _view->setCurrentIndex(currentView - 1);

    if (CitiesListView* view = dynamic_cast<CitiesListView*>(_view->currentWidget()))
        view->reload();
}

void Controller::toggleMaintenance(int state) const {
    Veicolo* vehicle = _model->getVehicle(_currentCityIndex, _currentVehicleIndex);

    if (state == Qt::Checked)
        vehicle->setStatoAttuale(Veicolo::manutenzione);
    else if (state == Qt::Unchecked)
        vehicle->setStatoAttuale(Veicolo::libero);

    dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex()))->reload();
    dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex() - 1))->reload();
}

void Controller::createMoveModal() const {
    std::string city = getCurrentCity().toStdString();
    _view->getVehicleDetailView()->createMoveDialog(city);
}

void Controller::removeVehicle() const {
    Veicolo* vehicle = _model->removeVehicle(_currentCityIndex, _currentVehicleIndex);
    _view->getVehicleListView()->reload();
    goBack();
    std::stringstream msg;
    msg << "Veicolo \"" << vehicle->targa() << "\" rimosso dalla flotta.";
    _view->showMessage(QString::fromStdString(msg.str()));
}

void Controller::saveChage(int row) const {
    try {
        Veicolo* vehicle = _model->getVehicle(_currentCityIndex, _currentVehicleIndex);
        _model->moveVehicle(_currentCityIndex, row, _currentVehicleIndex);

        std::stringstream msg;
        msg << "Veicolo \"" << vehicle->targa() << "\" spostato a " << _model->getCity(row)->getNome() << ".";
        _view->showMessage(QString::fromStdString(msg.str()));
        dynamic_cast<ViewInterface*>(_view->widget(_view->currentIndex() - 1))->reload();
        goBack();
    } catch (std::exception* e) {
        _view->showMessage(e->what());
    }
}

void Controller::deleteCity(unsigned index) const {
    Citta* city = _model->removeCity(index);
    CitiesListView* cities = _view->getCitiesListView();
    cities->reload();

    std::stringstream msg;
    msg << "Città \"" << city->getNome() << "\" rimossa dalla piattaforma.";
    _view->showMessage(QString::fromStdString(msg.str()));
}
