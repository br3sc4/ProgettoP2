#ifndef STATETABLEITEM_H
#define STATETABLEITEM_H

#include "Models/veicolo.h"
#include <QWidget>
#include <QTableWidgetItem>

class StateTableItem : public QTableWidgetItem {
public:
    explicit StateTableItem(Veicolo::StatoVeicolo state);
    virtual bool operator<(const QTableWidgetItem& item) const;

private:
    Veicolo::StatoVeicolo _state;

    void setupView(Veicolo::StatoVeicolo state);
};

#endif // STATETABLEITEM_H
