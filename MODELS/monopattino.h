#ifndef MONOPATTINO_H
#define MONOPATTINO_H

#include "motoreelettrico.h"

class Monopattino: public MotoreElettrico {
public:
    Monopattino(
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
                unsigned short ingombro = 1
               );
};

#endif // MONOPATTINO_H
