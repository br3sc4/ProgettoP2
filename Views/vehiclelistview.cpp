#include "Views/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    ViewInterface(parent), _controller(controller), _topBar(new BackTopBar(title, parent)), _table(new QTableWidget(parent)), _order(Qt::SortOrder::AscendingOrder) {
    setupTable(headerStrings);

    setupLayout();

    connect(_topBar, &BaseTopBar::closeSignal, this, &ViewInterface::closeSignal);
    connect(_topBar, &BaseTopBar::showAddCityWizard, this, &ViewInterface::showAddCityWizard);
    connect(_topBar, &BaseTopBar::showAddVehicleWizard, this, &ViewInterface::showAddVehicleWizard);
    connect(_topBar, &BackTopBar::backButtonClicked, this, [=]() {
        emit backButtonClicked();
        _order = Qt::SortOrder::DescendingOrder;
        QHeaderView* header = _table->horizontalHeader();
        const QSignalBlocker blocker(header);
        header->setSortIndicator(2, _order);
    });
    connect(_table, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item) {
        emit rowClicked(item->row());
        _table->clearSelection();
    });
    connect(_table->horizontalHeader(), &QHeaderView::sortIndicatorChanged, this, [=](int index, Qt::SortOrder order) {                
        if (index != 2) {            
            QHeaderView* header = _table->horizontalHeader();
            const QSignalBlocker blocker(header);
            header->setSortIndicator(2, _order);
        } else {
            _order = order;
            _table->sortItems(index, _order);
            emit sort(order == Qt::SortOrder::AscendingOrder);
        }
    });
}

void VehicleListView::reload() {
    Array<Veicolo*> vehicles = _controller->getVehicles();
    _table->setRowCount(vehicles.size());
    _table->clearSelection();

    for (int i = 0; i < _table->rowCount(); i++) {
        QPixmap* pixmap = new QPixmap(getIconPath(*vehicles[i]));

        QTableWidgetItem *item = new QTableWidgetItem();
        item->setData(Qt::DecorationRole, pixmap->scaled(50, 50));
        item->setTextAlignment(Qt::AlignCenter);
        _table->setItem(i, 0, item);

        item = new QTableWidgetItem(QString::fromStdString(vehicles[i]->targa()));
        _table->setItem(i, 1, item);

        item = new StateTableItem(vehicles[i]->statoAttuale());
        _table->setItem(i, 2, item);

        int hIcon = 30, wIcon = 30;

        QPixmap* low = new QPixmap(":/ExtraFiles/Icons/low_fuel.png");
        QPixmap* normal = new QPixmap(":/ExtraFiles/Icons/normal_fuel.png");
        QPixmap* help = new QPixmap(":/ExtraFiles/Icons/help.png");
        QPixmap* ok = new QPixmap(":/ExtraFiles/Icons/available.png");

        item = new QTableWidgetItem();
        if(vehicles[i]->serveAssistenza()) {
            item->setData(Qt::DecorationRole, help->scaled(hIcon, wIcon));
            item->setText(" Problema");
         } else {
            item->setData(Qt::DecorationRole, ok->scaled(hIcon, wIcon));
            item->setText(" Tutto ok");
        }
        _table->setItem(i, 3, item);

        vehicles[i]->checkRiserva();
        item = new QTableWidgetItem();
        if(vehicles[i]->inRiserva()) {
            item->setData(Qt::DecorationRole, low->scaled(hIcon, wIcon));
            item->setText(" Si");
        } else {
            item->setData(Qt::DecorationRole, normal->scaled(hIcon, wIcon));
            item->setText(" No");
        }
        _table->setItem(i, 4, item);

        item = new QTableWidgetItem(QString("%1").arg(vehicles[i]->autonomia(), 0, 'f', 2) + " km");
        item->setTextAlignment(Qt::AlignCenter);
        _table->setItem(i, 5, item);

        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreGreen()));
        if(vehicles[i]->fattoreGreen() >= 0) item->setTextColor("#52AE49");
        else item->setTextColor("#E6212B");
        item->setTextAlignment(Qt::AlignCenter);

        _table->setItem(i, 6, item);

        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreUtilizzo()) + "/10");
        item->setTextAlignment(Qt::AlignCenter);
        _table->setItem(i, 7, item);

        _table->setRowHeight(i, 60);
    }

    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    _order = Qt::SortOrder::AscendingOrder;
    _table->horizontalHeader()->setSortIndicator(2, _order);
    _table->scrollToTop();
}

void VehicleListView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);    
    header->setSortIndicator(2, _order);
    header->setSortIndicatorShown(true);
}

QString VehicleListView::title() const {
    return _topBar->title();
}

void VehicleListView::setTitle(const QString &title) {
    _topBar->setTitle(title);
}

void VehicleListView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->setAlternatingRowColors(true);

    _table->verticalHeader()->hide();
}

void VehicleListView::setupLayout() {
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(_topBar);
    layout->addWidget(_table);

    setLayout(layout);
}

const QString VehicleListView::getIconPath(const Veicolo& vehicle) const {
    QString basePath = ":/ExtraFiles/Icons/";

    if (typeid(vehicle) == typeid(Automobile))
        return basePath + "auto.png";
    else if (typeid(vehicle) == typeid(AutoIbrida))
        return basePath + "auto_ibrida.png";
    else if (typeid(vehicle) == typeid(AutomobileElettrica))
        return basePath + "auto_elettrica.png";
    else if (typeid(vehicle) == typeid(Moto))
        return basePath + "moto.png";
    else if (typeid(vehicle) == typeid(MotoElettrica))
        return basePath + "moto_elettrica.png";
    else if (typeid(vehicle) == typeid(Bicicletta))
        return basePath + "bici.png";
    else
        return basePath + "monopattino.png";
}
