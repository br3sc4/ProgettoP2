#include "vehiclelistview.h"

VehicleListView::VehicleListView(const QString& title, QWidget *parent): BaseView(title, parent) {
    setupBackButton();
}

VehicleListView::~VehicleListView() {}

void VehicleListView::setupBackButton() {
    _backButton = new QPushButton("Back");
    _backButton->setMaximumWidth(200);
    _horizontalLayout->addWidget(_backButton);
}
