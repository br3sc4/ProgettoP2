#ifndef CITTA_H
#define CITTA_H

#include "array.h"
#include "veicolo.h"
#include <algorithm>

class Citta {
public:
    Citta();
    Citta(const string& nome, const Array<Veicolo*> veicoli = Array<Veicolo*>());

    string getNome() const;
    Veicolo* getVeicolo(unsigned int index) const;
    const Array<Veicolo*>& getVeicoli() const;
    Array<Veicolo*>& getVeicoli();
    void addVeicolo(Veicolo* const veicolo);
    void deleteVeicolo(Array<Veicolo*>::iterator it);

private:
    const string _nome;
    Array<Veicolo*> _veicoli;
};

#endif // CITTA_H
