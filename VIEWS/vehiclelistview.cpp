#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller) {}

void VehicleListView::update() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    for (int i = 0; i < _table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 0, item);
        QLabel *icon = new QLabel;
        icon->setPixmap(QPixmap(getIconPath(vehicles[i])));
        _table->setCellWidget(i, 1, icon);
        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->posizione()));
        _table->setItem(i, 2, item);
        item = new QTableWidgetItem(QString::number(vehicles[i]->chilometraggio()));
        _table->setItem(i, 3, item);

        connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            emit rowClicked(item->row());
        });
    }
}

const QString& VehicleListView::getIconPath(Veicolo* const vehicle) {
    QString basePath = ":/icons/";

    if (typeid(vehicle) == typeid(Automobile))
        return basePath += "auto.png";
//    else if (typeid(vehicle) == typeid(AutoIbrida))
//        return basePath += "auto_ibrida.png";
//    else if (typeid(vehicle) == typeid(AutomobileElettrica))
//        return basePath += "auto_elettrica.png";
//    else if (typeid(vehicle) == typeid(Moto))
//        return basePath+= "moto.png";
//    else if (typeid(vehicle) == typeid(MotoElettrica))
//        return basePath += "moto_elettrica.png";
//    else if (typeid(vehicle) == typeid(Bicicletta))
//        return basePath += "bici.png";
//    else
//        return basePath += "monopattino.png";
}
