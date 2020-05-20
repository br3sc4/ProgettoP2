#include "moto.h"

Moto::Moto(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni):
    Veicolo(targa, posizione, km, numeroPosti, ingombro),
    MotoreCombustione(targa, posizione, km, numeroPosti, ingombro, capacitaSerbatoio, tipoCarburante, cilindrata, emissioni){}
