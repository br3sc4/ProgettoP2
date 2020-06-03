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
