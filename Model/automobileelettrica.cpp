#include "automobileelettrica.h"

AutomobileElettrica::AutomobileElettrica(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaBatteria, VelocitaRicarica caricaSupportata):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, capacitaBatteria, caricaSupportata) {}
