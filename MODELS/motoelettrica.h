#ifndef MOTOELETTRICA_H
#define MOTOELETTRICA_H

#include "motoreelettrico.h"

class MotoElettrica: public MotoreElettrico {
public:
    MotoElettrica(
                    string targa,
                    string posizione,
                    unsigned long km,
                    double capacitaBatteria,
                    double capacitaAttuale,
                    VelocitaRicarica caricaSupportata,
                    unsigned int potenza,
                    unsigned short numeroMotori,
                    bool inCarica = false,
                    Colonnina colonninaAttuale = nessuna,
                    unsigned short numeroPosti = 1,
                    unsigned short ingombro = 2
                  );
};

#endif // MOTOELETTRICA_H
