#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include <QCheckBox>
#include <QPushButton>
#include "vehiclelistview.h"

class VehicleDetailView : public VehicleListView {
    Q_OBJECT

public:
    explicit VehicleDetailView(const QString& title = "Veicolo", QWidget *parent = nullptr);
    virtual ~VehicleDetailView();

private:
    QCheckBox *_checkBox;
    QPushButton *_moveButton, *_removeButton;

    virtual void setupTable();
    void setupCheckBox();
    void setupMoveButton();
    void setupRemoveButton();
};

#endif // VEHICLEDETAILVIEW_H
