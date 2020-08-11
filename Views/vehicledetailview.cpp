#include "Views/vehicledetailview.h"

VehicleDetailView::VehicleDetailView(Controller* controller, const QString& title, QWidget *parent):
    ViewInterface(parent), _controller(controller), _verticalLayout(new QVBoxLayout), _gridLayout(new QGridLayout),
    _topBar(new BackTopBar(title, parent)), _checkBox(new QCheckBox("imposta in manutenzione", parent)),
    _moveButton(new QPushButton("Cambia città", parent)), _removeButton(new QPushButton("Rimuovi dalla flotta", parent)) {

    setupMoveButton();
    setupRemoveButton();

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddCityWizard, this, &ViewInterface::showAddCityWizard);
    connect(_topBar, &BaseTopBar::showAddVehicleWizard, this, &ViewInterface::showAddVehicleWizard);
    connect(_topBar, &BackTopBar::backButtonClicked, this, &ViewInterface::backButtonClicked);
    connect(_checkBox, &QCheckBox::stateChanged, this, &VehicleDetailView::maintenanceChanged);
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
    static_cast<QLabel*>(_gridLayout->itemAtPosition(0, 0)->widget())->setText("Posizione: " + QString::fromStdString(vehicle->posizione()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(1, 0)->widget())->setText("Chilometraggio: " + QString::number(vehicle->chilometraggio()) + " km");
    static_cast<QLabel*>(_gridLayout->itemAtPosition(2, 0)->widget())->setText("Consumo al km: " + QString::number(vehicle->consumoKm()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(3, 0)->widget())->setText("Numero posti: " + QString::number(vehicle->capacitaPosti()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(4, 0)->widget())->setText("Ingombro: " + QString::number(vehicle->ingombro()) + " su 5");
    static_cast<QLabel*>(_gridLayout->itemAtPosition(5, 0)->widget())->setText("Numero usi: " + QString::number(vehicle->numeroUsi()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(6, 0)->widget())->setText("Tempo in servizio: " + QString::number(vehicle->tempoServizio()) + " min");
    static_cast<QLabel*>(_gridLayout->itemAtPosition(7, 0)->widget())->setText("Numero guasti: " + QString::number(vehicle->numeroGuasti()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(8, 0)->widget())->setText("Fattore green: " + QString::number(vehicle->fattoreGreen()));
    static_cast<QLabel*>(_gridLayout->itemAtPosition(9, 0)->widget())->setText("Fattore utilizzo: " + QString::number(vehicle->fattoreUtilizzo()) + " su 10");
    static_cast<QLabel*>(_gridLayout->itemAtPosition(10, 0)->widget())->setText("Autonomia: " + QString("%1").arg(vehicle->autonomia(), 0, 'f', 2) + " km");

    vehicle->checkRiserva();
    QLabel* riserva = static_cast<QLabel*>(_gridLayout->itemAtPosition(11, 0)->widget());
    if (vehicle->inRiserva())
        riserva->setText("In riserva: <img src=:/ExtraFiles/Icons/low_fuel.png width=30 height=30> Si");
    else
        riserva->setText("In riserva: <img src=:/ExtraFiles/Icons/normal_fuel.png width=30 height=30> No");
    riserva->setTextFormat(Qt::RichText);

    // Se è stato aperto un altro veicolo prima
    if (_gridLayout->itemAtPosition(1, 1))
        clearDynamicData();

    // Seconda colonna
    Veicolo::StatoVeicolo state = vehicle->statoAttuale();
    const QSignalBlocker blocker(_checkBox);
    _checkBox->setCheckState(state == 3 ? Qt::Checked : Qt::Unchecked);

    QString stato = "Stato: ";
    switch (state) {
        case Veicolo::libero:
            stato += "<img src=:/ExtraFiles/Icons/available.png width=20 height=20> libero";
            _checkBox->setDisabled(false);
            break;
        case Veicolo::prenotato:
            stato += "<img src=:/ExtraFiles/Icons/reserved.png width=20 height=20> prenotato";
            _checkBox->setDisabled(true);
            break;
        case Veicolo::occupato:
            stato += "<img src=:/ExtraFiles/Icons/occupate.png width=20 height=20> occupato";
            _checkBox->setDisabled(true);
            break;
        case Veicolo::manutenzione:
            stato += "<img src=:/ExtraFiles/Icons/manutenzione.png width=20 height=20> manutenzione";
            _checkBox->setDisabled(false);
            break;
    }
    static_cast<QLabel*>(_gridLayout->itemAtPosition(0, 1)->widget())->setText(stato);

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

    _gridLayout->setVerticalSpacing(1);

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
    _gridLayout->addWidget(new QLabel("Stato: "), 0, 1, 1, 1);

    // Terza colonna
    _gridLayout->addWidget(_checkBox, 0, 2, 1, 1);
    _gridLayout->addWidget(_moveButton, 1, 2, 1, 1);
    _gridLayout->addWidget(_removeButton, 2, 2, 1, 1);

    _verticalLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    setLayout(_verticalLayout);
}

void VehicleDetailView::setupMoveButton() {
    QPixmap pixmap(":/ExtraFiles/Icons/change_city.png");
    QIcon buttonIcon(pixmap.scaled(40, 40));
    _moveButton->setIcon(buttonIcon);
    _moveButton->setMaximumWidth(200);
}

void VehicleDetailView::setupRemoveButton() {
    QPixmap pixmap(":/ExtraFiles/Icons/delete.png");
    QIcon buttonIcon(pixmap.scaled(40, 40));
    _removeButton->setIcon(buttonIcon);
    _removeButton->setMaximumWidth(200);
}


void VehicleDetailView::setDynamicData(const Veicolo& veicolo) {
    const MotoreCombustione* combustion = dynamic_cast<const MotoreCombustione*>(&veicolo);
    const MotoreElettrico* electric = dynamic_cast<const MotoreElettrico*>(&veicolo);

    unsigned row = 0;

    if (combustion) {
        _gridLayout->addWidget(new QLabel("Cilindrata: " + QString::number(combustion->cilindrata()) + " cc"), ++row, 1, 1, 1);
        _gridLayout->addWidget(new QLabel("Emissioni CO2: " + QString::number(combustion->emissioni()) + " g/Km"), ++row, 1, 1, 1);

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
        _gridLayout->addWidget(new QLabel(text), ++row, 1, 1, 1);

        _gridLayout->addWidget(new QLabel("Carburante disponibile: " + QString::number(combustion->litriSerbatoio())), ++row, 1, 1, 1);
        _gridLayout->addWidget(new QLabel("Capacità serbatoio: " + QString::number(combustion->capacitaSerbatoio())), ++row, 1, 1, 1);
    }

    if (electric) {
        _gridLayout->addWidget(new QLabel("Carica batteria: " + QString::number(electric->percentualeCarica()) + "%"), ++row, 1, 1, 1);
        _gridLayout->addWidget(new QLabel("Capacità massima batteria: " + QString::number(electric->capacitaBatteria()) + "Ah"), ++row, 1, 1, 1);

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
        _gridLayout->addWidget(new QLabel(text), ++row, 1, 1, 1);

        text = "In carica: ";
        if (electric->inCarica())
            text += "<img src=:/ExtraFiles/Icons/charging.png width=40 height=40>";
        else
            text += "<img src=:/ExtraFiles/Icons/not_charging.png width=40 height=40>";
        QLabel* inCarica = new QLabel(text);
        inCarica->setTextFormat(Qt::RichText);
        _gridLayout->addWidget(inCarica, ++row, 1, 1, 1);

        if (electric->inCarica()){
            text = "Velocità colonnina: ";
            switch(electric->colonninaAttuale()){
                case MotoreElettrico::nessuna:
                    break;
            case MotoreElettrico::lowHome:
                    text += "<img src=:/ExtraFiles/Icons/charger_lvl1.png width=40 height=40> Low Home";
                break;
                case MotoreElettrico::lowPublic:
                    text += "<img src=:/ExtraFiles/Icons/charger_lvl2.png width=40 height=40> Low Public";
                break;
                case MotoreElettrico::medium:
                    text += "<img src=:/ExtraFiles/Icons/charger_lvl3.png width=40 height=40> Medium";
                break;
                case MotoreElettrico::ultraFast:
                    text += "<img src=:/ExtraFiles/Icons/charger_lvl4.png width=40 height=40> Ultra Fast";
                break;
            }
            QLabel* colonnina = new QLabel(text);
            colonnina->setTextFormat(Qt::RichText);
            _gridLayout->addWidget(colonnina, ++row, 1, 1, 1);
        }

        if (electric->inCarica())
            _gridLayout->addWidget(new QLabel("Tempo di carica rimanente: " + QString::number(electric->tempoRimanenteCaricaCompleta()) + " min"), ++row, 1, 1, 1);
    }
}

void VehicleDetailView::clearDynamicData() {
    unsigned row = 1;

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
