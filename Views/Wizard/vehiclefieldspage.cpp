#include "vehiclefieldspage.h"

VehicleFieldsPage::VehicleFieldsPage(QWidget* parent): QWizardPage(parent), _targaLabel(new QLabel("Targa:")), _targaLineEdit(new QLineEdit),
    _posizioneLabel(new QLabel("Posizione:")), _posizioneLineEdit(new QLineEdit), _chilometraggioLabel(new QLabel("Chilometraggio:")),
    _chilometraggioSpinBox(new QSpinBox) {
    setupTarga();
    setupPosizione();
    setupKm();    

    registerField("targa", _targaLineEdit);
    registerField("posizione", _posizioneLineEdit);
    registerField("km", _chilometraggioSpinBox);    
    setupLayout();

    connect(_targaLineEdit, &QLineEdit::textEdited, this, &VehicleFieldsPage::completeChanged);
    connect(_posizioneLineEdit, &QLineEdit::textEdited, this, &VehicleFieldsPage::completeChanged);
    connect(_chilometraggioSpinBox, &QSpinBox::editingFinished, this, &VehicleFieldsPage::completeChanged);    

    setTitle("Inserisci i dati generici del veicolo");
}

bool VehicleFieldsPage::isComplete() const {
    return !field("targa").toString().isEmpty() && field("posizione").toString().length() >= 13 && !field("km").toString().isEmpty();
}

int VehicleFieldsPage::nextId() const {
    return CityWizard::SelectEngine_Page;
}

void VehicleFieldsPage::setupTarga() {
    QRegExp targa("[A-Z, 0-9]{4,7}");
    _targaLineEdit->setValidator(new QRegExpValidator(targa));
    _targaLineEdit->setPlaceholderText("Es. AB123CD");
    _targaLabel->setBuddy(_targaLineEdit);
}

void VehicleFieldsPage::setupPosizione() {
    QRegExp pos("\\-?[0-9]{1,3}\\.[0-9]{4}\\,\\s?\\-?[0-9]{1,3}\\.[0-9]{4}");
    _posizioneLineEdit->setValidator(new QRegExpValidator(pos));
    _posizioneLineEdit->setPlaceholderText("Es. 41.40338, 2.17403");
    _posizioneLabel->setBuddy(_posizioneLineEdit);
}

void VehicleFieldsPage::setupKm() {
    _chilometraggioSpinBox->setSingleStep(50);
    _chilometraggioSpinBox->setMaximum(500000);
    _chilometraggioSpinBox->setMinimum(0);
    _chilometraggioSpinBox->setGroupSeparatorShown(true);
    _chilometraggioLabel->setBuddy(_chilometraggioSpinBox);
}

void VehicleFieldsPage::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_targaLabel);
    layout->addWidget(_targaLineEdit);
    layout->addWidget(_posizioneLabel);
    layout->addWidget(_posizioneLineEdit);
    layout->addWidget(_chilometraggioLabel);
    layout->addWidget(_chilometraggioSpinBox);    

    setLayout(layout);
}
