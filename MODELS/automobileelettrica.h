#ifndef AUTOMOBILEELETTRICA_H
#define AUTOMOBILEELETTRICA_H

#include "motoreelettrico.h"

class AutomobileElettrica: public MotoreElettrico {
public:
    /**
     * @brief construttore AutomobileElettrica
     * @param
     * @param
     * @param
     * @param
     * @param
     */
    AutomobileElettrica(string targa, string posizione, double km, u_int potenza, u_int numeroMotori, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata, bool inCarica = false, Colonnina colonninaAttuale = nessuna, u_int numeroPosti = 2, u_int ingombro = 3);

};

#endif // AUTOMOBILEELETTRICA_H
