#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "basebackabstractview.h"
#include "CONTROLLERS/controller.h"
#include <QPushButton>

class Controller;

class VehicleListView : public BaseBackAbstractView {
    Q_OBJECT
public:
    explicit VehicleListView(Controller* controller, const QString& title = "Vehicles",
                             const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    virtual void update();

private:
    Controller* _controller;

    virtual void setupMenuBar();

signals:
    void selectedVehicle(QTableWidgetItem* itemClicked);
};

#endif // VEHICLELISTVIEW_H
