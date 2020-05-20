#ifndef MONOPATTINO_H
#define MONOPATTINO_H

#include "motoreelettrico.h"

class Monopattino: public MotoreElettrico
{
public:
    Monopattino(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaBatteria, VelocitaRicarica caricaSupportata);
};

#endif // MONOPATTINO_H
