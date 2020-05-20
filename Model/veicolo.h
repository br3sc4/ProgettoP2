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
     * @brief Veicolo: costruttore
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
     * @brief ~Veicolo: distruttore
     */
    virtual ~Veicolo();

    /**
     * @brief targa: metodo get per _targa
     * @return
     */
    string targa() const;

    /**
     * @brief setTarga: metodo set per _targa
     * @param targa
     */
    void setTarga(const string &targa);

    /**
     * @brief posizione: metodo get per _posizione
     * @return
     */
    string posizione() const;

    /**
     * @brief setPosizione: metodo set per _posizione
     * @param posizione
     */
    void setPosizione(const string &posizione);

    /**
     * @brief chilometraggio: metodo get per _chilometraggio
     * @return
     */
    double chilometraggio() const;

    /**
     * @brief setChilometraggio: metodo set per _chilometraggio
     * @param chilometraggio
     */
    void setChilometraggio(double chilometraggio);

    /**
     * @brief capacitaPosti: metodo get per _capacitaPosti
     * @return
     */
    unsigned short capacitaPosti() const;

    /**
     * @brief setCapacitaPosti: metodo set per _capacitaPosti
     * @param capacitaPosti
     */
    void setCapacitaPosti(unsigned short capacitaPosti);

    /**
     * @brief ingombro: metodo get per _ingombro
     * @return
     */
    unsigned short ingombro() const;

    /**
     * @brief setIngombro: metodo set per _ingombro
     * @param ingombro
     */
    void setIngombro(unsigned short ingombro);

    /**
     * @brief numeroUsi: metodo get per _numeroUsi
     * @return
     */
    unsigned short numeroUsi() const;

    /**
     * @brief setNumeroUsi: metodo set per _numeroUsi
     * @param numeroUsi
     */
    void setNumeroUsi(unsigned short numeroUsi);

    /**
     * @brief tempoServizio: metodo get per _tempoServizio
     * @return
     */
    unsigned long tempoServizio() const;

    /**
     * @brief setTempoServizio: metodo set per _tempoServizio
     * @param tempoServizio
     */
    void setTempoServizio(unsigned long tempoServizio);

    /**
     * @brief statoAttuale: metodo get per _statoAttuale
     * @return
     */
    StatoVeicolo statoAttuale() const;

    /**
     * @brief setStatoAttuale: metodo set per _statoAttuale
     * @param statoAttuale
     */
    void setStatoAttuale(const StatoVeicolo &statoAttuale);

    /**
     * @brief inRiserva: metodo get per _inRiserva
     * @return
     */
    bool inRiserva() const;

    /**
     * @brief setInRiserva: metodo set per _inRiserva
     * @param inRiserva
     */
    void setInRiserva(bool inRiserva);

    /**
     * @brief serveAssistenza: metodo get per _serveAssistenza
     * @return
     */
    bool serveAssistenza() const;

    /**
     * @brief setServeAssistenza: metodo set per _serveAssistenza
     * @param serveAssistenza
     */
    void setServeAssistenza(bool serveAssistenza);

    /**
     * @brief guasti: metodo get per _guasti
     * @return
     */
    unsigned short guasti() const;

    /**
     * @brief setGuasti: metodo set per _guasti
     * @param guasti
     */
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
