#include "backtopbar.h"

BackTopBar::BackTopBar(const QString& title, QWidget* parent)
    : BaseTopBar(title, parent), _backButton(new QPushButton("Back", this)) {
    setupBackButton();

    connect(_backButton, &QPushButton::clicked, this, &BackTopBar::backButtonClicked);
}

BackTopBar::~BackTopBar() {
    delete _backButton;
}

void BackTopBar::setupBackButton() {
    _backButton->setMinimumWidth(200);
    _horizontalLayout->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
    _horizontalLayout->addWidget(_backButton);
}
