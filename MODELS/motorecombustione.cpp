#include "MODELS/motorecombustione.h"


MotoreCombustione::MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                     double capacitaSerbatoio,double litriSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _capacitaSerbatoio(capacitaSerbatoio), _litriSerbatoio(litriSerbatoio),
    _tipoCarburante(tipoCarburante), _cilindrata(cilindrata), _emissioni(emissioni) {}

MotoreCombustione::~MotoreCombustione() {}

double MotoreCombustione::capacitaSerbatoio() const
{
    return _capacitaSerbatoio;
}

double MotoreCombustione::litriSerbatoio() const
{
    return _litriSerbatoio;
}

MotoreCombustione::Carburante MotoreCombustione::tipoCarburante() const
{
    return _tipoCarburante;
}

unsigned short MotoreCombustione::cilindrata() const
{
    return _cilindrata;
}

unsigned short MotoreCombustione::emissioni() const
{
    return _emissioni;
};
