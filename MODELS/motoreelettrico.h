#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"
#include "EXCEPTIONS/notinchargeexception.h"

class MotoreElettrico : virtual public Veicolo {
public:
    enum Colonnina {
        nessuna, lowHome, lowPublic, medium, ultraFast
    };

    enum VelocitaRicarica {
        lenta = 1, media, veloce
    };

    /**
     * @brief Costruttore
     * @param from Veicolo(targa, posizione, km, numeroPosti, ingombro)
     * @param capacitaBatteria: la capacità totale della batteria del veicolo
     * @param caricaSupportata: la velocità di carica a cui può essere caricato il veicolo
     */
    MotoreElettrico(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                    u_int potenza, u_int numeroMotori, bool inCarica, double capacitaBatteria, double capacitaAttuale, VelocitaRicarica caricaSupportata, Colonnina colonninaAttuale);

    virtual ~MotoreElettrico();

    // metodi virtuali implementati
    virtual double consumoKm() const;
    virtual double autonomia() const;
    virtual short int fattoreGreen() const;

    // calcola il tempo rimanente al veicolo per ranggiungere il 100% di carica
    short tempoRimanenteCaricaCompleta() const;

    // calcola la percentuale della batteria in quel momento
    unsigned short percentualeCarica() const;

    // metodi get
    bool inCarica() const;
    double capacitaBatteria() const;
    double capacitaAttuale() const;
    VelocitaRicarica caricaSupportata() const;
    Colonnina colonninaAttuale() const;

    // metodi set
    void setInCarica(bool inCarica, Colonnina colonnina = nessuna);
    void setCapacitaAttuale(double capacitaAttuale);

private:
    const u_int _potenza;                       // Potenza del motore
    const u_int _numeroMotori;                  // Il numero di motori presenti (da 1 a 4)
    bool _inCarica;                             // E' in carica ?
    const double _capacitaBatteria;             // Ampere-ora (Ah) massimi
    double _capacitaAttuale;                    // Ampere-ora presenti
    const VelocitaRicarica _caricaSupportata;   // la massima velocità alla quale può essere ricaricata (da 1 a 4)
    Colonnina _colonninaAttuale;                // tipo di colonnina alla quale è inCarica

};

#endif // MOTOREELETTRICO_H
