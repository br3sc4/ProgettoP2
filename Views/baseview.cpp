#include "baseview.h"
#include <QHeaderView>
#include <QSizePolicy>

BaseView::BaseView(const QString& title, QWidget *parent): QWidget(parent) {
    setupLayout();
    setupLabel(title);
    setupTable();

    setLayout(_verticalLayout);
}

BaseView::~BaseView() {}

void BaseView::setupLayout() {
    _verticalLayout = new QVBoxLayout;
    _horizontalLayout = new QHBoxLayout;
    _verticalLayout->insertLayout(0, _horizontalLayout);
    _verticalLayout->setAlignment(Qt::AlignLeft);
}

void BaseView::setupLabel(const QString& title) {
    _title = new QLabel("<h1>" + title + "</h1>", this);
    _title->setTextFormat(Qt::RichText);
    _horizontalLayout->addWidget(_title);
}

void BaseView::setupTable() {
    _table = new QTableWidget(2, 4, this);
    _table->setHorizontalHeaderLabels({ "Nome città", "Veicoli", "Veicoli in manutenzione", "Veicoli in uso" });
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);
    header->setStretchLastSection(true);
    _table->verticalHeader()->hide();
    _verticalLayout->addWidget(_table);
}


