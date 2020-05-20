#ifndef VEICOLO_H
#define VEICOLO_H

#define u_int unsigned short        //  unsigned short abbreviato (da 0 a 65,535)

#include <string>

using std::string;                  //  dichiarazione d'uso per string

class Veicolo {
public:
    enum StatoVeicolo {
        libero, prenotato, occupato, manutenzione
    };

    /**
     * @brief Veicolo: Costruttore
     * @param targa: la targa del veicolo
     * @param posizione: la posizione attuale del veicolo
     * @param km: i chilometri percorsi dal veicolo
     * @param numeroPosti: i posti per cui è omologato il veicolo
     * @param ingombro: le dimensioni del veicolo
     */
    Veicolo(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro);

    /**
     * @brief autonomia o range del veicolo
     * @return
     */
    virtual double autonomia() const =0;

    /**
     * @brief fattoreGreen (-10 a +10)
     * @return
     */
    virtual short int fattoreGreen() const =0;

    /**
     * @brief consumoKm
     * @return consumo al km in base ad alcune caratteristiche
     */
    virtual double consumoKm() const =0;

    /**
     * @brief fattoreUtilizzo
     * @return
     */
    virtual short int fattoreUtilizzo() const;

    /**
     * @brief ~Veicolo: Distruttore
     */
    virtual ~Veicolo();

    string targa() const;
    void setTarga(const string &targa);

    string posizione() const;
    void setPosizione(const string &posizione);

    double chilometraggio() const;
    void setChilometraggio(double chilometraggio);

    unsigned short capacitaPosti() const;
    void setCapacitaPosti(unsigned short capacitaPosti);

    unsigned short ingombro() const;
    void setIngombro(unsigned short ingombro);

    unsigned short numeroUsi() const;
    void setNumeroUsi(unsigned short numeroUsi);

    unsigned long tempoServizio() const;
    void setTempoServizio(unsigned long tempoServizio);

    StatoVeicolo statoAttuale() const;
    void setStatoAttuale(const StatoVeicolo &statoAttuale);

    bool inRiserva() const;
    void setInRiserva(bool inRiserva);

    bool serveAssistenza() const;
    void setServeAssistenza(bool serveAssistenza);

    unsigned short guasti() const;
    void setGuasti(unsigned short guasti);

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
