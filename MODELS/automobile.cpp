#include "MODELS/automobile.h"

Automobile::Automobile(string targa, string posizione, unsigned long km, double capacitaSerbatoio, double litriSerbatoio,
                       Carburante tipoCarburante, unsigned short cilindrata, unsigned short emissioni, unsigned short numeroPosti, unsigned short ingombro):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, litriSerbatoio, tipoCarburante, cilindrata, emissioni) {}
