#ifndef VEICOLO_H
#define VEICOLO_H
#define u_int unsigned short    //  unsigned short int abbreviato (da 0 a 65,535)

#include <string>

using std::string;              //  dichiarazione d'uso per string

class veicolo
{
private:
    string targa;
    //float prezzoAcquisto;     // possiamo toglierlo? Oppure ci interessa quanto abbiamo speso per un veicolo?
    //u_int capacitaPosti;      // anche questo non saprei se ci può essere utile
    string posizione;           //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    u_int statoAttuale;         //  0 = libero, 1 = occupato, 2 = prenotato, 3 = manutenzione
    float chilometraggio;
    bool inRiserva;
    bool richiedeManutenzione;
    u_int ingombro;             //  in base alla dimensioni del veicolo (da 0 a 5)        (o da 1 a 5 ?)
    u_int emissioni;            //  da 0 a 95g circa per km

public:
    // Costruttore
    veicolo(string tar, float preA, u_int capP, string pos, u_int staA, float km, bool inR, bool ricM, u_int ing, u_int emi);

    // Metodi virtuali
    virtual float consumoKm() const =0;
    virtual float distanzaPercorribile() const =0;      // range del veicolo dato da litri serbatoio o kw batteria * consumo al km
    virtual short int fattoreGreen() const =0;          // da -10 a +10
    virtual ~veicolo();                                 // non mi fa mettere const o default qua...

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
