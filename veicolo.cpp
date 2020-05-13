#include "veicolo.h"

string veicolo::getTarga() const
{
    return targa;
}

string veicolo::getPosizione() const
{
    return posizione;
}

u_int veicolo::getStatoAttuale() const
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

u_int veicolo::getIngombro() const
{
    return ingombro;
}

u_int veicolo::getEmissioni() const
{
    return emissioni;
}

veicolo::veicolo(string tar, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi)
    : targa(tar), posizione(pos), statoAttuale(staA), chilometraggio(km), inRiserva(inR), richiedeManutenzione(ricM), ingombro(ing), emissioni(emi)
{

}
