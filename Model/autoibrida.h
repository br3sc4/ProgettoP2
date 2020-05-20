#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H

#include "motorecombustione.h"
#include "motoreelettrico.h"

class AutoIbrida: public MotoreCombustione, public MotoreElettrico
{
public:
    AutoIbrida(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
               double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni,
               double capacitaBatteria, VelocitaRicarica caricaSupportata);
    /**
     * @brief autonomia
     * @return
     */
    double autonomia() const {return 0;}           // range del veicolo dato da litri o ampere * consumo

    /**
     * @brief fattoreGreen
     * @return
     */
     short int fattoreGreen() const {return 0;}      // da -10 a +10

    /**
     * @brief autonomia
     * @return
     */
     double autonomia() {return 0;}

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
