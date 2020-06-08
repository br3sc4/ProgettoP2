#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "baseabstractcontroller.h"
#include "model.h"
#include "VIEWS/citieslistview.h"
#include <QObject>

class CitiesListView;

class CitiesListController: public BaseAbstractController {
    Q_OBJECT

public:
    explicit CitiesListController(Model* model, QObject* parent = nullptr);
    virtual void setViewTitle() override;
    virtual void setViewHeader() override;
    virtual void setView(BaseAbstractView* view) override;

    Array<Citta*> getCities() const;

private:
    CitiesListView* _view;
    Model* _model;

public slots:
//    void rowSelected() override;
};

#endif // CITIESLISTCONTROLLER_H
