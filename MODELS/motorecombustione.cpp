#include "Models/motorecombustione.h"

MotoreCombustione::MotoreCombustione(
    string targa,
    string posizione,
    unsigned long km,
    unsigned short numeroPosti,
    unsigned short ingombro,
    unsigned short numeroUsi,
    unsigned long tempoServizio,
    StatoVeicolo statoAttuale,
    bool inRiserva,
    bool serveAssistenza,
    unsigned short numeroGuasti,
    double capacitaSerbatoio,
    double litriSerbatoio,
    Carburante tipoCarburante,
    unsigned short cilindrata,
    unsigned short emissioni):

    Veicolo(
        targa,
        posizione,
        km,
        numeroPosti,
        ingombro,
        numeroUsi,
        tempoServizio,
        statoAttuale,
        inRiserva,
        serveAssistenza,
        numeroGuasti),

    _capacitaSerbatoio(capacitaSerbatoio),
    _litriSerbatoio(litriSerbatoio),
    _tipoCarburante(tipoCarburante),
    _cilindrata(cilindrata),
    _emissioni(emissioni) {}

MotoreCombustione::~MotoreCombustione() = default;

double MotoreCombustione::consumoKm() const {
    double consumo;

    if(ingombro()<3)
        consumo = 1;
    else
        consumo = ingombro();

    if(_tipoCarburante == benzina)
        consumo = consumo * 1.1;
    else if(tipoCarburante() == gpl || tipoCarburante() == metano)
         consumo = consumo * 1.4;

    if(ingombro()<3)
        return consumo * (_cilindrata / 100);
    else
         return consumo * (_cilindrata / 1000);
}

double MotoreCombustione::autonomia() const {
    return litriSerbatoio() / consumoKm();
}

void MotoreCombustione::checkRiserva() {
    if (autonomia() < (capacitaSerbatoio()/consumoKm())*0.3) setInRiserva(true);
    else setInRiserva(false);
}

short int MotoreCombustione::fattoreGreen() const {
    double somma = 0;
    if(_tipoCarburante == benzina)
        somma = somma - 2;                  // benzina negativo
    else if(_tipoCarburante == diesel)
        somma = somma - 3;                  // diesel negativo
    else somma = somma - 1;                 // metano, gpl negativo
    somma = somma - _cilindrata / 100;      // cilindrata negativo
    somma = somma - _emissioni / 10;        // emissioni negativo

    if(ingombro() <= 2)
        somma = somma + 1;                  // meno ingombro positivo
    if(capacitaPosti() > 1)
        somma = somma + 2;                  // piu' posti positivo
    if(numeroGuasti() <= 10)
        somma = somma + 1;                  // meno guasti positivo

    if(somma < -10) return -10;
    if(somma > 10)  return 10;

    return somma;
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

void MotoreCombustione::setLitriSerbatoio(double litriSerbatoio) {
    _litriSerbatoio = litriSerbatoio;
}
