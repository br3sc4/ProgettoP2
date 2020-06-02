#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "motorecombustione.h"

class Automobile: public MotoreCombustione
{
public:
    /**
     * @brief Automobile: costruttore
     * @param targa
     * @param posizione
     * @param km
     * @param capacitaSerbatoio
     * @param tipoCarburante
     * @param cilindrata
     * @param emissioni
     * @param numeroPosti
     * @param ingombro
     */
    Automobile(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
               Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int numeroPosti = 2, u_int ingombro = 3);

};

#endif // AUTOMOBILE_H
