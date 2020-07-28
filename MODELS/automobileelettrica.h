#ifndef AUTOMOBILEELETTRICA_H
#define AUTOMOBILEELETTRICA_H

#include "motoreelettrico.h"

class AutomobileElettrica: public MotoreElettrico {
public:
    /**
     * @brief construttore AutomobileElettrica
     * @param for Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param for MotoreElettrico(potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
     */
    AutomobileElettrica(string targa, string posizione, unsigned long km,
                        unsigned int potenza, unsigned short numeroMotori, double capacitaBatteria, double capacitaAttuale,
                        VelocitaRicarica caricaSupportata, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
                        unsigned short numeroPosti = 2, unsigned short ingombro = 3);

};

#endif // AUTOMOBILEELETTRICA_H
