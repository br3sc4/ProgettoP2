#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "motorecombustione.h"

class Automobile: public MotoreCombustione
{
public:
    Automobile(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni);
};

#endif // AUTOMOBILE_H
