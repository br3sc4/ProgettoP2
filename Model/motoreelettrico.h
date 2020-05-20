#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"

class MotoreElettrico : public Veicolo {
public:
    enum Colonnina {
        nessuna
    };

    enum VelocitaRicarica {
        lenta = 1, media, veloce
    };

    /**
     * @brief MotoreElettrico: Costruttore
     * @param targa: la targa del veicolo
     * @param posizione: la posizione attuale del veicolo
     * @param km: i chilometri percorsi dal veicolo
     * @param numeroPosti: i posti per cui è omologato il veicolo
     * @param ingombro: le dimensioni del veicolo
     * @param capacitaBatteria: la capacità totale della batteria del veicolo
     * @param caricaSupportata: la velocità di carica a cui può essere caricato il veicolo
     */
    MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                    double capacitaBatteria, VelocitaRicarica caricaSupportata);

    /**
     * @brief ~MotoreElettrico: Distruttore
     */
    virtual ~MotoreElettrico();

    /**
     * @brief consumoKm
     * @return calcola il consumo del veicolo in base alle sue caratteristiche
     */
    virtual double consumoKm() const;

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

private:
    bool _inCarica;
    double _capacitaTotaleBatteria;         // Ampere-ora (Ah) massimi
    double _capacitaAttuale;               // Ampere-ora presenti
    VelocitaRicarica _caricaSupportata;     // la massima velocità alla quale può essere ricaricata (da 1 a 4)
    Colonnina _colonninaAttuale;              // tipo di colonnina alla quale è inCarica
};

#endif // MOTOREELETTRICO_H
