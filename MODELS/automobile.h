#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "motorecombustione.h"

class Automobile: public MotoreCombustione
{
public:
    Automobile(
        string targa,
        string posizione,
        unsigned long km,
        double capacitaSerbatoio,
        double litriSerbatoio,
        Carburante tipoCarburante,
        unsigned short cilindrata,
        unsigned short emissioni,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti,
        unsigned short numeroPosti = 2,
        unsigned short ingombro = 3);
};

#endif // AUTOMOBILE_H
