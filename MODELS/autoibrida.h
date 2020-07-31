#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H

#include "motorecombustione.h"
#include "motoreelettrico.h"

class AutoIbrida: public MotoreCombustione, public MotoreElettrico
{
public:
    AutoIbrida(
        string targa,
        string posizione,
        unsigned long km,
        double capacitaSerbatoio,
        double litriSerbatoio,
        Carburante tipoCarburante,
        unsigned short cilindrata,
        unsigned short emissioni,
        unsigned short potenza,
        unsigned short numeroMotori,
        double capacitaBatteria,
        double capacitaAttuale,
        VelocitaRicarica caricaSupportata,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti,
        bool inCarica = false,
        Colonnina colonninaAttuale = nessuna,
        unsigned short numeroPosti = 2,
        unsigned short ingombro = 3);

    double autonomia() const;

    short int fattoreGreen() const;

    double consumoKm() const;

};

#endif // AUTOIBRIDA_H
