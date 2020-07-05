#include "MODELS/veicolo.h"

Veicolo::Veicolo(){}

Veicolo::Veicolo(string targa, string posizione, unsigned long km, unsigned short numeroPosti, unsigned short ingombro):
    _targa(targa), _posizione(posizione), _chilometraggio(km), _capacitaPosti(numeroPosti), _ingombro(ingombro),
    _numeroUsi(0), _tempoServizio(0), _statoAttuale(libero), _inRiserva(false), _serveAssistenza(false) {}

Veicolo::~Veicolo() {}

void Veicolo::checkRiserva() {
    if (autonomia() < 30) _inRiserva = true;
    else _inRiserva = false;
}

short Veicolo::fattoreUtilizzo() const {
    return (_tempoServizio / 52560) % 52560;
}

string Veicolo::targa() const {
    return _targa;
}

string Veicolo::posizione() const {
    return _posizione;
}

void Veicolo::setPosizione(const string &posizione) {
    _posizione = posizione;
}

unsigned long Veicolo::chilometraggio() const {
    return _chilometraggio;
}

void Veicolo::increaseChilometraggio(unsigned long chilometraggio) {
    _chilometraggio += chilometraggio;
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

void Veicolo::increaseNumeroUsi(unsigned short numeroUsi) {
    _numeroUsi += numeroUsi;
}

unsigned long Veicolo::tempoServizio() const {
    return _tempoServizio;
}

void Veicolo::increaseTempoServizio(unsigned long tempoServizio) {
    _tempoServizio += tempoServizio;
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

bool Veicolo::serveAssistenza() const {
    return _serveAssistenza;
}

void Veicolo::setServeAssistenza(bool serveAssistenza) {
    _serveAssistenza = serveAssistenza;
}

unsigned short Veicolo::guasti() const {
    return _guasti;
}

void Veicolo::increaseGuasti(unsigned short guasti) {
    _guasti += guasti;
}
