#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"

class motoreElettrico : public veicolo
{
private:
    bool inCarica;
    double capacitaBatteria;        // Ampere-ora (Ah) massimi
    double ampereBatteria;          // Ampere-ora presenti
    u_int caricaSupportata;        // la massima velocità alla quale può essere ricaricata (da 1 a 4)
    u_int velocitaCarica;           // tipo di colonnina alla quale è inCarica (da 1 a 4)

public:
    // Costruttore
    motoreElettrico();

    // Metodi virtuali
    virtual ~motoreElettrico();

};

#endif // MOTOREELETTRICO_H
