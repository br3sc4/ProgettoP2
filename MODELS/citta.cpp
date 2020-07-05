#include "citta.h"

Citta::Citta(): _nome(), _veicoli() {}

Citta::Citta(const std::string& nome, const Array<Veicolo*> veicoli): _nome(nome), _veicoli(veicoli) {}

std::string Citta::getNome() const {
    return _nome;
}

Veicolo* Citta::getVeicolo(unsigned int index) const {
    return _veicoli[index];
}

const Array<Veicolo*>& Citta::getVeicoli() const {
    return _veicoli;
}

Array<Veicolo*>& Citta::getVeicoli() {
    return _veicoli;
}

void Citta::addVeicolo(Veicolo* const veicolo) {
    _veicoli.push_back(veicolo);
}

void Citta::deleteVeicolo(Array<Veicolo*>::iterator it) {
    _veicoli.erase(it);
}
