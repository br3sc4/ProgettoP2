#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "Components/backtopbar.h"
#include "CONTROLLERS/controller.h"
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class VehicleListView: public QWidget {
    Q_OBJECT

public:
    explicit VehicleListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void update();

    void setHederStrings(const QStringList& headerStrings);
    void resetTableSelection();

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BackTopBar* _topBar;
    QTableWidget* _table;

    void setupTable(const QStringList& headerStrings);
    void setupLayout();

    const QString getIconPath(const Veicolo& vehicle) const;

signals:
    void closeSignal();
    void showAddCityWizard();
    void showAddVehicleWizard();
    void backButtonClicked();
    void rowClicked(int row);
    void selectedVehicle(QTableWidgetItem* itemClicked);
};

#endif // VEHICLELISTVIEW_H
