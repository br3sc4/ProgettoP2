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
     * @param from MotoreElettrico()
     */
    AutoIbrida(string targa, string posizione, double km,
               double capacitaSerbatoio, double litriSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni,
               double capacitaBatteria, VelocitaRicarica caricaSupportata, u_int numeroPosti=2, u_int ingombro=3);

    /**
     * @brief autonomia
     * @return
     */
    double autonomia() const {
        return consumoKm()*litriSerbatoio()*;
    }

    /**
     * @brief fattoreGreen
     * @return
     */
     short int fattoreGreen() const {return 0;}

    /**
     * @brief consumoKm
     * @return calcola il consumo del veicolo in base alle sue caratteristiche
     */
     double consumoKm() const {return 0;}

    /**
     * @brief fattoreUtilizzo
     * @return
     */
     short int fattoreUtilizzo() const{return 0;}

     /**
      * @brief tempoRimanenteCaricaCompleta
      * @return calcola il tempo rimanente al veicolo per ranggiungere il 100% di carica
      */
     unsigned short tempoRimanenteCaricaCompleta() const;

     /**
      * @brief percentualeCarica
      * @return calcola la percentuale della batteria in quel momento
      */
     unsigned short percentualeCarica() const;

};

#endif // AUTOIBRIDA_H
