#ifndef MOTOELETTRICA_H
#define MOTOELETTRICA_H

#include "motoreelettrico.h"

class MotoElettrica: public MotoreElettrico
{
public:
    MotoElettrica(string targa, string posizione, double km, double capacitaBatteria, VelocitaRicarica caricaSupportata, u_int numeroPosti=1, u_int ingombro=2);
};

#endif // MOTOELETTRICA_H
