#include "vehiclelistview.h"

VehicleListView::VehicleListView(const QString& title, QWidget *parent): BaseView(title, parent), _backButton(new QPushButton("Back")) {
    setupBackButton();

    connect(_backButton, SIGNAL(clicked()), this, SIGNAL(backButtonClicked()));
}

VehicleListView::~VehicleListView() {}

void VehicleListView::setupBackButton() {
    _backButton->setMaximumWidth(200);
    _horizontalLayout->addWidget(_backButton);
}
