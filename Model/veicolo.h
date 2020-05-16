#ifndef VEICOLO_H
#define VEICOLO_H

#define u_int unsigned short        //  unsigned short abbreviato (da 0 a 65,535)

#include <string>

using std::string;                  //  dichiarazione d'uso per string

class Veicolo {
public:

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
     * @brief autonomia
     * @return
     */
    virtual double autonomia() const =0;            // range del veicolo dato da litri o ampere * consumo

    /**
     * @brief fattoreGreen
     * @return
     */
    virtual short int fattoreGreen() const =0;      // da -10 a +10

    /**
     * @brief autonomia
     * @return
     */
    virtual double autonomia() =0;

    /**
     * @brief consumoKm
     * @return calcola il consumo del veicolo in base alle sue caratteristiche
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

    typedef enum {
        libero, prenotato, occupato, manutenzione
    } StatoVeicolo;

private:
    string _targa;
    string _posizione;              //  gradi decimali con 4 cifre dopo il punto es: "41.8902, 12.4922"
    double _chilometraggio;
    u_int _capacitaPosti;
    u_int _ingombro;                //  in base alla dimensioni del veicolo (da 0 a 5)        (o da 1 a 5 ?)
    u_int _numeroUsi;               //  quante volte è stato usato
    unsigned long _tempoServizio;   //  tempo totale di utilizzo in minuti
    StatoVeicolo _statoAttuale;
    bool _inRiserva;                //  se autonomia < di 30km
    bool _serveAssistenza;
    u_int _guasti;                  //  quante volte si è rotto
};

#endif // VEICOLO_H
