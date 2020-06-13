#ifndef WINDOW_H
#define WINDOW_H

#include "CONTROLLERS/controller.h"
#include "VIEWS/citieslistview.h"
#include "VIEWS/vehiclelistview.h"
#include "VIEWS/vehicledetailview.h"
#include <QWidget>
#include <QStackedWidget>

class Controller;
class CitiesListView;
class VehicleListView;
class VehicleDetailView;

class View : public QWidget {
    Q_OBJECT

public:
    explicit View(Controller* controller, QWidget *parent = nullptr);
    ~View();

    CitiesListView* getCitiesListView() const;
    VehicleListView* getVehicleListView() const;
    VehicleDetailView* getVehicleDetailView() const;

    BaseAbstractView* getCurrentView() const;
    void setCurrentView(BaseAbstractView* view);

    unsigned int getCurrentIndex() const;
    void setCurrentIndex(unsigned int index);

private:
    QVBoxLayout *_layout;
    QStackedWidget *_navigator;
    CitiesListView *_citiesView;
    VehicleListView *_vehiclesView;
    VehicleDetailView *_vehicleDetailView;
};

#endif // WINDOW_H
