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
    motoreElettrico(string tar, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi,
                    bool inC, double capB, double ampB, u_int carS, u_int velC);

    // Metodi virtuali

    // Metodi get
    bool getInCarica() const;
    double getCapacitaBatteria() const;
    double getAmpereBatteria() const;
    u_int getCaricaSupportata() const;
    u_int getVelocitaCarica() const;
};

#endif // MOTOREELETTRICO_H
