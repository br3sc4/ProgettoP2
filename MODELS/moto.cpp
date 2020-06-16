#include "MODELS/moto.h"

Moto::Moto(string targa, string posizione, double km, double capacitaSerbatoio, double litriSerbatoio,
           Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni, unsigned short numeroPosti, unsigned short ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni) {}
