#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class MotoreCombustione : virtual public Veicolo {
public:
    enum Carburante {
        benzina, diesel, gpl, metano
    };

    /**
     * @brief MotoreCombustione: Costruttore
     *
     * @param from Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param capacitaSerbatoio: quanti litri di carburante può contenere il serbatoio del veicolo
     * @param litriSerbatoio: quanti litri di carburante sono rimasti
     * @param tipoCarburante: il carburante utilizzato dal veicolo
     * @param cilindrata: la cilindrata del motore
     * @param emissioni: le emissioni dinquinanti del veicolo
     */
    MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                      double capacitaSerbatoio, double litriSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni);

    /**
     * @brief ~MotoreCombustione: Distruttore
     */
    virtual ~MotoreCombustione();

    double capacitaSerbatoio() const;

    double litriSerbatoio() const;

    Carburante tipoCarburante() const;

    unsigned short cilindrata() const;

    unsigned short emissioni() const;

private:
    double _capacitaSerbatoio;
    double _litriSerbatoio;
    Carburante _tipoCarburante;
    u_int _cilindrata;
    u_int _emissioni;
};

#endif // MOTORECOMBUSTIONE_H
