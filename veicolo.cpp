#include "veicolo.h"

string veicolo::getTarga() const
{
    return targa;
}

unsigned short veicolo::getCapacitaPosti() const
{
    return capacitaPosti;
}

string veicolo::getPosizione() const
{
    return posizione;
}

unsigned short veicolo::getStatoAttuale() const
{
    return statoAttuale;
}

float veicolo::getChilometraggio() const
{
    return chilometraggio;
}

bool veicolo::getInRiserva() const
{
    return inRiserva;
}

bool veicolo::getRichiedeManutenzione() const
{
    return richiedeManutenzione;
}

unsigned short veicolo::getIngombro() const
{
    return ingombro;
}

unsigned short veicolo::getEmissioni() const
{
    return emissioni;
}

veicolo::veicolo(std::string tar, float preA, unsigned short capP, std::string pos, unsigned short staA, float km, bool inR, bool ricM, unsigned short ing, unsigned short emi)
    : targa(tar), prezzoAcquisto(preA), capacitaPosti(capP), posizione(pos), statoAttuale(staA), chilometraggio(km), inRiserva(inR), richiedeManutenzione(ricM), ingombro(ing), emissioni(emi)
{

}
