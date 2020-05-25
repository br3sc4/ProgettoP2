#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#import "baseview.h"
#import <QPushButton>

class VehicleListView : public BaseView {
    Q_OBJECT
public:
    VehicleListView(const QString& title, QWidget *parent = nullptr);
    virtual ~VehicleListView();

private:
    QPushButton* _backButton;

    void setupBackButton();
};

#endif // VEHICLELISTVIEW_H
