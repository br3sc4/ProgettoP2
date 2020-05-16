#include "motorecombustione.h"


MotoreCombustione::MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                     double capacitaSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _capacitaSerbatoio(capacitaSerbatoio), _litriSerbatoio(capacitaSerbatoio),
    _tipoCarburante(tipoCarburante), _cilindrata(cilindrata), _emissioni(emissioni) {}

MotoreCombustione::~MotoreCombustione() {};
