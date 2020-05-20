#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "motorecombustione.h"

class Automobile: public MotoreCombustione
{
public:
    Automobile(string targa, string posizione, double km, double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int numeroPosti=2, u_int ingombro=3);
};

#endif // AUTOMOBILE_H
