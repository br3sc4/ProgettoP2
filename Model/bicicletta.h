#ifndef BICICLETTA_H
#define BICICLETTA_H

#include "motoreelettrico.h"

class Bicicletta: public MotoreElettrico
{
public:
    Bicicletta(string targa, string posizione, double km, double capacitaBatteria, VelocitaRicarica caricaSupportata, u_int numeroPosti=1, u_int ingombro=1);
};

#endif // BICICLETTA_H
