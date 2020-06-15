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
    Bicicletta(string targa, string posizione, double km,
               u_int potenza, u_int numeroMotori, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata,
               bool inCarica = false, Colonnina colonninaAttuale = nessuna,
               u_int numeroPosti = 1, u_int ingombro = 1);
};

#endif // BICICLETTA_H
