#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
using std::string;

class Veicolo {
public:

    enum StatoVeicolo {
        libero, prenotato, occupato, manutenzione
    };

    Veicolo();

    Veicolo(
        string targa,
        string posizione,
        unsigned long km,
        unsigned short numeroPosti,
        unsigned short ingombro,
        unsigned short numeroUsi,
        unsigned long tempoServizio,
        Veicolo::StatoVeicolo statoAttuale,
        bool inRiserva,
        bool serveAssistenza,
        unsigned short numeroGuasti);

    virtual ~Veicolo() = 0;

    virtual double consumoKm() const =0;
    virtual double autonomia() const =0;
    virtual short int fattoreGreen() const =0;
    virtual void checkRiserva() =0;

    short int fattoreUtilizzo() const;

    // Metodi get
    string targa() const;
    string posizione() const;
    unsigned long chilometraggio() const;
    unsigned short capacitaPosti() const;
    unsigned short ingombro() const;
    unsigned short numeroUsi() const;
    unsigned long tempoServizio() const;
    StatoVeicolo statoAttuale() const;
    bool inRiserva() const;
    bool serveAssistenza() const;
    unsigned short numeroGuasti() const;

    // Metodi set
    void setStatoAttuale(const StatoVeicolo&);
    void setServeAssistenza(bool);
    void setInRiserva(bool);

private:
    string _targa;                      // Targa del veicolo
    string _posizione;                  // Coordinate in gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    unsigned long _chilometraggio;      // Chilometri percorsi
    unsigned short _capacitaPosti;      // Posti per cui è omologato
    unsigned short _ingombro;           // Dimensioni del veicolo (da 1 a 5)
    unsigned short _numeroUsi;          // Quante volte è stato usato
    unsigned long _tempoServizio;       // Tempo totale di utilizzo in minuti
    StatoVeicolo _statoAttuale;         // Disponibilità (libero, prenotato, occupato, manutenzione)
    bool _inRiserva;                    // Se autonomia < di 30km
    bool _serveAssistenza;              // Se è stata richiesta l'assistenza
    unsigned short _numeroGuasti;       // Quante volte si è guastato
};

#endif // VEICOLO_H
