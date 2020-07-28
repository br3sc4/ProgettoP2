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
    Monopattino(string targa, string posizione, unsigned long km, double capacitaBatteria, double capacitaAttuale,
                VelocitaRicarica caricaSupportata, unsigned int potenza, unsigned short numeroMotori, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
                unsigned short numeroPosti = 1, unsigned short ingombro = 1);
};

#endif // MONOPATTINO_H
