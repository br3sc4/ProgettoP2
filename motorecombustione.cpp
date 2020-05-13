#include "motorecombustione.h"

double motoreCombustione::getCapacitaSerbatoio() const
{
    return capacitaSerbatoio;
}

double motoreCombustione::getLitriSerbatoio() const
{
    return litriSerbatoio;
}

u_int motoreCombustione::getTipoCarburante() const
{
    return tipoCarburante;
}

u_int motoreCombustione::getCilindrata() const
{
    return cilindrata;
}

motoreCombustione::motoreCombustione(string tar, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi,
                                     double capS, double litS, u_int tipC, u_int cil):
veicolo(tar, pos, staA, km, inR, ricM, ing, emi),capacitaSerbatoio(capS), litriSerbatoio(litS), tipoCarburante(tipC), cilindrata(cil)
{

}
