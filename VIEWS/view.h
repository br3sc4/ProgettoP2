#ifndef WINDOW_H
#define WINDOW_H

#include "CONTROLLERS/citieslistcontroller.h"
#include "VIEWS/citieslistview.h"
#include "VIEWS/vehiclelistview.h"
#include "VIEWS/vehicledetailview.h"
#include <QWidget>
#include <QStackedWidget>

class View : public QWidget {
    Q_OBJECT

public:
    explicit View(CitiesListController* citiesListController, QWidget *parent = nullptr);
    ~View();

private:
    QVBoxLayout *_layout;
    QStackedWidget *_navigator;
    CitiesListView *_citiesView;
    VehicleListView *_vehiclesView;
    VehicleDetailView *_vehicleDetailView;

private slots:
    void goToVehiclesView(QTableWidgetItem* itemClicked);
    void goToVehicleDetailView(QTableWidgetItem* itemClicked);
    void goBack();
};

#endif // WINDOW_H
