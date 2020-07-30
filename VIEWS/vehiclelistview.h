#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "basebackabstractview.h"
#include "MODELS/automobile.h"
#include "MODELS/automobileelettrica.h"
#include "MODELS/autoibrida.h"
#include "MODELS/moto.h"
#include "MODELS/motoelettrica.h"
#include "MODELS/monopattino.h"
#include "MODELS/bicicletta.h"
#include "CONTROLLERS/controller.h"
#include <typeinfo>
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

    const QString& getIconPath(const Veicolo& vehicle);

signals:
    void selectedVehicle(QTableWidgetItem* itemClicked);
};

#endif // VEHICLELISTVIEW_H
