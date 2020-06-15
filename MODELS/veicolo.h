#ifndef VEICOLO_H
#define VEICOLO_H

#define u_int unsigned short
#include <string>
using std::string;

class Veicolo {
public:

    enum StatoVeicolo {
        libero, prenotato, occupato, manutenzione
    };

    Veicolo();

    /**
     * @brief costruttore Veicolo
     * @param targa
     * @param posizione
     * @param km
     * @param numeroPosti
     * @param ingombro
     */
    Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro);

    virtual ~Veicolo();

    virtual double consumoKm() const =0;
    virtual double autonomia() const =0;
    virtual short int fattoreGreen() const =0;
    virtual void checkRiserva();
    short int fattoreUtilizzo() const;

    // metodi get
    string targa() const;
    string posizione() const;
    double chilometraggio() const;
    unsigned short capacitaPosti() const;
    unsigned short ingombro() const;
    unsigned short numeroUsi() const;
    unsigned long tempoServizio() const;
    StatoVeicolo statoAttuale() const;
    bool inRiserva() const;
    bool serveAssistenza() const;
    unsigned short guasti() const;

    // metodi set
    void setPosizione(const string& posizione);
    void setStatoAttuale(const StatoVeicolo& statoAttuale);
    void setServeAssistenza(bool serveAssistenza);

    // metodi incremento
    void increaseChilometraggio(double chilometraggio);
    void increaseNumeroUsi(unsigned short numeroUsi);
    void increaseTempoServizio(unsigned long tempoServizio);
    void increaseGuasti(unsigned short guasti);

private:
    string _targa;                  // Targa del veicolo
    string _posizione;              // Coordinate in gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    double _chilometraggio;         // Chilometri percorsi
    u_int _capacitaPosti;           // Posti per cui è omologato
    u_int _ingombro;                // Dimensioni del veicolo (da 1 a 5)

    u_int _numeroUsi;               // Quante volte è stato usato
    unsigned long _tempoServizio;   // Tempo totale di utilizzo in minuti
    StatoVeicolo _statoAttuale;     // Disponibilità (libero, prenotato, occupato, manutenzione)
    bool _inRiserva;                // Se autonomia < di 30km
    bool _serveAssistenza;          // Se è stata richiesta l'assistenza
    u_int _guasti;                  // Quante volte si è guastato
};

#endif // VEICOLO_H
