#include "citieslistview.h"

CitiesListView::CitiesListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent)
    : ViewInterface(parent), _controller(controller), _topBar(new BaseTopBar(title, parent)), _table(new QTableWidget(parent)) {
    setupTable(headerStrings);

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddCityWizard, this, &ViewInterface::showAddCityWizard);
    connect(_topBar, &BaseTopBar::showAddVehicleWizard, this, &ViewInterface::showAddVehicleWizard);
    connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {        
        emit rowClicked(item->row());
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

void CitiesListView::resetTableSelection() {
    _table->clearSelection();
}

QString CitiesListView::title() const {
    return _topBar->title();
}

void CitiesListView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

QTableWidget* CitiesListView::table() {
    return _table;
}

void CitiesListView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setAlternatingRowColors(true);
    _table->verticalHeader()->hide();
}

void CitiesListView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);

    setLayout(layout);
}
