#ifndef VEICOLO_H
#define VEICOLO_H

#define u_int unsigned short        //  unsigned short abbreviato (da 0 a 65,535)

#include <string>

using std::string;                  //  dichiarazione d'uso per string

class Veicolo {
public:
    // Costruttore
    Veicolo();

    // Metodi virtuali
    virtual double autonomia() const =0;      // range del veicolo dato da litri o ampere * consumo
    virtual short int fattoreGreen() const =0;          // da -10 a +10
    virtual double autonomia() =0;
    virtual double consumoKm() const =0;
    virtual short int fattoreUtilizzo() const;
    virtual ~Veicolo();

    typedef enum {
        libero, prenotato, occupato, manutenzione
    } StatoVeicolo;

private:
    string targa;
    float chilometraggio;
    u_int numeroUsi;                //  quante volte è stato usato
    float tempoServizio;            //  tempo totale di utilizzo in minuti
    StatoVeicolo statoAttuale;
    u_int ingombro;                 //  in base alla dimensioni del veicolo (da 0 a 5)        (o da 1 a 5 ?)
    u_int emissioni;                //  da 0 a 95g circa per km
    bool inRiserva;                 //  se autonomia < di 30km
    bool serveAssistenza;
    u_int guasti;                   //  quante volte si è rotto
    string posizione;               //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    u_int capacitaPosti;
};

#endif // VEICOLO_H
