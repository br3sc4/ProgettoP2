#include "VIEWS/view.h"

View::View(Controller* controller, QWidget *parent) : QWidget(parent), _layout(new QVBoxLayout), _navigator(new QStackedWidget(this)),
    _citiesView(new CitiesListView(controller, "Città", { "Città", "Numero veicoli" })),
    _vehiclesView(new VehicleListView(controller)),
    _vehicleDetailView(new VehicleDetailView(controller)) {
    _citiesView->update();
    _navigator->addWidget(_citiesView);
    _navigator->addWidget(_vehiclesView);
    _navigator->addWidget(_vehicleDetailView);

    _layout->addWidget(_navigator);
    setLayout(_layout);
    setMinimumSize(600, 400);
}

View::~View() {
    delete _vehicleDetailView;
    delete _vehiclesView;
    delete _citiesView;
    delete _navigator;
    delete _layout;
}

CitiesListView *View::getCitiesListView() const {
    return _citiesView;
}

VehicleListView *View::getVehicleListView() const {
    return _vehiclesView;
}

VehicleDetailView *View::getVehicleDetailView() const {
    return _vehicleDetailView;
}

BaseAbstractView* View::getCurrentView() const {
    return dynamic_cast<BaseAbstractView*>(_navigator->currentWidget());
}

void View::setCurrentView(BaseAbstractView *view) {
    _navigator->setCurrentWidget(view);
}

unsigned int View::getCurrentIndex() const {
    return _navigator->currentIndex();
}

void View::setCurrentIndex(unsigned int index) {
    _navigator->setCurrentIndex(index);
}
