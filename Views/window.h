#ifndef WINDOW_H
#define WINDOW_H

#include "Views/baseview.h"
#include "Views/vehiclelistview.h"
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
    QPushButton *btn;

private slots:
    void goToVehiclesView();
    void goBack();
};

#endif // WINDOW_H
