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
    u_int tipoCarburante;               // 0 = benzina, 1 = diesel, 2 = GPL
    u_int cilindrata;
};

#endif // MOTORECOMBUSTIONE_H
