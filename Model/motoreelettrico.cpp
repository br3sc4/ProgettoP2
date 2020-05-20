#include "motoreelettrico.h"

MotoreElettrico::MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                 double capacitaBatteria, VelocitaRicarica caricaSupportata):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _inCarica(false), _capacitaTotaleBatteria(capacitaBatteria),
    _capacitaAttuale(capacitaBatteria), _caricaSupportata(caricaSupportata), _colonninaAttuale(nessuna) {}

MotoreElettrico::~MotoreElettrico() {}

unsigned short MotoreElettrico::percentualeCarica() const {
    return (_capacitaAttuale * 100) / _capacitaTotaleBatteria;
}

unsigned short MotoreElettrico::tempoRimanenteCaricaCompleta() const {
    return 10;
}
