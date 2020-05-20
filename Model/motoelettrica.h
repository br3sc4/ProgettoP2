#ifndef MOTOELETTRICA_H
#define MOTOELETTRICA_H

#include "motoreelettrico.h"

class MotoElettrica: public MotoreElettrico
{
public:
    MotoElettrica(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaBatteria, VelocitaRicarica caricaSupportata);
};

#endif // MOTOELETTRICA_H
