#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class MotoreCombustione : virtual public Veicolo {
public:

    enum Carburante {
        benzina, diesel, gpl, metano
    };

    /**
     * @brief costruttore MotoreCombustione
     * @param for Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param capacitaSerbatoio
     * @param litriSerbatoio
     * @param tipoCarburante
     * @param cilindrata
     * @param emissioni
     */
    MotoreCombustione(string targa, string posizione, unsigned long km, unsigned short numeroPosti, unsigned short ingombro,
                      double capacitaSerbatoio, double litriSerbatoio, Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni);

    virtual ~MotoreCombustione();

    // metodi virtuali implementati
    virtual double consumoKm() const;
    virtual double autonomia() const;
    virtual short int fattoreGreen() const;

    // metodi get
    double capacitaSerbatoio() const;
    double litriSerbatoio() const;
    Carburante tipoCarburante() const;
    unsigned short cilindrata() const;
    unsigned short emissioni() const;

    // metodi set
    void setLitriSerbatoio(double litriSerbatoio);

private:
    const double _capacitaSerbatoio;            // Litri di carburante che può contenere il serbatoio
    double _litriSerbatoio;                     // Litri di carburante rimasti
    const Carburante _tipoCarburante;           // Carburante utilizzato (benzina, diesel, gpl, metano)
    const unsigned short _cilindrata;                    // Cilindrata motore
    const unsigned short _emissioni;                     // Emissioni CO2
};

#endif // MOTORECOMBUSTIONE_H
