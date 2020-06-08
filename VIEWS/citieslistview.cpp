#include "citieslistview.h"

CitiesListView::CitiesListView(CitiesListController* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseAbstractView(title, headerStrings, parent), _controller(controller) {
    setMinimumSize(600, 400);
}

CitiesListView::~CitiesListView() {
    delete _controller;
}

void CitiesListView::update() {
    Array<Citta*> cities = _controller->getCities();
    _table->setRowCount(cities.size());

    for (int i = 0; i < _table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(cities[i]->getNome()));
        connect(_table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SIGNAL(rowDoubleClicked(QTableWidgetItem*)));
        _table->setItem(i, 0, item);
    }
    _table->resizeColumnsToContents();
}
