#include "MODELS/monopattino.h"

Monopattino::Monopattino(
        string targa,
        string posizione,
        unsigned long km,
        unsigned int potenza,
        unsigned short numeroMotori,
        double capacitaBatteria,
        double capacitaAttuale,
        VelocitaRicarica caricaSupportata,
        bool inCarica,
        Colonnina colonninaAttuale,
        unsigned short numeroPosti,
        unsigned short ingombro
) : Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro,  potenza,  numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale){}
