#include "MODELS/autoibrida.h"

AutoIbrida::AutoIbrida(string targa, string posizione, unsigned long km, double capacitaSerbatoio, double litriSerbatoio,
                       Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni, unsigned short potenza, unsigned short numeroMotori, double capacitaBatteria, double capacitaAttuale,
                       VelocitaRicarica caricaSupportata, bool inCarica,
                       Colonnina colonninaAttuale, unsigned short numeroPosti, unsigned short ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale) {}

double AutoIbrida::autonomia() const {
    return (MotoreCombustione::consumoKm() * litriSerbatoio()) + (MotoreElettrico::consumoKm() * capacitaAttuale());
}

short AutoIbrida::fattoreGreen() const {
    short int somma = MotoreElettrico::fattoreGreen() + MotoreCombustione::fattoreGreen();

    if(somma < -10) return -10;
    if(somma > 10)  return 10;

    return somma;
}

double AutoIbrida::consumoKm() const {
    return MotoreElettrico::consumoKm() + MotoreCombustione::consumoKm();
}
