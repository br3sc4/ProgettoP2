#include "statetableitem.h"
#include <iostream>

StateTableItem::StateTableItem(Veicolo::StatoVeicolo state) : QTableWidgetItem(), _state(state) {
    setupView(state);
}

bool StateTableItem::operator<(const QTableWidgetItem& item) const {
    const StateTableItem* stateItem = dynamic_cast<const StateTableItem*>(&item);
    return _state < stateItem->_state;
}

void StateTableItem::setupView(Veicolo::StatoVeicolo state) {
    QPixmap* iconaStato;
    switch (state) {
        case Veicolo::libero:
            iconaStato = new QPixmap(":/ExtraFiles/Icons/available.png");
            setText(" Libero");
            break;
        case Veicolo::prenotato:
            iconaStato = new QPixmap(":/ExtraFiles/Icons/reserved.png");
            setText(" Prenotato");
            break;
        case Veicolo::occupato:
            iconaStato = new QPixmap(":/ExtraFiles/Icons/occupate.png");
            setText(" Occupato");
            break;
        case Veicolo::manutenzione:
            iconaStato = new QPixmap(":/ExtraFiles/Icons/manutenzione.png");
            setText(" Manutenzione");
            break;
    }
    setData(Qt::DecorationRole, iconaStato->scaled(30, 30));
}
