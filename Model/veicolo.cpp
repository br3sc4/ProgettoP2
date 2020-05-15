#include "veicolo.h"

Veicolo::Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, u_int emissioni):
    _targa(targa), _posizione(posizione), _chilometraggio(km), _capacitaPosti(numeroPosti), _ingombro(ingombro), _emissioni(emissioni),
    _numeroUsi(0), _tempoServizio(0), _statoAttuale(libero), _inRiserva(false), _serveAssistenza(false) {}

short Veicolo::fattoreUtilizzo() const {
    return (_tempoServizio / 52560) % 52560;
}

Veicolo::~Veicolo(){}
