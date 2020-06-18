#include "VIEWS/view.h"

View::View(Controller* controller, QWidget *parent) : QStackedWidget(parent),
    _citiesView(new CitiesListView(controller, "Città", { "Città", "Numero veicoli" })),
    _vehiclesView(new VehicleListView(controller)),
    _vehicleDetailView(new VehicleDetailView(controller)) {
    _citiesView->update();

    addWidget(_citiesView);
    addWidget(_vehiclesView);
    addWidget(_vehicleDetailView);

    setMinimumSize(600, 400);

    connect(_citiesView, &BaseAbstractView::closeSignal, this, &View::close);
//    connect(_citiesView, &BaseAbstractView::showWizard, this, &View::showWizard);
}

View::~View() {
    delete _vehicleDetailView;
    delete _vehiclesView;
    delete _citiesView;
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
    return dynamic_cast<BaseAbstractView*>(currentWidget());
}

void View::setCurrentView(BaseAbstractView* view) {
    setCurrentWidget(view);
}

unsigned int View::getCurrentIndex() const {
    return currentIndex();
}

void View::createWizard() {

}
