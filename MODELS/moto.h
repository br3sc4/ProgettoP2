#ifndef MOTO_H
#define MOTO_H

#include "motorecombustione.h"

class Moto: public MotoreCombustione {
public:
    /**
     * @brief Moto: costruttore
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
    Moto(string targa, string posizione, unsigned long km, double capacitaSerbatoio, double litriSerbatoio,
         Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni, unsigned short numeroPosti = 1, unsigned short ingombro = 2);
};

#endif // MOTO_H
