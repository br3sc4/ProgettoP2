#include "VIEWS/vehicledetailview.h"

#include <QScrollBar>

VehicleDetailView::VehicleDetailView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent), _controller(controller), _checkBox(new QCheckBox("in manutenzione", parent)),
    _moveButton(new QPushButton("Cambia città", parent)), _removeButton(new QPushButton("Rimuovi dalla flotta", parent)) {
    _table->setFixedHeight(52);
    _table->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
    _table->verticalScrollBar()->setDisabled(true);
    _table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setupCheckBox();
    setupMoveButton();
    setupRemoveButton();
    _verticalLayout->addSpacerItem(new QSpacerItem(10, 100));
    setMinimumSize(600, 400);

    connect(_checkBox, SIGNAL(stateChanged(int)), this, SIGNAL(maintenanceChanged(int)));
    connect(_removeButton, SIGNAL(clicked()), this, SIGNAL(removeButtonClicked()));
}

VehicleDetailView::~VehicleDetailView() {
    delete _removeButton;
    delete _moveButton;
    delete _checkBox;
}

void VehicleDetailView::update() {
    Veicolo* vehicle = _controller->getVehicle();
    _table->setRowCount(1);

    _checkBox->setChecked(vehicle->serveAssistenza());

    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicle->targa()));
    _table->setItem(0, 0, item);
    item = new QTableWidgetItem(QString::fromStdString(vehicle->posizione()));
    _table->setItem(0, 1, item);
    item = new QTableWidgetItem(QString::number(vehicle->chilometraggio()));
    _table->setItem(0, 2, item);

    _table->resizeColumnsToContents();
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
