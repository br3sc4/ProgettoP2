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
    motoreCombustione(string tar, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi,
                      double capS, double litS, u_int tipC, u_int cil);

    // Metodi virtuali
    virtual ~motoreCombustione();

    //  Metodi get
    double getCapacitaSerbatoio() const;
    double getLitriSerbatoio() const;
    u_int getTipoCarburante() const;
    u_int getCilindrata() const;
};

#endif // MOTORECOMBUSTIONE_H
