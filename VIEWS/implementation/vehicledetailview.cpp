#include "VIEWS/header/vehicledetailview.h"

VehicleDetailView::VehicleDetailView(const QString& title, QWidget *parent): VehicleListView(title, parent) {
    setupTable();
}

VehicleDetailView::~VehicleDetailView() {}

void VehicleDetailView::setupTable() {
    _table->setRowCount(1);
    _table->setHorizontalHeaderLabels({ "Targa", "Tipo", "Stato", "Posizione" });
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);
}
