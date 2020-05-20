#ifndef BICICLETTA_H
#define BICICLETTA_H

#include "motoreelettrico.h"

class Bicicletta: public MotoreElettrico
{
public:
    Bicicletta(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaBatteria, VelocitaRicarica caricaSupportata);
};

#endif // BICICLETTA_H
