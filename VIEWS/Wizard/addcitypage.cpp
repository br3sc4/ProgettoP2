#include "addcitypage.h"

AddCityPage::AddCityPage(QWidget* parent): QWizardPage(parent), _cityLabel(new QLabel("Nome città:")), _cityLineEdit(new QLineEdit) {
    QRegExp re("[A-Z][a-z]+");
    _cityLineEdit->setValidator(new QRegExpValidator(re));
    _cityLineEdit->setPlaceholderText("Es. Milano");
    _cityLabel->setBuddy(_cityLineEdit);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_cityLabel);
    layout->addWidget(_cityLineEdit);

    registerField("cityName", _cityLineEdit);
    setLayout(layout);

    connect(_cityLineEdit, &QLineEdit::textEdited, this, &AddCityPage::completeChanged);

    setTitle("Inserisci il nome della città");
}

bool AddCityPage::isComplete() const {
    return !field("cityName").toString().isEmpty();
}

int AddCityPage::nextId() const {
    return CityWizard::Vehicle_Page;
}
