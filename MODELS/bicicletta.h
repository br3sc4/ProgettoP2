#ifndef BICICLETTA_H
#define BICICLETTA_H

#include "motoreelettrico.h"

class Bicicletta: public MotoreElettrico {
public:
    Bicicletta(
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
        unsigned short ingombro = 1);
};

#endif // BICICLETTA_H
