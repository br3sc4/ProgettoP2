#ifndef CITIESLISTCONTROLLER_H
#define CITIESLISTCONTROLLER_H

#include "baseabstractcontroller.h"
#include "model.h"
#include "VIEWS/citieslistview.h"
#include <QObject>

class CitiesListController: public BaseAbstractController {
    Q_OBJECT

public:
    explicit CitiesListController(QObject* parent = nullptr);
//    virtual ~CitiesListController();
//    void setTitle() override;
//    void setHeader() override;

//    void getCities() const;

private:
//    CitiesListView* _view;
//    Model* _model;

public slots:
//    void rowSelected() override;
};

#endif // CITIESLISTCONTROLLER_H
