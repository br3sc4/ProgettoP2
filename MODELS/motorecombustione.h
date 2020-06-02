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

    virtual ~MotoreCombustione();

    virtual double consumoKm() const =0;

    virtual double autonomia() const =0;

    virtual short int fattoreGreen() const =0;

    virtual void checkRiserva();

    // metodi get
    double capacitaSerbatoio() const;
    double litriSerbatoio() const;
    Carburante tipoCarburante() const;
    unsigned short cilindrata() const;
    unsigned short emissioni() const;

    // metodi set
    void setCapacitaSerbatoio(double capacitaSerbatoio);
    void setLitriSerbatoio(double litriSerbatoio);
    void setTipoCarburante(const Carburante &tipoCarburante);
    void setCilindrata(unsigned short cilindrata);
    void setEmissioni(unsigned short emissioni);

private:
    double _capacitaSerbatoio;
    double _litriSerbatoio;
    Carburante _tipoCarburante;
    u_int _cilindrata;
    u_int _emissioni;
};

#endif // MOTORECOMBUSTIONE_H
