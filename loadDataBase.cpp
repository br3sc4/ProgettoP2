#include "model.h"
#include "EXCEPTIONS/filenotfound.h"

#include <fstream>

void loadCitta(Model& model) {
  std::ifstream dBCitta("database/dataBaseCitta.txt");
  if (dBCitta.is_open()) {
    string nomeCitta;
    while (dBCitta >> nomeCitta) {
      model.addCity(new Citta(nomeCitta));
    }
  } else
    throw FileNotFound(0);
  dBCitta.close();
}

void loadVeicoli(Model& model) {
  std::ifstream dBBiciclette("database/dataBaseBiciclette.txt");
  if (dBBiciclette.is_open()) {
    int citta, km, numPost, ingombro, potenza, numMotori, inCarica, caricaSupp,
        colonninaAtt;
    string targa, posizione;
    double capBatteria, capAttuale;
    while (dBBiciclette >> citta >> targa >> posizione >> km >> potenza >>
           numMotori >> capBatteria >> capAttuale >> caricaSupp >> inCarica >>
           colonninaAtt >> numPost >> ingombro) {
      model.addVehicle(
          citta,
          new Bicicletta(
              targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
              static_cast<Bicicletta::VelocitaRicarica>(caricaSupp), inCarica,
              static_cast<Bicicletta::Colonnina>(colonninaAtt), numPost,
              ingombro));
    }
  } else
    throw FileNotFound(1);
  dBBiciclette.close();

  std::ifstream dBAutomobili("database/dataBaseAutomobili.txt");
  if (dBAutomobili.is_open()) {
    int citta, km, carburante, cilindrata, emissioni, numPost, ingombro;
    string targa, posizione;
    double capSerba, litSerba;
    while (dBAutomobili >> citta >> targa >> posizione >> km >> capSerba >>
           litSerba >> carburante >> cilindrata >> emissioni >> numPost >>
           ingombro) {
      model.addVehicle(
          citta, new Automobile(targa, posizione, km, capSerba, litSerba,
                                static_cast<Automobile::Carburante>(carburante),
                                cilindrata, emissioni, numPost, ingombro));
    }
  } else
    throw FileNotFound(2);
  dBAutomobili.close();

  std::ifstream dBAutoElettriche("database/dataBaseAutoElettriche.txt");
  if (dBAutoElettriche.is_open()) {
    int citta, km, numPost, ingombro, potenza, numMotori, inCarica, caricaSupp,
        colonninaAtt;
    string targa, posizione;
    double capBatteria, capAttuale;
    while (dBAutoElettriche >> citta >> targa >> posizione >> km >> potenza >>
           numMotori >> capBatteria >> capAttuale >> caricaSupp >> inCarica >>
           colonninaAtt >> numPost >> ingombro) {
      model.addVehicle(
          citta,
          new AutomobileElettrica(
              targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
              static_cast<AutomobileElettrica::VelocitaRicarica>(caricaSupp),
              inCarica,
              static_cast<AutomobileElettrica::Colonnina>(colonninaAtt),
              numPost, ingombro));
    }
  } else
    throw FileNotFound(3);
  dBAutoElettriche.close();

  std::ifstream dBAutoIbride("database/dataBaseAutoIbride.txt");
  if (dBAutoIbride.is_open()) {
    int citta, km, carburante, cilindrata, emissioni, numPost, ingombro,
        potenza, numMotori, inCarica, caricaSupp, colonninaAtt;
    string targa, posizione;
    double capBatteria, capAttuale, capSerba, litSerba;
    while (dBAutoIbride >> citta >> targa >> posizione >> km >> capSerba >>
           litSerba >> carburante >> cilindrata >> emissioni >> potenza >>
           numMotori >> capBatteria >> capAttuale >> caricaSupp >> inCarica >>
           colonninaAtt >> numPost >> ingombro) {
      model.addVehicle(
          citta,
          new AutoIbrida(
              targa, posizione, km, capSerba, litSerba,
              static_cast<AutoIbrida::Carburante>(carburante), cilindrata,
              emissioni, potenza, numMotori, capBatteria, capAttuale,
              static_cast<AutoIbrida::VelocitaRicarica>(caricaSupp), inCarica,
              static_cast<AutoIbrida::Colonnina>(colonninaAtt), numPost,
              ingombro));
    }
  } else
    throw FileNotFound(4);
  dBAutoIbride.close();

  std::ifstream dBMonopattini("database/dataBaseMonopattini.txt");
  if (dBMonopattini.is_open()) {
    int citta, km, numPost, ingombro, potenza, numMotori, inCarica, caricaSupp,
        colonninaAtt;
    string targa, posizione;
    double capBatteria, capAttuale;
    while (dBMonopattini >> citta >> targa >> posizione >> km >> potenza >>
           numMotori >> capBatteria >> capAttuale >> caricaSupp >> inCarica >>
           colonninaAtt >> numPost >> ingombro) {
      model.addVehicle(
          citta,
          new Monopattino(
              targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
              static_cast<Monopattino::VelocitaRicarica>(caricaSupp), inCarica,
              static_cast<Monopattino::Colonnina>(colonninaAtt), numPost,
              ingombro));
    }
  } else
    throw FileNotFound(5);
  dBMonopattini.close();

  std::ifstream dBMotoElettriche("database/dataBaseMotoElettriche.txt");
  if (dBMotoElettriche.is_open()) {
    int citta, km, numPost, ingombro, potenza, numMotori, inCarica, caricaSupp,
        colonninaAtt;
    string targa, posizione;
    double capBatteria, capAttuale;
    while (dBMotoElettriche >> citta >> targa >> posizione >> km >> potenza >>
           numMotori >> capBatteria >> capAttuale >> caricaSupp >> inCarica >>
           colonninaAtt >> numPost >> ingombro) {
      model.addVehicle(
          citta,
          new MotoElettrica(
              targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
              static_cast<Monopattino::VelocitaRicarica>(caricaSupp), inCarica,
              static_cast<Monopattino::Colonnina>(colonninaAtt), numPost,
              ingombro));
    }
  } else
    throw FileNotFound(6);
  dBMotoElettriche.close();

  std::ifstream dBMoto("database/dataBaseMoto.txt");
  if (dBMoto.is_open()) {
    int citta, km, carburante, cilindrata, emissioni, numPost, ingombro;
    string targa, posizione;
    double capSerba, litSerba;
    while (dBMoto >> citta >> targa >> posizione >> km >> capSerba >>
           litSerba >> carburante >> cilindrata >> emissioni >> numPost >>
           ingombro) {
      model.addVehicle(citta,
                       new Moto(targa, posizione, km, capSerba, litSerba,
                                static_cast<Automobile::Carburante>(carburante),
                                cilindrata, emissioni, numPost, ingombro));
    }
  } else
    throw FileNotFound(7);
  dBMoto.close();
}
