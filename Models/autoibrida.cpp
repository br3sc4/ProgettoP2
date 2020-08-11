#include "Models/autoibrida.h"

AutoIbrida::AutoIbrida(
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
    bool inCarica,
    Colonnina colonninaAttuale,
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

    MotoreCombustione(
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
        numeroGuasti,
        capacitaSerbatoio,
        litriSerbatoio,
        tipoCarburante,
        cilindrata,
        emissioni),

    MotoreElettrico(
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
        numeroGuasti,
        potenza,
        numeroMotori,
        inCarica,
        capacitaBatteria,
        capacitaAttuale,
        caricaSupportata,
        colonninaAttuale) {}

double AutoIbrida::autonomia() const {
    return MotoreCombustione::autonomia() + MotoreElettrico::autonomia();
}

short AutoIbrida::fattoreGreen() const {
    short int somma = 2 + MotoreElettrico::fattoreGreen() + MotoreCombustione::fattoreGreen();

    if(somma < -10) return -10;
    if(somma > 10)  return 10;

    return somma;
}

double AutoIbrida::consumoKm() const {
    return MotoreElettrico::consumoKm() + MotoreCombustione::consumoKm();
}

void AutoIbrida::checkRiserva() {
    if(MotoreCombustione::autonomia() < (capacitaSerbatoio()/MotoreCombustione::consumoKm())*0.3 &&
       MotoreElettrico::autonomia() < (capacitaBatteria()/MotoreElettrico::consumoKm())*0.3)
       setInRiserva(true);
    else setInRiserva(false);
}
