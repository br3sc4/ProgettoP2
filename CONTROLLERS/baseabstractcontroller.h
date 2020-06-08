#ifndef BASEABSTRACTCONTROLLER_H
#define BASEABSTRACTCONTROLLER_H

#include "VIEWS/baseabstractview.h"
#include <QObject>

class BaseAbstractController: public QObject {
    Q_OBJECT

public:
    explicit BaseAbstractController(QObject *parent = nullptr);

    virtual void setViewHeader() = 0;
    virtual void setViewTitle() = 0;
    virtual void setView(BaseAbstractView* view) = 0;

public slots:
//    virtual void rowSelected() = 0;
};

#endif // BASEABSTRACTCONTROLLER_H
