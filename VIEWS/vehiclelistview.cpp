#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {}

void VehicleListView::update() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    for (int i = 0; i < _table->rowCount(); i++) {
        QLabel *icon = new QLabel;
        QPixmap* pixmap = new QPixmap(getIconPath(*vehicles[i]));
        icon->setPixmap(pixmap->scaled(40, 40, Qt::KeepAspectRatio));
        _table->setCellWidget(i, 0, icon);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->posizione()));
        _table->setItem(i, 2, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->chilometraggio()));
        _table->setItem(i, 3, item);

        connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            emit rowClicked(item->row());
        });
    }
}
