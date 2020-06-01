#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(const QString& title, QWidget *parent): BaseView(title, parent), _backButton(new QPushButton("Back", parent)) {
    setupBackButton();
    setupTable();

    connect(_backButton, SIGNAL(clicked()), this, SIGNAL(backButtonClicked()));
}

VehicleListView::~VehicleListView() {}

void VehicleListView::setupTable() {
    _table->setRowCount(1);
    _table->setHorizontalHeaderLabels({ "Targa", "Tipo veicolo", "Disponibilità", "Veicolo in uso" });
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);

    // TODO: integrate controller
    for (int i = 0; i < _table->rowCount(); i++) {
        for (int j = 0; j < _table->columnCount(); j++) {
            connect(_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectRow(QTableWidgetItem*)));
            connect(_table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SIGNAL(selectedVehicle(QTableWidgetItem*)));
        }
    }
}

void VehicleListView::setupBackButton() {
    _backButton->setMaximumWidth(200);
    _horizontalLayout->addWidget(_backButton);
}
