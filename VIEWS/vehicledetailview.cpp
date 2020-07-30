#include "VIEWS/vehicledetailview.h"

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

    _verticalLayout->addSpacerItem(new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    connect(_checkBox, SIGNAL(stateChanged(int)), this, SIGNAL(maintenanceChanged(int)));
    connect(_moveButton, SIGNAL(clicked()), this, SIGNAL(createMoveDialog()));
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

    QLabel *icon = new QLabel;
    QPixmap* pixmap = new QPixmap(getIconPath(*vehicle));
    icon->setPixmap(pixmap->scaled(40, 40, Qt::KeepAspectRatio));
    _table->setCellWidget(0, 0, icon);
    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(vehicle->targa()));
    _table->setItem(0, 1, item);
    item = new QTableWidgetItem(QString::fromStdString(vehicle->posizione()));
    _table->setItem(0, 2, item);
    item = new QTableWidgetItem(QString::number(vehicle->chilometraggio()));
    _table->setItem(0, 3, item);
    item = new QTableWidgetItem(QString::number(vehicle->consumoKm()));
    _table->setItem(0, 4, item);
    item = new QTableWidgetItem(QString::number(vehicle->fattoreGreen()));
    _table->setItem(0, 5, item);
    item = new QTableWidgetItem(QString::number(vehicle->autonomia()));
    _table->setItem(0, 6, item);
    item = new QTableWidgetItem(QString::number(vehicle->fattoreUtilizzo()));
    _table->setItem(0, 7, item);
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

void VehicleDetailView::setDynamicData(const Veicolo& veicolo) {
    if (typeid(veicolo) == typeid(MotoreCombustione)) {
        // carburante, cilindrata, emissioni CO2
        const MotoreCombustione* combustion = dynamic_cast<const MotoreCombustione*>(&veicolo);
        _table->setHorizontalHeaderItem(8, new QTableWidgetItem("Cilindrata"));
        _table->setItem(0, 8, new QTableWidgetItem(QString::number(combustion->cilindrata())));
        _table->setHorizontalHeaderItem(9, new QTableWidgetItem("Emissioni CO_2"));
        _table->setItem(0, 9, new QTableWidgetItem(QString::number(combustion->emissioni())));
    }
}

void VehicleDetailView::createMoveDialog(const std::string& currentCity) {
    QDialog* modal = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(modal);

    QLabel* title = new QLabel("<h1>Move vehicle</h1>");
    title->setTextFormat(Qt::RichText);

    Array<Citta*> cities = _controller->getCities();
    QTableWidget* table = new QTableWidget;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->verticalHeader()->hide();
    table->setColumnCount(1);
    table->setHorizontalHeaderLabels({ "Nome" });
    QHeaderView *header = table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
    table->setRowCount(cities.size());
    for (int i = 0; i < table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(cities[i]->getNome()));

        table->setItem(i, 0, item);
        item->setSelected(cities[i]->getNome() == currentCity);
    }

    QDialogButtonBox* buttons = new QDialogButtonBox;
    buttons->setStandardButtons(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    buttons->setOrientation(Qt::Horizontal);

    connect(buttons, &QDialogButtonBox::rejected, modal, &QDialog::reject);
    connect(buttons, &QDialogButtonBox::accepted, this, [=]() {
        emit vehicleMove(table->selectedItems().first()->row());
    });
    connect(buttons, &QDialogButtonBox::accepted, modal, &QDialog::accept);

    layout->addWidget(title);
    layout->addWidget(table);
    layout->addWidget(buttons);

    modal->setModal(true);
    modal->setLayout(layout);
    modal->show();
    modal->activateWindow();
}
