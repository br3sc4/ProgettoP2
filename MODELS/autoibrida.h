#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H

#include "motorecombustione.h"
#include "motoreelettrico.h"

class AutoIbrida: public MotoreCombustione, public MotoreElettrico
{
public:
    /**
     * @brief AutoIbrida: costruttore
     *
     * @param from Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param from MotoreCombustione(capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni)
     * @param from MotoreElettrico(potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale)
     */
    AutoIbrida(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
               Carburante tipoCarburante, u_int cilindrata, u_int emissioni,
               u_int potenza, u_int numeroMotori, double capacitaBatteria, double capacitaAttuale,
               VelocitaRicarica caricaSupportata, bool inCarica = false,
               Colonnina colonninaAttuale = nessuna, u_int numeroPosti = 2, u_int ingombro = 3);

    double autonomia() const;

    short int fattoreGreen() const;

    double consumoKm() const;

};

#endif // AUTOIBRIDA_H
