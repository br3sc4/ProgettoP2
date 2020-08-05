#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "viewinterface.h"
#include "Components/basetopbar.h"
#include "CONTROLLERS/controller.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class Controller;

class CitiesListView: public ViewInterface {
    Q_OBJECT

public:
    explicit CitiesListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void reload() override;

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
};

#endif // CITIESLISTVIEW_H
