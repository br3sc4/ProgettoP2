#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "model.h"
#include "view.h"
#include "Views/citieslistview.h"
#include <QObject>
#include <ostream>
#include <sstream>

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

    QString getCurrentCity() const;
    QString getCurrentVehicle() const;

    void addCity(const std::string& nome);
    void addVehicle(unsigned int city, Veicolo* const vehicle);

    bool searchCity(const std::string& nome) const;
    bool searchVehicle(unsigned int city, const std::string& vehicle) const;    

    void showMessage(const QString& msg) const;

private:
    View *_view;
    Model* _model;
    unsigned int _currentCityIndex, _currentVehicleIndex;

private slots:
    void goToVehiclesView(int row);
    void goToVehicleDetailView(int row);
    void goBack() const;
    void toggleMaintenance(int state) const;
    void createMoveModal() const;
    void removeVehicle() const;
    void saveChage(int row) const;
    void deleteCity(unsigned index) const;
    void sortVeiclesByState(bool ascending) const;
};

#endif // CITIESLISTCONTROLLER_H
