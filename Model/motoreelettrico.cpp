#include "motoreelettrico.h"

MotoreElettrico::MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                 double capacitaBatteria, VelocitaRicarica caricaSupportata):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _inCarica(false), _capacitaTotaleBatteria(capacitaBatteria),
    _capacitaAttuale(capacitaBatteria), _caricaSupportata(caricaSupportata), _colonninaAttuale(nessuna) {}

MotoreElettrico::~MotoreElettrico() {}

unsigned short MotoreElettrico::percentualeCarica() const {
    return (_capacitaAttuale * 100) / _capacitaTotaleBatteria;
}

bool MotoreElettrico::inCarica() const {
    return _inCarica;
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
        return _capacitaTotaleBatteria / _capacitaColonnina;
    } else
        return -1;
}
