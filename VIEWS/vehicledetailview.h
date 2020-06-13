#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include "basebackabstractview.h"
#include "CONTROLLERS/controller.h"
#include <QCheckBox>
#include <QPushButton>

class VehicleDetailView : public BaseBackAbstractView {
    Q_OBJECT

public:
    explicit VehicleDetailView(Controller* controller, const QString& title = "Vehicle",
                               const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~VehicleDetailView();
    virtual void update();

private:
    Controller* _controller;
    QCheckBox *_checkBox;
    QPushButton *_moveButton, *_removeButton;

    void setupCheckBox();
    void setupMoveButton();
    void setupRemoveButton();

signals:
    void maintenanceChanged(int);
    void removeButtonClicked();
};

#endif // VEHICLEDETAILVIEW_H
