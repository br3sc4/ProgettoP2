#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "baseview.h"
#include <QPushButton>

class VehicleListView : public BaseView {
    Q_OBJECT
public:
    explicit VehicleListView(const QString& title = "Elenco veicoli", QWidget *parent = nullptr);
    virtual ~VehicleListView();

private:
    QPushButton* _backButton;

    virtual void setupTable();
    void setupBackButton();

signals:
    void backButtonClicked();
    void selectedVehicle(QTableWidgetItem* itemClicked);
};

#endif // VEHICLELISTVIEW_H
