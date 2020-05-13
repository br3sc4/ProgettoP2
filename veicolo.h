#ifndef VEICOLO_H
#define VEICOLO_H
#define u_int unsigned short    //  unsigned short int abbreviato (da 0 a 65,535)

#include <string>

using std::string;              //  dichiarazione d'uso per string

class veicolo
{
private:
    string targa;
    float prezzoAcquisto;
    u_int capacitaPosti;
    string posizione;           //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    u_int statoAttuale;         //  0 = libero, 1 = occupato, 2 = prenotato, 3 = manutenzione
    float chilometraggio;
    bool inRiserva;
    bool richiedeManutenzione;
    u_int ingombro;             //  in base alla dimensioni del veicolo (da 0 a 5)        (o da 1 a 5 ?)
    u_int emissioni;            //  da 0 a 95g circa per km

public:
    veicolo(string tar, float preA, u_int capP, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi);

    // Tutti i metodi get
    string getTarga() const;
    unsigned short getCapacitaPosti() const;
    string getPosizione() const;
    unsigned short getStatoAttuale() const;
    float getChilometraggio() const;
    bool getInRiserva() const;
    bool getRichiedeManutenzione() const;
    unsigned short getIngombro() const;
    unsigned short getEmissioni() const;
};

#endif // VEICOLO_H
