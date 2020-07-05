#include "selectenginepage.h"

SelectEnginePage::SelectEnginePage(QWidget *parent) : QWizardPage(parent), _postiLabel(new QLabel("Numero posti:")),
    _postiSpinBox(new QSpinBox), _ingombroLabel(new QLabel("Ingombro veicolo:")), _ingombroSpinBox(new QSpinBox),
    _tipoMotoreLabel(new QLabel("Tipo motore:")), _tipoMotoreComboBox(new QComboBox), _tipoVeicoloLabel(new QLabel("Tipo veicolo:")),
    _tipoVeicoloComboBox(new QComboBox),  _combustione({ "Automobile", "Moto" }),
    _elettrico({ "Automobile elettrica", "Moto elettrica", "Bicicletta", "Monopattino" }), _ibrido({ "Automobile ibrida" }) {
    setupPosti();
    setupIngombro();
    setupMotore();
    setupVeicolo();

    registerField("posti", _postiSpinBox);
    registerField("ingombro", _ingombroSpinBox);
    registerField("tipoMotore", _tipoMotoreComboBox);
    registerField("tipoVeicolo", _tipoVeicoloComboBox);

    setupLayout();

    connect(_tipoMotoreComboBox, &QComboBox::currentTextChanged, this, &SelectEnginePage::changeTipoVeicoloLabels);
}

int SelectEnginePage::nextId() const {
    if (field("tipoMotore").toUInt() == Engines::CombustionEngine || field("tipoMotore").toUInt() == Engines::HybridEngine)
        return CityWizard::ComustionEngine_Page;
    else
        return CityWizard::ElectricEngine_Page;
}

void SelectEnginePage::setupPosti() {
    _postiSpinBox->setMinimum(1);
    _postiSpinBox->setMaximum(9);
    _postiLabel->setBuddy(_postiSpinBox);
}

void SelectEnginePage::setupIngombro() {
    _ingombroSpinBox->setMinimum(1);
    _ingombroSpinBox->setMaximum(5);
    _ingombroLabel->setBuddy(_ingombroSpinBox);
}

void SelectEnginePage::setupMotore() {
    _tipoMotoreComboBox->addItems({ "Combustione", "Elettrico", "Ibrido" });
    _tipoMotoreLabel->setBuddy(_tipoMotoreComboBox);
}

void SelectEnginePage::setupVeicolo() {
    _tipoVeicoloComboBox->addItems(_combustione);
    _tipoVeicoloLabel->setBuddy(_tipoVeicoloComboBox);
}

void SelectEnginePage::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_postiLabel);
    layout->addWidget(_postiSpinBox);
    layout->addWidget(_ingombroLabel);
    layout->addWidget(_ingombroSpinBox);
    layout->addWidget(_tipoMotoreLabel);
    layout->addWidget(_tipoMotoreComboBox);
    layout->addWidget(_tipoVeicoloLabel);
    layout->addWidget(_tipoVeicoloComboBox);

    setLayout(layout);
}

void SelectEnginePage::changeTipoVeicoloLabels(const QString& text) {
    int items = _tipoVeicoloComboBox->count();
    for (int i = 0; i < items; i++)
        _tipoVeicoloComboBox->removeItem(0);

    if (text == "Combustione")
        _tipoVeicoloComboBox->addItems(_combustione);
    else if (text == "Elettrico")
        _tipoVeicoloComboBox->addItems(_elettrico);
    else
        _tipoVeicoloComboBox->addItems(_ibrido);
}
