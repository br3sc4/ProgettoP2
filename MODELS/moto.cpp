#include "MODELS/moto.h"

Moto::Moto(
        string targa,
        string posizione,
        unsigned long km,
        double capacitaSerbatoio,
        double litriSerbatoio,
        Carburante tipoCarburante,
        unsigned short cilindrata,
        unsigned short emissioni,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti,
        unsigned short numeroPosti,
        unsigned short ingombro):

    Veicolo(
        targa,
        posizione,
        km,
        numeroPosti,
        ingombro,
        numeroUsi,
        tempoServizio,
        statoAttuale,
        inRiserva,
        serveAssistenza,
        numeroGuasti),

        MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, numeroUsi,
                          tempoServizio, statoAttuale, inRiserva, serveAssistenza,
                          numeroGuasti, capacitaSerbatoio, litriSerbatoio,
                          tipoCarburante, cilindrata, emissioni) {}
