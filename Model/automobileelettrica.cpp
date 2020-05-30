#include "automobileelettrica.h"

AutomobileElettrica::AutomobileElettrica(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                                         VelocitaRicarica caricaSupportata, bool inCarica, Colonnina colonninaAttuale,
                                         u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
{}
