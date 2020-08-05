#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H

#include <QWidget>

class ViewInterface: public QWidget {
    Q_OBJECT

public:
    explicit ViewInterface(QWidget* parent = nullptr);
    virtual ~ViewInterface() = 0;

    virtual void reload() = 0;

signals:
    void closeSignal();
    void showAddCityWizard();
    void showAddVehicleWizard();
    void backButtonClicked();
    void rowClicked(int row);
};

#endif // VIEWINTERFACE_H
