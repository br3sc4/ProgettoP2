#include "veicolo.h"

Veicolo::Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro):
    _targa(targa), _posizione(posizione), _chilometraggio(km), _capacitaPosti(numeroPosti), _ingombro(ingombro),
    _numeroUsi(0), _tempoServizio(0), _statoAttuale(libero), _inRiserva(false), _serveAssistenza(false) {}

short Veicolo::fattoreUtilizzo() const {
    return (_tempoServizio / 52560) % 52560;
}

Veicolo::~Veicolo(){}

string Veicolo::targa() const {
    return _targa;
}

void Veicolo::setTarga(const string &targa) {
    _targa = targa;
}

string Veicolo::posizione() const {
    return _posizione;
}

void Veicolo::setPosizione(const string &posizione) {
    _posizione = posizione;
}

double Veicolo::chilometraggio() const {
    return _chilometraggio;
}

void Veicolo::setChilometraggio(double chilometraggio) {
    _chilometraggio = chilometraggio;
}

unsigned short Veicolo::capacitaPosti() const {
    return _capacitaPosti;
}

void Veicolo::setCapacitaPosti(unsigned short capacitaPosti) {
    _capacitaPosti = capacitaPosti;
}

unsigned short Veicolo::ingombro() const {
    return _ingombro;
}

void Veicolo::setIngombro(unsigned short ingombro) {
    _ingombro = ingombro;
}

unsigned short Veicolo::numeroUsi() const {
    return _numeroUsi;
}

void Veicolo::setNumeroUsi(unsigned short numeroUsi) {
    _numeroUsi = numeroUsi;
}

unsigned long Veicolo::tempoServizio() const {
    return _tempoServizio;
}

void Veicolo::setTempoServizio(unsigned long tempoServizio) {
    _tempoServizio = tempoServizio;
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

unsigned short Veicolo::guasti() const {
    return _guasti;
}

void Veicolo::setGuasti(unsigned short guasti) {
    _guasti = guasti;
}
