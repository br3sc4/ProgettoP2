#ifndef MOTO_H
#define MOTO_H

#include "motorecombustione.h"

class Moto: public MotoreCombustione
{
public:
    Moto(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
          double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni);
};

#endif // MOTO_H
