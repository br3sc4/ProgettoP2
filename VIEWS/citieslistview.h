#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "Components/basetopbar.h"
#include "CONTROLLERS/controller.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class CitiesListView: public QWidget {
    Q_OBJECT

public:
    explicit CitiesListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void update();

    void setHederStrings(const QStringList& headerStrings);
    void resetTableSelection();

    QString title() const;
    void setTitle(const QString& title);

    QTableWidget* table();

private:
    Controller* _controller;
    BaseTopBar* _topBar;
    QTableWidget* _table;

    void setupTable(const QStringList& headerStrings);
    void setupLayout();

signals:
    void closeSignal();
    void showAddCityWizard();
    void showAddVehicleWizard();
    void backButtonClicked();
    void rowClicked(int row);
};

#endif // CITIESLISTVIEW_H
