#include "combustionenginepage.h"

CombustionEnginePage::CombustionEnginePage(QWidget* parent): QWizardPage(parent), _cilindrataLabel(new QLabel("Cilindrata:")),
    _cilindrataSpinBox(new QSpinBox), _capacitaLabel(new QLabel("Capacità serbatoio:")), _capacitaSpinBox(new QSpinBox),
    _emissioniLabel(new QLabel("Emissioni:")), _emissioniSpinBox(new QDoubleSpinBox), _carburanteLabel(new QLabel("Carburante:")),
    _carburanteComboBox(new QComboBox) {
    setupCilindrata();
    setupCapacita();
    setupEmissioni();
    setupCarburante();

    setupLayout();

    registerField("cilindrata", _cilindrataSpinBox);
    registerField("capacità", _capacitaSpinBox);
    registerField("emissioni", _emissioniSpinBox);
    registerField("carburante", _carburanteComboBox);
}

int CombustionEnginePage::nextId() const {
    if (field("tipoMotore").toUInt() == SelectEnginePage::Engines::HybridEngine)
        return CityWizard::ElectricEngine_Page;
    return -1;
}


void CombustionEnginePage::setupCilindrata() {
    _cilindrataSpinBox->setMinimum(1000);
    _cilindrataSpinBox->setMaximum(4000);
    _cilindrataSpinBox->setSingleStep(100);
    _cilindrataSpinBox->setGroupSeparatorShown(true);
    _cilindrataSpinBox->setKeyboardTracking(false);
    _cilindrataLabel->setBuddy(_cilindrataSpinBox);
}

void CombustionEnginePage::setupCapacita() {
    _capacitaSpinBox->setMinimum(10);
    _capacitaSpinBox->setMaximum(100);
    _capacitaSpinBox->setSingleStep(5);
    _capacitaSpinBox->setKeyboardTracking(false);
    _capacitaLabel->setBuddy(_capacitaSpinBox);
}

void CombustionEnginePage::setupEmissioni() {
    _emissioniSpinBox->setDecimals(1);
    _emissioniSpinBox->setSingleStep(0.5);
    _emissioniSpinBox->setKeyboardTracking(false);
    _emissioniLabel->setBuddy(_emissioniSpinBox);
}

void CombustionEnginePage::setupCarburante() {
    _carburanteComboBox->addItems({ "Benzina", "Diesel", "GPL", "Metano" });
    _carburanteLabel->setBuddy(_carburanteComboBox);
}

void CombustionEnginePage::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_cilindrataLabel);
    layout->addWidget(_cilindrataSpinBox);
    layout->addWidget(_capacitaLabel);
    layout->addWidget(_capacitaSpinBox);
    layout->addWidget(_emissioniLabel);
    layout->addWidget(_emissioniSpinBox);
    layout->addWidget(_carburanteLabel);
    layout->addWidget(_carburanteComboBox);

    setLayout(layout);
}
