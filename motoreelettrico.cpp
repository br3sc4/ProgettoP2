#include "motoreelettrico.h"

bool motoreElettrico::getInCarica() const
{
    return inCarica;
}

double motoreElettrico::getCapacitaBatteria() const
{
    return capacitaBatteria;
}

double motoreElettrico::getAmpereBatteria() const
{
    return ampereBatteria;
}

u_int motoreElettrico::getCaricaSupportata() const
{
    return caricaSupportata;
}

u_int motoreElettrico::getVelocitaCarica() const
{
    return velocitaCarica;
}

motoreElettrico::motoreElettrico(string tar, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi,
                                 bool inC, double capB, double ampB, u_int carS, u_int velC):
    veicolo(tar, pos, staA, km, inR, ricM, ing, emi), inCarica(inC), capacitaBatteria(capB), ampereBatteria(ampB), caricaSupportata(carS), velocitaCarica(velC)
{

}
