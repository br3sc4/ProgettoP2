#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "basebackabstractview.h"
#include <QPushButton>

class VehicleListView : public BaseBackAbstractView {
    Q_OBJECT
public:
    explicit VehicleListView(const QString& title = "Vehicles", const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~VehicleListView();

signals:
    void selectedVehicle(QTableWidgetItem* itemClicked);
};

#endif // VEHICLELISTVIEW_H
