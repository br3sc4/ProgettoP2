#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {
    setMinimumSize(600, 400);
}

void VehicleListView::update() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    for (int i = 0; i < _table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->posizione()));
        _table->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->chilometraggio()));
        _table->setItem(i, 2, item);
        connect(_table, SIGNAL(cellClicked(int, int)), this, SIGNAL(rowClicked(int, int)));
    }
    _table->resizeColumnsToContents();
}
