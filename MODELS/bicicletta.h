#ifndef BICICLETTA_H
#define BICICLETTA_H

#include "motoreelettrico.h"

class Bicicletta: public MotoreElettrico {
public:
    /**
     * @brief costruttore Bicicletta
     * @param for Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param for MotoreElettrico(potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
     */
    Bicicletta(string targa, string posizione, unsigned long km,
               unsigned short potenza, unsigned short numeroMotori, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata,
               bool inCarica = false, Colonnina colonninaAttuale = nessuna,
               unsigned short numeroPosti = 1, unsigned short ingombro = 1);
};

#endif // BICICLETTA_H
