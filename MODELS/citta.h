#ifndef CITTA_H
#define CITTA_H

#include "array.h"
#include "veicolo.h"

class Citta {
public:
    Citta();
    Citta(const string& nome, const Array<Veicolo*> veicoli = Array<Veicolo*>());

    std::string getNome() const;
    Array<Veicolo *> getVeicoli() const;
    void addVeicolo(Veicolo* const veicolo);
    void deleteVeicolo(Array<Veicolo*>::iterator it);

private:
    const std::string _nome;
    Array<Veicolo*> _veicoli;
};

#endif // CITTA_H
