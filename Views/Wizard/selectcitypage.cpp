#include "selectcitypage.h"

SelectCityPage::SelectCityPage(QWidget* parent): QWizardPage(parent), _vehiclesLabel(new QLabel("Lista città:")),
    _vehiclesList(new QTableWidget) {
    setupTable();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_vehiclesLabel);
    layout->addWidget(_vehiclesList);

    setLayout(layout);
}

bool SelectCityPage::isComplete() const {
    return !_vehiclesList->selectedItems().isEmpty();
}

int SelectCityPage::nextId() const {
    return CityWizard::Vehicle_Page;
}

void SelectCityPage::initializePage() {
    CityWizard* cityWizard = static_cast<CityWizard*>(wizard());
    Array<Citta*> cities = cityWizard->getCities();
    _vehiclesList->setRowCount(cities.size());

    for (int i = 0; i < _vehiclesList->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(cities[i]->getNome()));
        _vehiclesList->setItem(i, 0, item);

        connect(_vehiclesList, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {
            cityWizard->setCity(item->row());
            emit completeChanged();
        });
    }
}

void SelectCityPage::setupTable() {
    _vehiclesList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _vehiclesList->setSelectionBehavior(QAbstractItemView::SelectRows);
    _vehiclesList->setSelectionMode(QAbstractItemView::SingleSelection);
    _vehiclesList->verticalHeader()->hide();
    _vehiclesList->setColumnCount(1);
    _vehiclesList->setHorizontalHeaderLabels({ "Nome" });
    QHeaderView* header = _vehiclesList->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}
