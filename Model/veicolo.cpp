#include "veicolo.h"

Veicolo::Veicolo(){}

short Veicolo::fattoreUtilizzo() const {
    return (tempoServizio / 52560) % 52560;
}

Veicolo::~Veicolo(){}
