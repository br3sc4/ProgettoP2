#include "autoibrida.h"

AutoIbrida::AutoIbrida(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
                       Carburante tipoCarburante, u_int cilindrata, u_int emissioni, double capacitaBatteria, VelocitaRicarica caricaSupportata,
                       u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni),
    MotoreElettrico(targa, posizione, km, numeroPosti, ingombro, capacitaBatteria, caricaSupportata) {}
