#include "VIEWS/baseabstractview.h"
#include <QMessageBox>

BaseAbstractView::BaseAbstractView(const QString &title, const QStringList& headerStrings, QWidget *parent): QWidget(parent), _title(new QLabel(this)),
    _menubar(new QMenuBar(this)), _table(new QTableWidget(this)), _verticalLayout(new QVBoxLayout), _horizontalLayout(new QHBoxLayout) {    
    setupMenuBar();
    setupLayout();
    setupLabel(title);
    setupTable(headerStrings);

    setLayout(_verticalLayout);

    setMinimumSize(200,200);
}

BaseAbstractView::~BaseAbstractView() {
    delete _horizontalLayout;
    delete _verticalLayout;
    delete _table;
    delete _title;
}

void BaseAbstractView::setupLayout() {
    _verticalLayout->insertLayout(1, _horizontalLayout);
    _verticalLayout->setAlignment(Qt::AlignLeft);
}

void BaseAbstractView::setupLabel(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
    _title->setTextFormat(Qt::RichText);
    _horizontalLayout->addWidget(_title);
}

void BaseAbstractView::setupTable(const QStringList& headerStrings) {
    setHederStrings(headerStrings);
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _table->setSelectionBehavior(QAbstractItemView::SelectRows);
    _table->setSelectionMode(QAbstractItemView::SingleSelection);
    _table->verticalHeader()->hide();
    _verticalLayout->addWidget(_table);
}

void BaseAbstractView::setupMenuBar() {
    QMenu* file = _menubar->addMenu("File");
    QAction* exit = file->addAction("Exit");
    QAction* addVehicle = file->addAction("Add vehicle");
    addVehicle->setShortcut(QKeySequence::New);
    QAction* addCity = file->addAction("Add city");
    addCity->setShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_N));

    _verticalLayout->addWidget(_menubar);

    connect(exit, &QAction::triggered, this, &BaseAbstractView::closeSignal);    
    connect(addCity, &QAction::triggered, this, &BaseAbstractView::showAddCityWizard);
    connect(addVehicle, &QAction::triggered, this, &BaseAbstractView::showAddVehicleWizard);
}

void BaseAbstractView::setTitle(const QString& title) {
    _title->setText("<h1>" + title + "</h1>");
}

QString BaseAbstractView::getTitle() const {
    return _title->text();
}

void BaseAbstractView::setHederStrings(const QStringList& headerStrings) {
    _table->setColumnCount(headerStrings.size());
    _table->setHorizontalHeaderLabels(headerStrings);
    QHeaderView *header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);
}

void BaseAbstractView::resetTableSelection() {
    _table->clearSelection();
}

void BaseAbstractView::showMessage(const QString &msg) {
    QMessageBox* dialog = new QMessageBox(this);
    dialog->setText(msg);

    dialog->show();
}
