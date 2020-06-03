#ifndef CITIESLISTVIEW_H
#define CITIESLISTVIEW_H

#include "baseabstractview.h"
#include <QWidget>

class CitiesListView: public BaseAbstractView {
    Q_OBJECT

public:
    explicit CitiesListView(const QString& title = "Cities", const QStringList& headerStrings = {}, QWidget *parent = nullptr);
    virtual ~CitiesListView();
};

#endif // CITIESLISTVIEW_H
