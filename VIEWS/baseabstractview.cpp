#include "VIEWS/baseabstractview.h"

BaseAbstractView::BaseAbstractView(const QString &title, const QStringList& headerStrings, QWidget *parent): QWidget(parent), _title(new QLabel(this)),
    _table(new QTableWidget(this)), _verticalLayout(new QVBoxLayout), _horizontalLayout(new QHBoxLayout) {
    setupLayout();
    setupLabel(title);
    setupTable(headerStrings);

    setLayout(_verticalLayout);
}

BaseAbstractView::~BaseAbstractView() {
    delete _horizontalLayout;
    delete _verticalLayout;
    delete _table;
    delete _title;
}

void BaseAbstractView::setupLayout() {
    _verticalLayout->insertLayout(0, _horizontalLayout);
    _verticalLayout->setAlignment(Qt::AlignLeft);
}

void BaseAbstractView::setupLabel(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
    _title->setTextFormat(Qt::RichText);
    _horizontalLayout->addWidget(_title);
}

void BaseAbstractView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setRowCount(0);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->verticalHeader()->hide();
    _verticalLayout->addWidget(_table);
}

void BaseAbstractView::setTitle(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
}

void BaseAbstractView::setHederStrings(const QStringList &headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setStretchLastSection(true);
    header->resizeSections(QHeaderView::ResizeToContents);
}

void BaseAbstractView::resetTableSelection() {
    _table->clearSelection();
}

void BaseAbstractView::setData(const QStringList &headerStrings) {
    _table->setRowCount(headerStrings.size());
    for (int i = 0; i < _table->rowCount(); i++) {
        QTableWidgetItem *item = new QTableWidgetItem(headerStrings[i]);
        connect(_table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SIGNAL(rowDoubleClicked(QTableWidgetItem*)));
        _table->setItem(i, 0, item);
    }
    _table->resizeColumnsToContents();
}
