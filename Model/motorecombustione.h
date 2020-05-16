#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class MotoreCombustione : public Veicolo {
public:
    // Costruttore
    MotoreCombustione();

    // Metodi virtuali
    virtual ~MotoreCombustione();
    virtual double consumoKm() const;

    typedef enum {
        benzina, diesel, gpl, metano
    } Carburante;

private:
    double capacitaSerbatoio;
    double litriSerbatoio;
    Carburante tipoCarburante;               // 0 = benzina, 1 = diesel, 2 = GPL
    u_int cilindrata;
    u_int _emissioni;                //  da 0 a 95g circa per km
};

#endif // MOTORECOMBUSTIONE_H
