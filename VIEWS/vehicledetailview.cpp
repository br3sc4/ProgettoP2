#include "VIEWS/vehicledetailview.h"

VehicleDetailView::VehicleDetailView(Controller* controller, const QString& title, QWidget *parent):
    ViewInterface(parent), _controller(controller), _verticalLayout(new QVBoxLayout), _gridLayout(new QGridLayout),
    _topBar(new BackTopBar(title, parent)), _checkBox(new QCheckBox("imposta in manutenzione", parent)),
    _moveButton(new QPushButton("Cambia città", parent)), _removeButton(new QPushButton("Rimuovi dalla flotta", parent)) {

    setupMoveButton();
    setupRemoveButton();

    setupLayout();

    connect(_topBar, &BackTopBar::backButtonClicked, this, &ViewInterface::backButtonClicked);
    connect(_checkBox, SIGNAL(stateChanged(int)), this, SIGNAL(maintenanceChanged(int)));
    connect(_moveButton, SIGNAL(clicked()), this, SIGNAL(createMoveDialog()));
    connect(_removeButton, SIGNAL(clicked()), this, SIGNAL(removeButtonClicked()));
}

VehicleDetailView::~VehicleDetailView() {
    delete _removeButton;
    delete _moveButton;
    delete _checkBox;
}

void VehicleDetailView::reload() {
    Veicolo* vehicle = _controller->getVehicle();

    // Prima colonna
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(0, 0)->widget())->setText("Posizione: " + QString::fromStdString(vehicle->posizione()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(1, 0)->widget())->setText("Chilometraggio: " + QString::number(vehicle->chilometraggio()) + " km");
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(2, 0)->widget())->setText("Consumo al km: " + QString::number(vehicle->consumoKm()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(3, 0)->widget())->setText("Numero posti: " + QString::number(vehicle->capacitaPosti()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(4, 0)->widget())->setText("Ingombro: " + QString::number(vehicle->ingombro()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(5, 0)->widget())->setText("Numero usi: " + QString::number(vehicle->numeroUsi()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(6, 0)->widget())->setText("Tempo in servizio: " + QString::number(vehicle->tempoServizio()) + " min");
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(7, 0)->widget())->setText("Numero guasti: " + QString::number(vehicle->numeroGuasti()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(8, 0)->widget())->setText("Fattore green: " + QString::number(vehicle->fattoreGreen()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(9, 0)->widget())->setText("Fattore utilizzo: " + QString::number(vehicle->fattoreUtilizzo()));
    dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(10, 0)->widget())->setText("Autonomia: " + QString("%1").arg(vehicle->autonomia(), 0, 'f', 2));

    vehicle->checkRiserva();
    QLabel* riserva = static_cast<QLabel*>(_gridLayout->itemAtPosition(11, 0)->widget());
    if (vehicle->inRiserva())
        riserva->setText("In riserva: <img src=:/icons/true.png width=20 height=20>");
    else
        riserva->setText("In riserva: <img src=:/icons/false.png width=20 height=20>");
    riserva->setTextFormat(Qt::RichText);

    if (_gridLayout->itemAtPosition(0, 1))
        clearDynamicData();

    // Seconda colonna
    setDynamicData(*vehicle);
}

QString VehicleDetailView::title() const {
    return _topBar->title();
}

void VehicleDetailView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

void VehicleDetailView::setupLayout() {    
    _verticalLayout->addWidget(_topBar);
    _verticalLayout->addLayout(_gridLayout);

    // Prima colonna
    _gridLayout->addWidget(new QLabel("Posizione: "), 0, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Chilometraggio: "), 1, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Consumo al km: "), 2, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Numero posti: "), 3, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Ingombro: "), 4, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Numero usi: "), 5, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Tempo in servizio: "), 6, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Numero guasti: "), 7, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Fattore green: "), 8, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Fattore di utilizzo: "), 9, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("Autonomia: "), 10, 0, 1, 1);
    _gridLayout->addWidget(new QLabel("In riserva: "), 11, 0, 1, 1);

    // Seconda colonna
    _gridLayout->addWidget(_checkBox, 0, 1, 1, 2);
    _gridLayout->addWidget(_moveButton, 1, 1, 1, 2);
    _gridLayout->addWidget(_removeButton, 2, 1, 1, 2);

    _verticalLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    setLayout(_verticalLayout);
}

void VehicleDetailView::setupMoveButton() {
    QPixmap pixmap1(":/icons/change_city.png");
    QIcon ButtonIcon1(pixmap1.scaled(40, 40));
    _moveButton->setIcon(ButtonIcon1);
    _moveButton->setMaximumWidth(200);
}

void VehicleDetailView::setupRemoveButton() {
    QPixmap pixmap2(":/icons/delete.png");
    QIcon ButtonIcon2(pixmap2.scaled(40, 40));
    _removeButton->setIcon(ButtonIcon2);
    _removeButton->setMaximumWidth(200);
}


void VehicleDetailView::setDynamicData(const Veicolo& veicolo) {
    const MotoreCombustione* combustion = dynamic_cast<const MotoreCombustione*>(&veicolo);
    const MotoreElettrico* electric = dynamic_cast<const MotoreElettrico*>(&veicolo);

    unsigned row = 2;

    QString stato = "stato: ";
    switch(veicolo.statoAttuale()){
        case Veicolo::libero:
        stato += "<img src=:/icons/available.png width=40 height=40>";
        break;
        case Veicolo::prenotato:
        stato += "<img src=:/icons/reserved.png width=40 height=40>";
        break;
        case Veicolo::occupato:
        stato += "<img src=:/icons/occupate.png width=40 height=40>";
        break;
        case Veicolo::manutenzione:
        stato += "<img src=:/icons/manutenzione.png width=40 height=40>";
        break;
    }
    _gridLayout->addWidget(new QLabel(stato), ++row, 1);

    if (combustion) {
        _gridLayout->addWidget(new QLabel("Cilindrata: " + QString::number(combustion->cilindrata())), ++row, 1, 1, 2);
        _gridLayout->addWidget(new QLabel("Emissioni CO_2: " + QString::number(combustion->emissioni())), ++row, 1, 1, 2);

        QString text = "Carburante: ";
        switch (combustion->tipoCarburante()) {
        case MotoreCombustione::gpl:
            text += "GPL";
            break;
        case MotoreCombustione::metano:
            text += "Metano";
            break;
        case MotoreCombustione::diesel:
            text += "Diesel";
            break;
        default:
            text += "Benzina";
            break;
        }
        _gridLayout->addWidget(new QLabel(text), ++row, 1, 1, 2);

        _gridLayout->addWidget(new QLabel("Carburante disponibile: " + QString::number(combustion->litriSerbatoio())), ++row, 1, 1, 2);
        _gridLayout->addWidget(new QLabel("Capacità serbatoio: " + QString::number(combustion->capacitaSerbatoio())), ++row, 1, 1, 2);
    }

    if (electric) {
        _gridLayout->addWidget(new QLabel("Percentuale batteria: " + QString::number(electric->percentualeCarica())), ++row, 1, 1, 2);
        _gridLayout->addWidget(new QLabel("Capacità batteria: " + QString::number(electric->capacitaBatteria())), ++row, 1, 1, 2);

        QString text = "Velocità di carica supportata: ";
        switch (electric->caricaSupportata()) {
        case MotoreElettrico::lenta:
            text += "Lenta";
            break;
        case MotoreElettrico::media:
            text += "Media";
            break;
        default:
            text += "Veloce";
            break;
        }
        _gridLayout->addWidget(new QLabel(text), ++row, 1, 1, 2);

        text = "In carica: ";
        if (electric->inCarica()){
            text += "<img src=:/icons/charging.png width=40 height=40>";

        }else
            text += "<img src=:/icons/not_charging.png width=40 height=40>";
        QLabel* inCarica = new QLabel(text);
        inCarica->setTextFormat(Qt::RichText);
        _gridLayout->addWidget(inCarica, ++row, 1, 1, 2);

        if (electric->inCarica()){
            text = "Colonnina in uso: ";
            switch(electric->colonninaAttuale()){
                case MotoreElettrico::nessuna:
                    break;
            case MotoreElettrico::lowHome:
                    text += "<img src=:/icons/charger_lvl1.png width=40 height=40>";
                break;
                case MotoreElettrico::lowPublic:
                    text += "<img src=:/icons/charger_lvl2.png width=40 height=40>";
                break;
                case MotoreElettrico::medium:
                    text += "<img src=:/icons/charger_lvl3.png width=40 height=40>";
                break;
                case MotoreElettrico::ultraFast:
                    text += "<img src=:/icons/charger_lvl4.png width=40 height=40>";
                break;
            }
            QLabel* colonnina = new QLabel(text);
            colonnina->setTextFormat(Qt::RichText);
            _gridLayout->addWidget(colonnina, ++row, 1);
        }

        if (electric->inCarica())
            _gridLayout->addWidget(new QLabel("Tempo di carica rimanente: " + QString::number(electric->tempoRimanenteCaricaCompleta())), ++row, 1, 1, 2);
    }
}

void VehicleDetailView::clearDynamicData() {
    unsigned row = 0;

    do {
        QLabel* label = dynamic_cast<QLabel*>(_gridLayout->itemAtPosition(row, 1)->widget());
        _gridLayout->removeWidget(label);
        delete label;
        ++row;
    } while (_gridLayout->itemAtPosition(row, 1));
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
