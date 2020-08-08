#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(Controller* controller, const QString& title, const QStringList& headerStrings, QWidget *parent):
    ViewInterface(parent), _controller(controller), _topBar(new BackTopBar(title, parent)), _table(new QTableWidget(parent)) {
    setupTable(headerStrings);

    setupLayout();

    connect(_topBar, &BackTopBar::backButtonClicked, this, &ViewInterface::backButtonClicked);
    connect(_table, &QTableWidget::itemClicked, this, [=](QTableWidgetItem* item) {        
        emit rowClicked(item->row());
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

        item = new QTableWidgetItem();
        Veicolo::StatoVeicolo stato = vehicles[i]->statoAttuale();
        QPixmap* iconaStato;
        switch (stato) {
            case Veicolo::libero:
                iconaStato = new QPixmap(":/icons/available.png");
                item->setText(" Libero");
                break;
            case Veicolo::prenotato:
                iconaStato = new QPixmap(":/icons/reserved.png");
                item->setText(" Prenotato");
                break;
            case Veicolo::occupato:
                iconaStato = new QPixmap(":/icons/occupate.png");
                item->setText(" Occupato");
                break;
            case Veicolo::manutenzione:
                iconaStato = new QPixmap(":/icons/manutenzione.png");
                item->setText(" Manutenzione");
                break;
        }
        item->setData(Qt::DecorationRole, iconaStato->scaled(30, 30));
        _table->setItem(i, 2, item);

        int hIcon = 30, wIcon = 30;

        QPixmap* si = new QPixmap(":/icons/true.png");
        QPixmap* no = new QPixmap(":/icons/false.png");
        QPixmap* help = new QPixmap(":/icons/help.png");
        QPixmap* ok = new QPixmap(":/icons/available.png");


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
        if(vehicles[i]->inRiserva())
            item->setData(Qt::DecorationRole, si->scaled(hIcon, wIcon));
         else
            item->setData(Qt::DecorationRole, no->scaled(hIcon, wIcon));
        _table->setItem(i, 4, item);

        item = new QTableWidgetItem(QString("%1").arg(vehicles[i]->autonomia(), 0, 'f', 2));
        _table->setItem(i, 5, item);

        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreGreen()));
        _table->setItem(i, 6, item);

        item = new QTableWidgetItem(QString::number(vehicles[i]->fattoreUtilizzo()));
        _table->setItem(i, 7, item);

        _table->setRowHeight(i, 60);
    }
    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    
}

void VehicleListView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}

void VehicleListView::resetTableSelection() {
    _table->clearSelection();
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
    QString basePath = ":/icons/";

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
