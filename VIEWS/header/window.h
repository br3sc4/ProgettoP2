#ifndef WINDOW_H
#define WINDOW_H

#include "VIEWS/header/baseview.h"
#include "VIEWS/header/vehiclelistview.h"
#include "VIEWS/header/vehicledetailview.h"
#include <QWidget>
#include <QStackedWidget>

class Window : public QWidget {
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    QVBoxLayout *_layout;
    QStackedWidget *_navigator;
    BaseView *_citiesView;
    VehicleListView *_vehiclesView;
    VehicleDetailView *_vehicleDetailView;

private slots:
    void goToVehiclesView(QTableWidgetItem* itemClicked);
    void goToVehicleDetailView(QTableWidgetItem* itemClicked);
    void goBack();
};

#endif // WINDOW_H
