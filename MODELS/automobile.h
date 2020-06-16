#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "motorecombustione.h"

class Automobile: public MotoreCombustione
{
public:
    /**
     * @brief costruttore Automobile
     * @param for Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param for MotoreCombustione(capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni)
     */
    Automobile(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
               Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni, unsigned short numeroPosti = 2, unsigned short ingombro = 3);

};

#endif // AUTOMOBILE_H
