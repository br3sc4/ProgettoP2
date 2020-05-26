#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include "vehiclelistview.h"

class VehicleDetailView : public VehicleListView {
    Q_OBJECT

public:
    explicit VehicleDetailView(const QString& title = "Veicolo", QWidget *parent = nullptr);
    virtual ~VehicleDetailView();

private:
    virtual void setupTable();
};

#endif // VEHICLEDETAILVIEW_H
