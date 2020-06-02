#include "VIEWS/baseview.h"

BaseView::BaseView(const QString& title, QWidget *parent): QWidget(parent), _title(new QLabel(this)), _table(new QTableWidget(this)),
    _verticalLayout(new QVBoxLayout), _horizontalLayout(new QHBoxLayout) {
    setupLayout();
    setupLabel(title);
    setupTable();

    setLayout(_verticalLayout);
}

BaseView::~BaseView() {}

void BaseView::setupLayout() {
    _verticalLayout->insertLayout(0, _horizontalLayout);
    _verticalLayout->setAlignment(Qt::AlignLeft);
}

void BaseView::setupLabel(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
    _title->setTextFormat(Qt::RichText);
    _horizontalLayout->addWidget(_title);
}

void BaseView::setupTable() {
    _table->setRowCount(2);
    _table->setColumnCount(4);
    _table->setHorizontalHeaderLabels({ "Nome città", "Veicoli", "Veicoli in manutenzione", "Veicoli in uso" });
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);
    header->setStretchLastSection(true);

    // TODO: integrate controller
    for (int i = 0; i < _table->rowCount(); i++) {
        for (int j = 0; j < _table->columnCount(); j++) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(i) + " " + QString::number(j));
            _table->setItem(i, j, item);

            connect(_table, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectRow(QTableWidgetItem*)));
            connect(_table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SIGNAL(selectedCity(QTableWidgetItem*)));
        }
    }

    _table->verticalHeader()->hide();
    _verticalLayout->addWidget(_table);
}

void BaseView::setTitle(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
}

void BaseView::resetTable() {
    for (int i = 0; i < _table->rowCount(); i++) {
        for (int j = 0; j < _table->columnCount(); j++) {
            _table->item(i, j)->setSelected(false);
        }
    }
}

void BaseView::selectRow(QTableWidgetItem* itemClicked) {
    unsigned short int row = itemClicked->row();

    for (int i = 0; i < _table->columnCount(); i++) {
        _table->item(row, i)->setSelected(true);
    }
}


