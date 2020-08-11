#ifndef VEHICLELISTVIEW_H
#define VEHICLELISTVIEW_H

#include "viewinterface.h"
#include "Components/backtopbar.h"
#include "Components/statetableitem.h"
#include "controller.h"
#include <typeinfo>
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class VehicleListView: public ViewInterface {
    Q_OBJECT

public:
    explicit VehicleListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void reload() override;

    void setHederStrings(const QStringList& headerStrings);

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BackTopBar* _topBar;
    QTableWidget* _table;
    Qt::SortOrder _order;

    void setupTable(const QStringList& headerStrings);
    void setupLayout();

    const QString getIconPath(const Veicolo& vehicle) const;

signals:
    void sort(bool ascending);
};

#endif // VEHICLELISTVIEW_H
