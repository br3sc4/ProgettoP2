#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>

#define u_int unsigned short        //  unsigned short abbreviato (NB da 0 a 65,535)

using std::string;                  //  dichiarazione d'uso per string

class Veicolo {
public:
    enum StatoVeicolo {
        libero, prenotato, occupato, manutenzione
    };

    // costruttore di default
    Veicolo();

    /**
     * @brief Veicolo: costruttore
     * @param targa: la targa del veicolo
     * @param posizione: la posizione attuale del veicolo
     * @param km: i chilometri percorsi dal veicolo
     * @param numeroPosti: i posti per cui è omologato il veicolo
     * @param ingombro: le dimensioni del veicolo
     */
    Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro);

     // distruttore virtuale
     virtual ~Veicolo();

    // consumo al km in base ad alcune caratteristiche
    virtual double consumoKm() const =0;

    // autonomia (o range) del veicolo
    virtual double autonomia() const =0;

    // fattoreGreen (-10 a +10)
    virtual short int fattoreGreen() const =0;

    // controlla autonomia e setta inRiserva
    virtual void checkRiserva();

    // fattoreUtilizzo
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
    string _targa;
    string _posizione;              //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    double _chilometraggio;
    u_int _capacitaPosti;
    u_int _ingombro;                //  dimensioni del veicolo (da 1 a 5)
    u_int _numeroUsi;               //  quante volte è stato usato
    unsigned long _tempoServizio;   //  tempo totale di utilizzo in minuti
    StatoVeicolo _statoAttuale;
    bool _inRiserva;                //  se autonomia < di 30km
    bool _serveAssistenza;
    u_int _guasti;                  //  quante volte si è rotto
};

#endif // VEICOLO_H
