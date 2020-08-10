#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include "Components/backtopbar.h"
#include "controller.h"
#include "QCheckBox"
#include "QPushButton"
#include "QScrollBar"
#include "QDialog"
#include "QDialogButtonBox"

class VehicleDetailView: public ViewInterface {
    Q_OBJECT

public:
    explicit VehicleDetailView(Controller* controller, const QString& title = "Vehicle", QWidget *parent = nullptr);
    ~VehicleDetailView();

    void reload() override;

    QString title() const;
    void setTitle(const QString& title);

    void createMoveDialog(const std::string& currentCity);

private:
    Controller* _controller;
    QVBoxLayout* _verticalLayout;
    QGridLayout* _gridLayout;
    BackTopBar* _topBar;
    QCheckBox *_checkBox;
    QPushButton *_moveButton, *_removeButton;

    void setupLayout();
    void setupMoveButton();
    void setupRemoveButton();

    void setDynamicData(const Veicolo& veicolo);
    void clearDynamicData();

signals:
    void maintenanceChanged(int);
    void createMoveDialog();
    void vehicleMove(int);
    void removeButtonClicked();
};

#endif // VEHICLEDETAILVIEW_H
