#include "view.h"
#include "Views/Components/basetopbar.h"

View::View(Controller* controller, QWidget *parent) : QStackedWidget(parent),
    _citiesView(new CitiesListView(controller, "Città", { "Città", "Numero veicoli" })),
    _vehiclesView(new VehicleListView(controller)),
    _vehicleDetailView(new VehicleDetailView(controller)),
    _controller(controller), _titoloApp("CitySharing"), _altezza(1000), _larghezza(700) {

    setFixedSize(_altezza, _larghezza);
    setWindowTitle(_titoloApp);

    addWidget(_citiesView);
    addWidget(_vehiclesView);
    addWidget(_vehicleDetailView);

    setupStyle();

    connect(_citiesView, &ViewInterface::closeSignal, this, &View::close);
    connect(_citiesView, &ViewInterface::showAddCityWizard, this, [=]() {
        createWizard(true);
    });
    connect(_citiesView, &ViewInterface::showAddVehicleWizard, this, [=]() {
        createWizard();
    });

    connect(_vehiclesView, &ViewInterface::closeSignal, this, &View::close);
    connect(_vehiclesView, &ViewInterface::showAddCityWizard, this, [=]() {
        createWizard(true);
    });
    connect(_vehiclesView, &ViewInterface::showAddVehicleWizard, this, [=]() {
        createWizard();
    });

    connect(_vehicleDetailView, &ViewInterface::closeSignal, this, &View::close);
    connect(_vehicleDetailView, &ViewInterface::showAddCityWizard, this, [=]() {
        createWizard(true);
    });
    connect(_vehicleDetailView, &ViewInterface::showAddVehicleWizard, this, [=]() {
        createWizard();
    });

    _citiesView->reload();
}

View::~View() {
    delete _vehicleDetailView;
    delete _vehiclesView;
    delete _citiesView;
}

CitiesListView *View::getCitiesListView() const {
    return _citiesView;
}

VehicleListView* View::getVehicleListView() const {
    return _vehiclesView;
}

VehicleDetailView *View::getVehicleDetailView() const {
    return _vehicleDetailView;
}

void View::showMessage(const QString &msg) {
    QMessageBox* dialog = new QMessageBox(this);
    dialog->setText(msg);

    dialog->show();
}

void View::setupStyle() {
    QFile file(":/ExtraFiles/Styles/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}

void View::createWizard(bool addCityMode) {
    CityWizard* wizard = new CityWizard(addCityMode, _controller, this);
    wizard->show();
    wizard->activateWindow();
}
