#ifndef BASEABSTRACTCONTROLLER_H
#define BASEABSTRACTCONTROLLER_H

#include <QObject>

class BaseAbstractController: public QObject {
    Q_OBJECT

public:
    explicit BaseAbstractController(QObject *parent = nullptr);
    virtual ~BaseAbstractController() = 0;

    virtual void setHeader() = 0;
    virtual void setTitle() = 0;

public slots:
    virtual void rowSelected() = 0;
};

#endif // BASEABSTRACTCONTROLLER_H
