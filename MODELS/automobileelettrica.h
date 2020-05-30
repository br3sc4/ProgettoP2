#ifndef AUTOMOBILEELETTRICA_H
#define AUTOMOBILEELETTRICA_H

#include "motoreelettrico.h"

class AutomobileElettrica: public MotoreElettrico {
public:
    /**
     * @brief AutomobileElettrica: construttore
     * @param targa
     * @param posizione
     * @param km
     * @param numeroPosti
     * @param ingombro
     * @param capacitaBatteria
     * @param caricaSupportata
     */
    AutomobileElettrica(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                        VelocitaRicarica caricaSupportata, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
                        u_int numeroPosti = 2, u_int ingombro = 3);

};

#endif // AUTOMOBILEELETTRICA_H
