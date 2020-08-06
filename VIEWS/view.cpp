#include "VIEWS/view.h"

#include "Components/basetopbar.h"
View::View(Controller* controller, QWidget *parent) : QStackedWidget(parent),
    _citiesView(new CitiesListView(controller, "Città", { "Città", "Numero veicoli" })),
    _vehiclesView(new VehicleListView(controller)),
    _vehicleDetailView(new VehicleDetailView(controller)),
    _controller(controller) {

    setMinimumSize(_minAltezza, _minLarghezza);
    setWindowTitle(_titoloApp);

    addWidget(_citiesView);
    addWidget(_vehiclesView);
    addWidget(_vehicleDetailView);

    setupStyle();

    connect(_citiesView, &CitiesListView::closeSignal, this, &View::close);
    connect(_citiesView, &CitiesListView::showAddCityWizard, this, [=]() {
        createWizard(true);
    });
    connect(_citiesView, &CitiesListView::showAddVehicleWizard, this, [=]() {
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
    QFile file(":/stylesheets/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}

void View::createWizard(bool addCityMode) {
    CityWizard* wizard = new CityWizard(addCityMode, _controller, this);
    wizard->show();
    wizard->activateWindow();
}
