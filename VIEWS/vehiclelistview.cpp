#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {
}

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
        item = new QTableWidgetItem(vehicles[i]->serveAssistenza() ? "Si" : "No");
        _table->setItem(i, 2, item);
        vehicles[i]->checkRiserva();
        item = new QTableWidgetItem(vehicles[i]->inRiserva() ? "Si" : "No");
        _table->setItem(i, 3, item);
        item = new QTableWidgetItem(QString("%1").arg(vehicles[i]->autonomia(), 0, 'f', 2));
        _table->setItem(i, 4, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreGreen()));
        _table->setItem(i, 5, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreUtilizzo()));
        _table->setItem(i, 6, item);

        connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            emit rowClicked(item->row());
        });
        _table->setRowHeight(i, 45);
    }    
    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
