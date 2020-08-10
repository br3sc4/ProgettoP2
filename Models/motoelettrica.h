#ifndef MOTOELETTRICA_H
#define MOTOELETTRICA_H

#include "motoreelettrico.h"

class MotoElettrica: public MotoreElettrico {
public:
    MotoElettrica(
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
        unsigned short numeroPosti = 1,
        unsigned short ingombro = 2);
};

#endif // MOTOELETTRICA_H
