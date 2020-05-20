#include "automobile.h"

Automobile::Automobile(string targa, string posizione, double km, double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni, u_int numeroPosti, u_int ingombro): Veicolo(targa, posizione, km, numeroPosti, ingombro), MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, tipoCarburante, cilindrata, emissioni) {}
