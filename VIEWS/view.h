#ifndef WINDOW_H
#define WINDOW_H

#include "CONTROLLERS/controller.h"
#include "VIEWS/citieslistview.h"
#include "VIEWS/vehiclelistview.h"
#include "VIEWS/vehicledetailview.h"
#include "Wizard/citywizard.h"
#include <QStackedWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFile>

class Controller;
class CitiesListView;
class VehicleListView;
class VehicleDetailView;

class View : public QStackedWidget {
    Q_OBJECT

public:
    explicit View(Controller* controller, QWidget *parent = nullptr);
    ~View();

    CitiesListView* getCitiesListView() const;
    VehicleListView* getVehicleListView() const;
    VehicleDetailView* getVehicleDetailView() const;

    void showMessage(const QString& msg);

    QWidget* getCurrentView() const;
    void setCurrentView(QWidget* view);

private:
    CitiesListView* _citiesView;
    VehicleListView* _vehiclesView;
    VehicleDetailView* _vehicleDetailView;
    Controller* _controller;

    void setupStyle();

    const QString _titoloApp = "CitySharing";
    const unsigned int _minAltezza = 900;
    const unsigned int _minLarghezza = 600;

private slots:
    void createWizard(bool addCityMode = false);
};

#endif // WINDOW_H
