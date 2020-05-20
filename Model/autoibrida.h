#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H

#include "motorecombustione.h"
#include "motoreelettrico.h"

class AutoIbrida: public MotoreCombustione, public MotoreElettrico
{
public:
    /**
     * @brief AutoIbrida: costruttore
     * @param targa
     * @param posizione
     * @param km
     * @param capacitaSerbatoio
     * @param tipoCarburante
     * @param cilindrata
     * @param emissioni
     * @param capacitaBatteria
     * @param caricaSupportata
     * @param numeroPosti
     * @param ingombro
     */
    AutoIbrida(string targa, string posizione, double km, double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni,
               double capacitaBatteria, VelocitaRicarica caricaSupportata, u_int numeroPosti=2, u_int ingombro=3);

    /**
     * @brief autonomia
     * @return
     */
    double autonomia() const {return 0;}

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
