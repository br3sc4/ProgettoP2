#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "baseabstractview.h"
#include "CONTROLLERS/controller.h"
#include <QWidget>

class Controller;

class CitiesListView: public BaseAbstractView {
    Q_OBJECT

public:
    explicit CitiesListView(Controller* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);

    virtual void update();

private:
    Controller* _controller;
};

#endif // CITIESLISTVIEW_H
