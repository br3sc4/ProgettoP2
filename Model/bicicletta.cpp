#include "bicicletta.h"

Bicicletta::Bicicletta(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                       VelocitaRicarica caricaSupportata, bool inCarica, Colonnina colonninaAttuale,
                       u_int numeroPosti, u_int ingombro):
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
{}
