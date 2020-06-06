#include "MODELS/autoibrida.h"

AutoIbrida::AutoIbrida(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
                       Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int potenza, u_int numeroMotori, double capacitaBatteria, double capacitaAttuale,
                       VelocitaRicarica caricaSupportata, bool inCarica,
                       Colonnina colonninaAttuale, u_int numeroPosti, u_int ingombro):
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
