#include "electricenginepage.h"

ElectricEnginePage::ElectricEnginePage(QWidget* parent): QWizardPage(parent), _motoriLabel(new QLabel("Numero di motori:")),
    _motoriSpinBox(new QSpinBox), _capacitaLabel(new QLabel("Capacità della batteria:")), _capacitaSpinBox(new QSpinBox),
    _potenzaLabel(new QLabel("Potenza:")), _potenzaSpinBox(new QSpinBox), _caricaLabel(new QLabel("Velocità massima di carica:")),
    _caricaComboBox(new QComboBox) {
    setupMotori();
    setupCapacita();
    setupPotenza();
    setupCarica();

    setupLayout();

    registerField("motori", _motoriSpinBox);
    registerField("capacitaBatteria", _capacitaSpinBox);
    registerField("potenza", _potenzaSpinBox);
    registerField("carica", _caricaComboBox);
}

int ElectricEnginePage::nextId() const {
    return -1;
}

void ElectricEnginePage::setupMotori() {
    _motoriSpinBox->setMinimum(0);
    _motoriSpinBox->setMaximum(8);
    _motoriSpinBox->setKeyboardTracking(false);
    _motoriLabel->setBuddy(_motoriSpinBox);
}

void ElectricEnginePage::setupCapacita() {
    _capacitaSpinBox->setMinimum(0);
    _capacitaSpinBox->setMaximum(100);
    _capacitaSpinBox->setSingleStep(5);
    _capacitaSpinBox->setSuffix(" kWh");
    _capacitaSpinBox->setKeyboardTracking(false);
    _capacitaLabel->setBuddy(_capacitaSpinBox);
}

void ElectricEnginePage::setupPotenza() {
    _potenzaSpinBox->setMinimum(0);
    _potenzaSpinBox->setMaximum(500);
    _potenzaSpinBox->setSingleStep(5);
    _potenzaSpinBox->setSuffix(" kW");
    _potenzaSpinBox->setKeyboardTracking(false);
    _potenzaLabel->setBuddy(_potenzaSpinBox);
}

void ElectricEnginePage::setupCarica() {
    _caricaComboBox->addItems({ "Lenta", "Media", "Veloce"});
    _caricaLabel->setBuddy(_caricaComboBox);
}

void ElectricEnginePage::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_motoriLabel);
    layout->addWidget(_motoriSpinBox);
    layout->addWidget(_capacitaLabel);
    layout->addWidget(_capacitaSpinBox);
    layout->addWidget(_potenzaLabel);
    layout->addWidget(_potenzaSpinBox);
    layout->addWidget(_caricaLabel);
    layout->addWidget(_caricaComboBox);

    setLayout(layout);
}
