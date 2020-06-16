#include "citieslistview.h"

CitiesListView::CitiesListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseAbstractView(title, headerStrings, parent), _controller(controller) {
    setMinimumSize(600, 400);
}

void CitiesListView::update() {
    Array<Citta*> cities = _controller->getCities();
    _table->setRowCount(cities.size());

    for (int i = 0; i < _table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(cities[i]->getNome()));
        _table->setItem(i, 0, item);
        item = new QTableWidgetItem(QString::number(cities[i]->getVeicoli()->size()));
        _table->setItem(i, 1, item);

        connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            emit rowClicked(item->row());
        });
    }
}
