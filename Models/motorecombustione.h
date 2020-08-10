#ifndef MOTORECOMBUSTIONE_H
#define MOTORECOMBUSTIONE_H

#include "veicolo.h"

class MotoreCombustione : virtual public Veicolo {
public:

    enum Carburante {
        benzina, diesel, gpl, metano
    };

    MotoreCombustione(
        string targa,
        string posizione,
        unsigned long km,
        unsigned short numeroPosti,
        unsigned short ingombro,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti,
        double capacitaSerbatoio,
        double litriSerbatoio,
        Carburante tipoCarburante,
        unsigned short cilindrata,
        unsigned short emissioni);

    virtual ~MotoreCombustione() = 0;

    // Metodi virtuali implementati
    virtual double consumoKm() const;
    virtual double autonomia() const;
    virtual short int fattoreGreen() const;
    virtual void checkRiserva();

    // Metodi get
    double capacitaSerbatoio() const;
    double litriSerbatoio() const;
    Carburante tipoCarburante() const;
    unsigned short cilindrata() const;
    unsigned short emissioni() const;

    // Metodi set
    void setLitriSerbatoio(double litriSerbatoio);

private:
    const double _capacitaSerbatoio;            // Litri di carburante che può contenere il serbatoio
    double _litriSerbatoio;                     // Litri di carburante rimasti
    const Carburante _tipoCarburante;           // Carburante utilizzato (benzina, diesel, gpl, metano)
    const unsigned short _cilindrata;           // Cilindrata motore
    const unsigned short _emissioni;            // Emissioni CO2
};

#endif // MOTORECOMBUSTIONE_H
