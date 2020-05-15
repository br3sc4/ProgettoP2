#ifndef VEICOLO_H
#define VEICOLO_H

#define u_int unsigned short        //  unsigned short abbreviato (da 0 a 65,535)

#include <string>

using std::string;                  //  dichiarazione d'uso per string

class Veicolo {
public:

    /**
     * @brief Veicolo: Costruttore della classe astratta
     * @param targa
     * @param posizione
     * @param km
     * @param numeroPosti
     * @param ingombro
     * @param emissioni
     */
    Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro, u_int emissioni);

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
    string _targa;
    string _posizione;               //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    double _chilometraggio;
    u_int _capacitaPosti;
    u_int _ingombro;                 //  in base alla dimensioni del veicolo (da 0 a 5)        (o da 1 a 5 ?)
    u_int _emissioni;                //  da 0 a 95g circa per km
    u_int _numeroUsi;                //  quante volte è stato usato
    unsigned long _tempoServizio;            //  tempo totale di utilizzo in minuti
    StatoVeicolo _statoAttuale;
    bool _inRiserva;                 //  se autonomia < di 30km
    bool _serveAssistenza;
    u_int _guasti;                   //  quante volte si è rotto
};

#endif // VEICOLO_H
