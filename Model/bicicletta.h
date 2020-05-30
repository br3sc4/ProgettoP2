#ifndef BICICLETTA_H
#define BICICLETTA_H

#include "motoreelettrico.h"

class Bicicletta: public MotoreElettrico {
public:
    /**
     * @brief Bicicletta: costruttore
     * @param targa
     * @param posizione
     * @param km
     * @param capacitaBatteria
     * @param caricaSupportata
     * @param numeroPosti
     * @param ingombro
     */
    Bicicletta(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
               VelocitaRicarica caricaSupportata, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
               u_int numeroPosti = 1, u_int ingombro = 1);
};

#endif // BICICLETTA_H
