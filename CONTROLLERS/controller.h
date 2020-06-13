#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "model.h"
#include "VIEWS/view.h"
#include "VIEWS/citieslistview.h"
#include <QObject>

class CitiesListView;
class View;

class Controller: public QObject {
    Q_OBJECT

public:
    explicit Controller(Model* model, QObject* parent = nullptr);

    void setView(View* view);

    Array<Citta*> getCities() const;
    Array<Veicolo*> getVehicles() const;
    Veicolo* getVehicle() const;

private:
    View *_view;
    Model* _model;
    std::string _currentCity;
    std::string _currentVehicle;

private slots:
    void goToVehiclesView(int row, int column);
    void goToVehicleDetailView(int row, int column);
    void goBack();
    void toggleMaintenance(int state);
    void removeVehicle();
};

#endif // CITIESLISTCONTROLLER_H
