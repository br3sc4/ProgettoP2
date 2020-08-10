#ifndef AUTOMOBILEELETTRICA_H
#define AUTOMOBILEELETTRICA_H

#include "motoreelettrico.h"

class AutomobileElettrica: public MotoreElettrico {
public:
    AutomobileElettrica(
        string targa,
        string posizione,
        unsigned long km,
        unsigned int potenza,
        unsigned short numeroMotori,
        double capacitaBatteria,
        double capacitaAttuale,
        VelocitaRicarica caricaSupportata,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti,
        bool inCarica = false,
        Colonnina colonninaAttuale = nessuna,
        unsigned short numeroPosti = 2,
        unsigned short ingombro = 3);

};

#endif // AUTOMOBILEELETTRICA_H
