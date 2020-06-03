#include "headerview.h"

HeaderView::HeaderView(const QVector<QString>& headerString, QWidget *parent): QWidget(parent), _layout(new QHBoxLayout),
    _headerStrings(headerString), _headerLabels(new QVector<QLabel*>) {
    setupLayout();
    setupLabels();

    setLayout(_layout);
}

HeaderView::~HeaderView() {
    delete _headerLabels;
    delete _layout;
}

void HeaderView::setupLayout() {
    _layout->setAlignment(Qt::AlignHCenter);
}

void HeaderView::setupLabels() {
    for (auto it = _headerStrings.cbegin(); it != _headerStrings.cend(); it++) {
        QLabel* label = new QLabel(*it, this);
        label->setAlignment(Qt::AlignJustify);
        label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        label->setScaledContents(true);
        _headerLabels->push_back(label);
        _layout->addWidget(label);
    }
}
