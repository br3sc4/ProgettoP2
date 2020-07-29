#ifndef MOTO_H
#define MOTO_H

#include "motorecombustione.h"

class Moto: public MotoreCombustione {
public:
    Moto(
         string targa,
         string posizione,
         unsigned long km,
         double capacitaSerbatoio,
         double litriSerbatoio,
         Carburante tipoCarburante,
         unsigned short cilindrata,
         unsigned short emissioni,
         unsigned short numeroPosti = 1,
         unsigned short ingombro = 2
        );
};

#endif // MOTO_H
