#include "monopattino.h"

Monopattino::Monopattino(string targa, string posizione, double km, double capacitaBatteria, VelocitaRicarica caricaSupportata, u_int numeroPosti, u_int ingombro): Veicolo(targa, posizione, km, numeroPosti, ingombro), MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, capacitaBatteria, caricaSupportata) {}
