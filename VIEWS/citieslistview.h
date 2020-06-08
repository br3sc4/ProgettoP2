#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "baseabstractview.h"
#include "CONTROLLERS/citieslistcontroller.h"
#include <QWidget>

class CitiesListController;

class CitiesListView: public BaseAbstractView {
    Q_OBJECT

public:
    explicit CitiesListView(CitiesListController* controller, const QString& title = "Cities",
                            const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~CitiesListView();
    virtual void update() override;

private:
    CitiesListController* _controller;
};

#endif // CITIESLISTVIEW_H
