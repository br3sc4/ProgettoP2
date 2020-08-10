#include "citieslistview.h"

CitiesListView::CitiesListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent)
    : ViewInterface(parent), _controller(controller), _topBar(new BaseTopBar(title, parent)), _table(new QTableWidget(parent)),
      _deleteButton(new QPushButton("Elimina città", parent)) {
    setupTable(headerStrings);
    setupButton();

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddCityWizard, this, &ViewInterface::showAddCityWizard);
    connect(_topBar, &BaseTopBar::showAddVehicleWizard, this, &ViewInterface::showAddVehicleWizard);
    connect(_table, &QTableWidget::itemSelectionChanged, this, [this]() {
        _deleteButton->setDisabled(false);
    });
    connect(_table, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item) {
        emit rowClicked(item->row());
        _table->clearSelection();
        _deleteButton->setDisabled(true);
    });
    connect(_deleteButton, &QPushButton::clicked, this, [this]() {
        if (_table->selectedItems().size() > 0) {
            emit deleteCityButtonClicked(_table->selectedItems().first()->row());
            _table->clearSelection();
            _deleteButton->setDisabled(true);
        }
    });
}

void CitiesListView::reload() {
    Array<Citta*> cities = _controller->getCities();
    _table->setRowCount(cities.size());

    for (int i = 0; i < _table->rowCount(); i++) {
        _table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(cities[i]->getNome())));
        _table->setItem(i, 1, new QTableWidgetItem(QString::number(cities[i]->getVeicoli().size())));        
    }
}

void CitiesListView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}

QString CitiesListView::title() const {
    return _topBar->title();
}

void CitiesListView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

void CitiesListView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setAlternatingRowColors(true);
    _table->verticalHeader()->hide();
}

void CitiesListView::setupButton() {
    _deleteButton->setMaximumWidth(250);
    _deleteButton->setDisabled(true);
}

void CitiesListView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);
    layout->addWidget(_deleteButton);

    setLayout(layout);
}
