#ifndef BASEBACKABSTRACTVIEW_H
#define BASEBACKABSTRACTVIEW_H

#include "baseabstractview.h"
#include "MODELS/array.h"
#include "MODELS/veicolo.h"
#include <QWidget>
#include <QPushButton>

class BaseBackAbstractView: public BaseAbstractView {
    Q_OBJECT

public:
    explicit BaseBackAbstractView(const QString& title, const QStringList& headerStrings, QWidget *parent = nullptr);
    virtual ~BaseBackAbstractView() = 0;

private:
    QPushButton* _backButton;

    void setupBackButton();

signals:
    void backButtonClicked();
};

#endif // BASEBACKABSTRACTVIEW_H
