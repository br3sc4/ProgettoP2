#ifndef BASEBACKABSTRACTVIEW_H
#define BASEBACKABSTRACTVIEW_H

#include "baseabstractview.h"
#include "MODELS/array.h"
#include "MODELS/veicolo.h"
#include "MODELS/automobile.h"
#include "MODELS/automobileelettrica.h"
#include "MODELS/autoibrida.h"
#include "MODELS/moto.h"
#include "MODELS/motoelettrica.h"
#include "MODELS/monopattino.h"
#include "MODELS/bicicletta.h"
#include "typeinfo"
#include "QWidget"
#include "QPushButton"

class BaseBackAbstractView: public BaseAbstractView {
    Q_OBJECT

public:
    explicit BaseBackAbstractView(const QString& title, const QStringList& headerStrings, QWidget *parent = nullptr);
    virtual ~BaseBackAbstractView() = 0;
protected:
    const QString getIconPath(const Veicolo& vehicle);

private:
    QPushButton* _backButton;

    void setupBackButton();    

signals:
    void backButtonClicked();
};

#endif // BASEBACKABSTRACTVIEW_H
