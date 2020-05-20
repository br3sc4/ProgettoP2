#ifndef AUTOMOBILEELETTRICA_H
#define AUTOMOBILEELETTRICA_H

#include "motoreelettrico.h"

class AutomobileElettrica: public MotoreElettrico
{
public:
    AutomobileElettrica(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaBatteria, VelocitaRicarica caricaSupportata);

};

#endif // AUTOMOBILEELETTRICA_H
