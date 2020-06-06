#ifndef MONOPATTINO_H
#define MONOPATTINO_H

#include "motoreelettrico.h"

class Monopattino: public MotoreElettrico {
public:
    /**
     * @brief Monopattino: costruttore
     * @param targa
     * @param posizione
     * @param km
     * @param capacitaBatteria
     * @param caricaSupportata
     * @param numeroPosti
     * @param ingombro
     */
    Monopattino(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                VelocitaRicarica caricaSupportata, u_int potenza, u_int numeroMotori, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
                u_int numeroPosti = 1, u_int ingombro = 1);
};

#endif // MONOPATTINO_H
