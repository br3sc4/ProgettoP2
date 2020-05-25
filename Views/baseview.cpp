#include "baseview.h"
#include <QHeaderView>
#include <QSizePolicy>

BaseView::BaseView(const QString& title, QWidget *parent): QWidget(parent), _verticalLayout(new QVBoxLayout),
    _title(new QLabel(this)), _table(new QTableWidget(2, 4, this)), _horizontalLayout(new QHBoxLayout) {
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
    _table->setHorizontalHeaderLabels({ "Nome città", "Veicoli", "Veicoli in manutenzione", "Veicoli in uso" });
    QHeaderView *header = _table->horizontalHeader();
    header->resizeSections(QHeaderView::ResizeToContents);
    header->setStretchLastSection(true);
    _table->verticalHeader()->hide();
    _verticalLayout->addWidget(_table);
}

void BaseView::setTitle(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
}


