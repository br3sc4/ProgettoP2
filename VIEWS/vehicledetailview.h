#ifndef VEHICLEDETAILVIEW_H
#define VEHICLEDETAILVIEW_H

#include "basebackabstractview.h"
#include <QCheckBox>
#include <QPushButton>

class VehicleDetailView : public BaseBackAbstractView {
    Q_OBJECT

public:
    explicit VehicleDetailView(const QString& title = "Vehicle", const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~VehicleDetailView();

private:
    QCheckBox *_checkBox;
    QPushButton *_moveButton, *_removeButton;

    void setupCheckBox();
    void setupMoveButton();
    void setupRemoveButton();
};

#endif // VEHICLEDETAILVIEW_H
