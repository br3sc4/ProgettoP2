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
    Moto(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
         Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int numeroPosti = 1, u_int ingombro = 2);
};

#endif // MOTO_H
