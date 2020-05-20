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
     * @param targa: la targa del veicolo
     * @param posizione: la posizione attuale del veicolo
     * @param km: i chilometri percorsi dal veicolo
     * @param numeroPosti: i posti per cui è omologato il veicolo
     * @param ingombro: le dimensioni del veicolo
     * @param capacitaSerbatoio: quanti litri di carburante può contenere il serbatoio del veicolo
     * @param tipoCarburante: il carburante utilizzato dal veicolo
     * @param cilindrata: la cilindrata del motore
     * @param emissioni: le emissioni dinquinanti del veicolo
     */
    MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                      double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni);

    /**
     * @brief ~MotoreCombustione: Distruttore
     */
    virtual ~MotoreCombustione();


private:
    double _capacitaSerbatoio;
    double _litriSerbatoio;
    Carburante _tipoCarburante;     // 0 = benzina, 1 = diesel, 2 = GPL, 3 = Metano
    u_int _cilindrata;
    u_int _emissioni;               //  da 0 a 95g circa per km
};

#endif // MOTORECOMBUSTIONE_H
