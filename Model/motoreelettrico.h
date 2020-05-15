#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"

class MotoreElettrico : public Veicolo {
public:
    // Costruttore
    MotoreElettrico();

    // Metodi virtuali
    virtual ~MotoreElettrico();
    unsigned tempoRimanenteCaricaCompleta() const;
    unsigned short percentualeCarica() const;
    virtual double consumoKm() const;

    typedef enum {
        lenta, media, veloce, gigaveloce
    } Colonnina;

private:
    bool inCarica;
    double capacitaBatteria;        // Ampere-ora (Ah) massimi
    double ampereBatteria;          // Ampere-ora presenti
    u_int caricaSupportata;        // la massima velocità alla quale può essere ricaricata (da 1 a 4)
    Colonnina velocitaCarica;           // tipo di colonnina alla quale è inCarica (da 1 a 4)
};

#endif // MOTOREELETTRICO_H
