#include "MODELS/header/moto.h"

Moto::Moto(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
           Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int numeroPosti, u_int ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni) {}