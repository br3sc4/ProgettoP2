#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"

class MotoreElettrico : virtual public Veicolo {
public:
    enum Colonnina {
        nessuna, lowHome, lowPublic, medium, ultraFast
    };

    enum VelocitaRicarica {
        lenta = 1, media, veloce
    };

    /**
     * @brief MotoreElettrico: Costruttore
     * @param from Veicolo(targa, posizione, km, numeroPosti, ingombro)
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
     * @brief tempoRimanenteCaricaCompleta
     * @return calcola il tempo rimanente al veicolo per ranggiungere il 100% di carica
     */
    short tempoRimanenteCaricaCompleta() const;

    /**
     * @brief percentualeCarica
     * @return calcola la percentuale della batteria in quel momento
     */
    unsigned short percentualeCarica() const;

    /**
     * @brief inCarica
     * @return se il veicolo è in carica
     */
    bool inCarica() const;

private:
    bool _inCarica;
    double _capacitaTotaleBatteria;         // Ampere-ora (Ah) massimi
    double _capacitaAttuale;               // Ampere-ora presenti
    VelocitaRicarica _caricaSupportata;     // la massima velocità alla quale può essere ricaricata (da 1 a 4)
    Colonnina _colonninaAttuale;              // tipo di colonnina alla quale è inCarica

};

#endif // MOTOREELETTRICO_H
