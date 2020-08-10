#ifndef WINDOW_H
#define WINDOW_H

#include "controller.h"
#include "Views/citieslistview.h"
#include "Views/vehiclelistview.h"
#include "Views/vehicledetailview.h"
#include "Views/Wizard/citywizard.h"
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

    const QString _titoloApp;
    const unsigned int _altezza;
    const unsigned int _larghezza;

private slots:
    void createWizard(bool addCityMode = false);
};

#endif // WINDOW_H
