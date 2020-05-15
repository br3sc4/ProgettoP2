#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class motoreCombustione : public veicolo
{
private:
    double capacitaSerbatoio;
    double litriSerbatoio;
    u_int tipoCarburante;               // 0 = benzina, 1 = diesel, 2 = GPL
    u_int cilindrata;

public:
    // Costruttore
    motoreCombustione();

    // Metodi virtuali
    virtual ~motoreCombustione();

};

#endif // MOTORECOMBUSTIONE_H
