#include "Models/motoreelettrico.h"

MotoreElettrico::MotoreElettrico(
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
    unsigned int potenza,
    unsigned short numeroMotori,
    bool inCarica,
    double capacitaBatteria,
    double capacitaAttuale,
    VelocitaRicarica caricaSupportata,
    Colonnina colonninaAttuale):

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

    _potenza(potenza),
    _numeroMotori(numeroMotori),
    _inCarica(inCarica),
    _capacitaBatteria(capacitaBatteria),
    _capacitaAttuale(capacitaAttuale),
    _caricaSupportata(caricaSupportata),
    _colonninaAttuale(colonninaAttuale) {}

MotoreElettrico::~MotoreElettrico() = default;

double MotoreElettrico::consumoKm() const {
    if(ingombro()<=2)
         return _potenza/10 / _numeroMotori;
    return  _potenza/1000 / _numeroMotori;
}

double MotoreElettrico::autonomia() const {
    return capacitaAttuale() / consumoKm();
}

void MotoreElettrico::checkRiserva() {
    if (autonomia() < (capacitaBatteria()/consumoKm())*0.3) setInRiserva(true);
    else setInRiserva(false);
}

short int MotoreElettrico::fattoreGreen() const {
    short int somma = 2;
    if(ingombro() == 1)
        somma = somma + 3;                          // meno ingombro positivo
    else if(ingombro() == 2 || ingombro() == 3)
        somma = somma + 2;
    else    somma = somma + 1;
    if(capacitaPosti() > 1)
        somma = somma + 2;                          // piu' posti positivo
    if(numeroGuasti() <= 5)
        somma = somma + 2;                          // meno guasti positivo
    else if(numeroGuasti() < 10)
        somma = somma + 1;

    return somma;
}

short MotoreElettrico::tempoRimanenteCaricaCompleta() const {
    if (_inCarica) {
        int _capacitaColonnina = 0;
        if (_caricaSupportata == lenta)
            _capacitaColonnina = 16;
        else if (_caricaSupportata == media)
            _capacitaColonnina = 63;
        else
            _capacitaColonnina = 200;
        return _capacitaBatteria / _capacitaColonnina;
    } else
        throw NotInChargeException();
}

unsigned short MotoreElettrico::percentualeCarica() const {
    return (_capacitaAttuale * 100) / _capacitaBatteria;
}

bool MotoreElettrico::inCarica() const {
    return _inCarica;
}

double MotoreElettrico::capacitaBatteria() const {
    return _capacitaBatteria;
}

double MotoreElettrico::capacitaAttuale() const {
    return _capacitaAttuale;
}

MotoreElettrico::VelocitaRicarica MotoreElettrico::caricaSupportata() const {
    return _caricaSupportata;
}

MotoreElettrico::Colonnina MotoreElettrico::colonninaAttuale() const {
    return _colonninaAttuale;
}

void MotoreElettrico::setInCarica(bool inCarica, Colonnina colonnina) {
    _inCarica = inCarica;
    _colonninaAttuale = colonnina;
}

void MotoreElettrico::setCapacitaAttuale(double capacitaAttuale)
{
    _capacitaAttuale = capacitaAttuale;
}
