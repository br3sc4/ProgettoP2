#include "MODELS/autoibrida.h"

AutoIbrida::AutoIbrida(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
                       Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int potenza, u_int numeroMotori, double capacitaBatteria, double capacitaAttuale,
                       VelocitaRicarica caricaSupportata, bool inCarica,
                       Colonnina colonninaAttuale, u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, potenza, numeroMotori, inCarica, capacitaBatteria, capacitaAttuale, caricaSupportata, colonninaAttuale) {}

double AutoIbrida::autonomia() const {
    return (consumoKm() * litriSerbatoio()) + (consumoKm() * capacitaAttuale());
}

short AutoIbrida::fattoreGreen() const {
    return 0;
}

double AutoIbrida::consumoKm() const {
    return 0;
}

short AutoIbrida::fattoreUtilizzo() const{
    return 0;
}
