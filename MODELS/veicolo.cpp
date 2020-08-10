#include "Models/veicolo.h"

Veicolo::Veicolo() {}

Veicolo::Veicolo(
        string targa,
        string posizione,
        unsigned long km,
        unsigned short numeroPosti,
        unsigned short ingombro,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti):
        _targa(targa),
        _posizione(posizione),
        _chilometraggio(km),
        _capacitaPosti(numeroPosti),
        _ingombro(ingombro),
        _numeroUsi(numeroUsi),
        _tempoServizio(tempoServizio),
        _statoAttuale(statoAttuale),
        _inRiserva(inRiserva),
        _serveAssistenza(serveAssistenza),
        _numeroGuasti(numeroGuasti) {}

Veicolo::~Veicolo() = default;

short Veicolo::fattoreUtilizzo() const {
    return 1 + (_tempoServizio / 52560) % 52560 ;
}

string Veicolo::targa() const {
    return _targa;
}

string Veicolo::posizione() const {
    return _posizione;
}

unsigned long Veicolo::chilometraggio() const {
    return _chilometraggio;
}

unsigned short Veicolo::capacitaPosti() const {
    return _capacitaPosti;
}

unsigned short Veicolo::ingombro() const {
    return _ingombro;
}

unsigned short Veicolo::numeroUsi() const {
    return _numeroUsi;
}

unsigned long Veicolo::tempoServizio() const {
    return _tempoServizio;
}

Veicolo::StatoVeicolo Veicolo::statoAttuale() const {
    return _statoAttuale;
}

void Veicolo::setStatoAttuale(const StatoVeicolo &statoAttuale) {
    _statoAttuale = statoAttuale;
}

bool Veicolo::inRiserva() const {
    return _inRiserva;
}

void Veicolo::setInRiserva(bool inRiserva) {
    _inRiserva = inRiserva;
}

bool Veicolo::serveAssistenza() const {
    return _serveAssistenza;
}

void Veicolo::setServeAssistenza(bool serveAssistenza) {
    _serveAssistenza = serveAssistenza;
}

unsigned short Veicolo::numeroGuasti() const {
    return _numeroGuasti;
}
