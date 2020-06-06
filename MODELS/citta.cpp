#include "citta.h"

Citta::Citta(const std::string& nome, const Array<Veicolo*> veicoli): _nome(nome), _veicoli(veicoli) {}

std::string Citta::getNome() const {
    return _nome;
}

Array<Veicolo*> Citta::getVeicoli() const {
    return _veicoli;
}

void Citta::addVeicolo(Veicolo* const veicolo) {
    _veicoli.push_back(veicolo);
}

Array<Veicolo*>::iterator Citta::deleteVeicolo(Array<Veicolo*>::iterator it) {
    return _veicoli.erase(it);
}
