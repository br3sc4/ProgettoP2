#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include "basebackabstractview.h"
#include "CONTROLLERS/controller.h"
#include <QCheckBox>
#include <QPushButton>
#include <QScrollBar>
#include <QDialog>
#include <QDialogButtonBox>

class VehicleDetailView : public BaseBackAbstractView {
    Q_OBJECT

public:
    explicit VehicleDetailView(Controller* controller, const QString& title = "Vehicle",
                               const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~VehicleDetailView();
    virtual void update();

    void createMoveDialog(const std::string& currentCity);

private:
    Controller* _controller;
    QCheckBox *_checkBox;
    QPushButton *_moveButton, *_removeButton;

    void setupCheckBox();
    void setupMoveButton();
    void setupRemoveButton();
    void setDynamicData(const Veicolo& veicolo);

signals:
    void maintenanceChanged(int);
    void createMoveDialog();
    void vehicleMove(int);
    void removeButtonClicked();
};

#endif // VEHICLEDETAILVIEW_H
