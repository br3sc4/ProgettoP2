#include "MODELS/automobileelettrica.h"

AutomobileElettrica::AutomobileElettrica(string targa, string posizione, double km, unsigned short potenza, unsigned short numeroMotori, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata, bool inCarica, Colonnina colonninaAttuale, u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, potenza,  numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
{}
