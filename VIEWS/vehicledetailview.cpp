#include "VIEWS/vehicledetailview.h"

VehicleDetailView::VehicleDetailView(const QString& title, QWidget *parent): VehicleListView(title, parent),
    _checkBox(new QCheckBox("in manutenzione", parent)), _moveButton(new QPushButton("Cambia città", parent)),
    _removeButton(new QPushButton("Rimuovi dalla flotta", parent)) {
    setupTable();
    setupCheckBox();
    setupMoveButton();
    setupRemoveButton();
    _verticalLayout->addSpacerItem(new QSpacerItem(10, 100));
}

VehicleDetailView::~VehicleDetailView() {}

void VehicleDetailView::setupTable() {
    _table->setRowCount(1);
    _table->setFixedHeight(50);
    _table->setHorizontalHeaderLabels({ "Targa", "Tipo", "Stato", "Posizione" });
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);
}

void VehicleDetailView::setupCheckBox() {
    _verticalLayout->addWidget(_checkBox);
}

void VehicleDetailView::setupMoveButton() {
    _moveButton->setMaximumWidth(200);
    _verticalLayout->addWidget(_moveButton);
}

void VehicleDetailView::setupRemoveButton() {
    _removeButton->setMaximumWidth(200);
    _verticalLayout->addWidget(_removeButton);
}
