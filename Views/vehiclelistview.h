#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#import "baseview.h"
#import <QPushButton>

class VehicleListView : public BaseView {
    Q_OBJECT
public:
    explicit VehicleListView(const QString& title = "Elenco veicoli", QWidget *parent = nullptr);
    virtual ~VehicleListView();

private:
    QPushButton* _backButton;

    void setupBackButton();

signals:
    void backButtonClicked();
};

#endif // VEHICLELISTVIEW_H
