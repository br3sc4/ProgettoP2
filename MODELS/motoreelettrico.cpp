#include "MODELS/motoreelettrico.h"

MotoreElettrico::MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, bool inCarica,
                                 double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata, Colonnina colonninaAttuale):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    _inCarica(inCarica), _capacitaBatteria(capacitaBatteria), _capacitaAttuale(capacitaAttuale), _caricaSupportata(caricaSupportata),
    _colonninaAttuale(colonninaAttuale) {}

MotoreElettrico::~MotoreElettrico() {}

unsigned short MotoreElettrico::percentualeCarica() const {
    return (_capacitaAttuale * 100) / _capacitaBatteria;
}

bool MotoreElettrico::inCarica() const {
    return _inCarica;
}

double MotoreElettrico::capacitaBatteria() const
{
    return _capacitaBatteria;
}

double MotoreElettrico::capacitaAttuale() const
{
    return _capacitaAttuale;
}

MotoreElettrico::VelocitaRicarica MotoreElettrico::caricaSupportata() const
{
    return _caricaSupportata;
}

MotoreElettrico::Colonnina MotoreElettrico::colonninaAttuale() const
{
    return _colonninaAttuale;
}

short MotoreElettrico::tempoRimanenteCaricaCompleta() const {
    if (_inCarica) {
        int _capacitaColonnina = 0;
        if (_caricaSupportata == lenta)
            _capacitaColonnina = 16;
        else if (_caricaSupportata == media)
            _capacitaColonnina = 63;
        else
            _capacitaColonnina = 200;
        return _capacitaBatteria / _capacitaColonnina;
    } else
        return -1;
}
