#include "MODELS/motoelettrica.h"

MotoElettrica::MotoElettrica(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                             VelocitaRicarica caricaSupportata, unsigned short potenza, unsigned short numeroMotori, bool inCarica, Colonnina colonninaAttuale,
                             u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
{}
