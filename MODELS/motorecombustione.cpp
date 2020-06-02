#include "MODELS/motorecombustione.h"


MotoreCombustione::MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                     double capacitaSerbatoio,double litriSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _capacitaSerbatoio(capacitaSerbatoio), _litriSerbatoio(litriSerbatoio),
    _tipoCarburante(tipoCarburante), _cilindrata(cilindrata), _emissioni(emissioni) {}

MotoreCombustione::~MotoreCombustione() {}

double MotoreCombustione::consumoKm() const {
    double consumoGG = ingombro();
    if(tipoCarburante()==0)
        consumoGG = consumoGG * 1.2;
    else if(tipoCarburante()==2 || tipoCarburante()==3)
         consumoGG = consumoGG * 1.5;
    return ((consumoGG * (cilindrata()/1000)) / 100);
}

double MotoreCombustione::autonomia() const {
        return consumoKm()*litriSerbatoio();
}

short int MotoreCombustione::fattoreGreen() const {
    //TODO funzione
    return 1;
}

void MotoreCombustione::checkRiserva() {
    if (autonomia() < 30) setInRiserva(true);
    else setInRiserva(false);
}

double MotoreCombustione::capacitaSerbatoio() const {
    return _capacitaSerbatoio;
}

double MotoreCombustione::litriSerbatoio() const {
    return _litriSerbatoio;
}

MotoreCombustione::Carburante MotoreCombustione::tipoCarburante() const {
    return _tipoCarburante;
}

unsigned short MotoreCombustione::cilindrata() const {
    return _cilindrata;
}

unsigned short MotoreCombustione::emissioni() const {
    return _emissioni;
}

void MotoreCombustione::setCapacitaSerbatoio(double capacitaSerbatoio)
{
    _capacitaSerbatoio = capacitaSerbatoio;
}

void MotoreCombustione::setLitriSerbatoio(double litriSerbatoio)
{
    _litriSerbatoio = litriSerbatoio;
}

void MotoreCombustione::setTipoCarburante(const Carburante &tipoCarburante)
{
    _tipoCarburante = tipoCarburante;
}

void MotoreCombustione::setCilindrata(unsigned short cilindrata)
{
    _cilindrata = cilindrata;
}

void MotoreCombustione::setEmissioni(unsigned short emissioni)
{
    _emissioni = emissioni;
}
