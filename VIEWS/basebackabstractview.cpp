#include "basebackabstractview.h"

BaseBackAbstractView::BaseBackAbstractView(const QString& title, const QStringList& headerStrings, QWidget *parent):
    BaseAbstractView(title, headerStrings, parent), _backButton(new QPushButton("Back", parent)) {
    setupBackButton();

    connect(_backButton, SIGNAL(clicked()), this, SIGNAL(backButtonClicked()));
}

BaseBackAbstractView::~BaseBackAbstractView() {
    delete _backButton;
}

void BaseBackAbstractView::setupBackButton() {
    _backButton->setMaximumWidth(200);
    _horizontalLayout->addWidget(_backButton);
}

const QString BaseBackAbstractView::getIconPath(const Veicolo& vehicle) {
    QString basePath = ":/icons/";

    if (typeid(vehicle) == typeid(Automobile))
        return basePath + "auto.png";
    else if (typeid(vehicle) == typeid(AutoIbrida))
        return basePath + "auto_ibrida.png";
    else if (typeid(vehicle) == typeid(AutomobileElettrica))
        return basePath + "auto_elettrica.png";
    else if (typeid(vehicle) == typeid(Moto))
        return basePath + "moto.png";
//    else if (typeid(vehicle) == typeid(MotoElettrica))
//        return basePath + "moto_elettrica.png";
    else if (typeid(vehicle) == typeid(Bicicletta))
        return basePath + "bici.png";
    else
        return basePath + "monopattino.png";
}
