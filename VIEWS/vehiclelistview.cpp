#include "VIEWS/vehiclelistview.h"

VehicleListView::VehicleListView(const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseBackAbstractView(title, headerStrings, parent) {
    setMinimumSize(600, 400);
}

VehicleListView::~VehicleListView() {}
