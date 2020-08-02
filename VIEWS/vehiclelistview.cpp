#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {
}

void VehicleListView::update() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    QPixmap* si = new QPixmap(":/icons/true.png");
    QPixmap* no = new QPixmap(":/icons/false.png");

    for (int i = 0; i < _table->rowCount(); i++) {
        QPixmap* pixmap = new QPixmap(getIconPath(*vehicles[i]));
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::DecorationRole, pixmap->scaled(50, 50, Qt::KeepAspectRatio));
        _table->setItem(i, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 1, item);
        item = new QTableWidgetItem();
        if(vehicles[i]->serveAssistenza())
            item->setData(Qt::DecorationRole, si->scaled(20, 20, Qt::KeepAspectRatio));
         else
            item->setData(Qt::DecorationRole, no->scaled(20, 20, Qt::KeepAspectRatio));
        _table->setItem(i, 2, item);
        vehicles[i]->checkRiserva();
        item = new QTableWidgetItem();
        if(vehicles[i]->inRiserva())
            item->setData(Qt::DecorationRole, si->scaled(20, 20, Qt::KeepAspectRatio));
         else
            item->setData(Qt::DecorationRole, no->scaled(20, 20, Qt::KeepAspectRatio));
        //item = new QTableWidgetItem(vehicles[i]->inRiserva() ? "Si" : "No");
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
        _table->setRowHeight(i, 60);
    }
    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
