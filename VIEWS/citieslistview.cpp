#include "citieslistview.h"

CitiesListView::CitiesListView(const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseAbstractView(title, headerStrings, parent) {
    setMinimumSize(600, 400);
}

CitiesListView::~CitiesListView() {}
