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
    AutomobileElettrica(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                        double capacitaBatteria, VelocitaRicarica caricaSupportata);

};

#endif // AUTOMOBILEELETTRICA_H
