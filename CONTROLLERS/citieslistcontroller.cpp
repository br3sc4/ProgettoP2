#include "citieslistcontroller.h"

CitiesListController::CitiesListController(Model* model, QObject* parent): BaseAbstractController(parent),
    _view(nullptr), _model(model) {}

void CitiesListController::setViewTitle() {
    _view->setTitle("Elenco città");
}

void CitiesListController::setViewHeader() {
    _view->setHederStrings({ "Città" });
}

void CitiesListController::setView(BaseAbstractView* view) {
    _view = static_cast<CitiesListView*>(view);
}

Array<Citta *> CitiesListController::getCities() const {
    return _model->getCities();
}
