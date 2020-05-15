#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class MotoreCombustione : public Veicolo
{
private:
    double capacitaSerbatoio;
    double litriSerbatoio;
    u_int tipoCarburante;               // 0 = benzina, 1 = diesel, 2 = GPL
    u_int cilindrata;

public:
    // Costruttore
    MotoreCombustione();

    // Metodi virtuali
    virtual ~MotoreCombustione();

};

#endif // MOTORECOMBUSTIONE_H
