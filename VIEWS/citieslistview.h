#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "viewinterface.h"
#include "Components/basetopbar.h"
#include "controller.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>

class Controller;

class CitiesListView: public ViewInterface {
    Q_OBJECT

public:
    explicit CitiesListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    void reload() override;

    void setHederStrings(const QStringList& headerStrings);

    QString title() const;
    void setTitle(const QString& title);

private:
    Controller* _controller;
    BaseTopBar* _topBar;
    QTableWidget* _table;
    QPushButton* _deleteButton;

    void setupTable(const QStringList& headerStrings);
    void setupButton();
    void setupLayout();

signals:
    void deleteCityButtonClicked(unsigned row);
};

#endif // CITIESLISTVIEW_H
