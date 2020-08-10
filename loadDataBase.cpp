#include "model.h"
#include <fstream>
#include <QFile>
#include <QTextStream>

void loadCitta(Model& model) {
  QFile inputFile(":/ExtraFiles/DataBase/Citta.txt");
  if (inputFile.open(QIODevice::ReadOnly)) {
    QTextStream in(&inputFile);
    while (!in.atEnd()) {
      QString line = in.readLine();
      model.addCity(new Citta(line.toStdString()));
    }
    inputFile.close();
  }
}

void loadVeicoli(Model& model) {
  QString dataBase = ":/ExtraFiles/DataBase/Veicoli.txt";

  QFile inputFile(dataBase);
  if (inputFile.open(QIODevice::ReadOnly)) {
    QTextStream in(&inputFile);
    while (!in.atEnd()) {
      QString text = in.readLine();
      if (!text.isEmpty()) {
        QStringList line = text.split(' ');

        int tipo = line[0].toInt();

        if (tipo < 4) {
          int citta = line[1].toInt(), km = line[4].toInt(),
              potenza = line[5].toInt(), numeroMotori = line[6].toInt(),
              caricaSupportata = line[9].toInt(), numeroUsi = line[10].toInt(),
              tempoServizio = line[11].toInt(), statoAttuale = line[12].toInt(),
              inRiserva = line[13].toInt(), serveAssistenza = line[14].toInt(),
              numeroGuasti = line[15].toInt(), inCarica = line[16].toInt(),
              colonninaAttuale = line[17].toInt(),
              numeroPosti = line[18].toInt(), ingombro = line[19].toInt();
          string targa = line[2].toStdString(),
                 posizione = line[3].toStdString();
          double capacitaBatteria = line[7].toDouble(),
                 capacitaAttuale = line[8].toDouble();
          switch (tipo) {
          case 0: {
            model.addVehicle(
                citta,
                new Bicicletta(
                    targa, posizione, km, potenza, numeroMotori,
                    capacitaBatteria, capacitaAttuale,
                    static_cast<MotoreElettrico::VelocitaRicarica>(
                        caricaSupportata),
                    numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, inCarica,
                    static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                    numeroPosti, ingombro));
            break;
          }
          case 1: {
            model.addVehicle(
                citta,
                new AutomobileElettrica(
                    targa, posizione, km, potenza, numeroMotori,
                    capacitaBatteria, capacitaAttuale,
                    static_cast<MotoreElettrico::VelocitaRicarica>(
                        caricaSupportata),
                    numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, inCarica,
                    static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                    numeroPosti, ingombro));
            break;
          }
          case 2: {
            model.addVehicle(
                citta,
                new Monopattino(
                    targa, posizione, km, potenza, numeroMotori,
                    capacitaBatteria, capacitaAttuale,
                    static_cast<MotoreElettrico::VelocitaRicarica>(
                        caricaSupportata),
                    numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, inCarica,
                    static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                    numeroPosti, ingombro));
            break;
          }
          case 3: {
            model.addVehicle(
                citta,
                new MotoElettrica(
                    targa, posizione, km, potenza, numeroMotori,
                    capacitaBatteria, capacitaAttuale,
                    static_cast<MotoreElettrico::VelocitaRicarica>(
                        caricaSupportata),
                    numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, inCarica,
                    static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                    numeroPosti, ingombro));
            break;
          }
          }
        } else if (tipo == 4 || tipo == 5) {
          int citta = line[1].toInt(), km = line[4].toInt(),
              carburante = line[7].toInt(), cilindrata = line[8].toInt(),
              emissioni = line[9].toInt(), numeroUsi = line[10].toInt(),
              tempoServizio = line[11].toInt(), statoAttuale = line[12].toInt(),
              inRiserva = line[13].toInt(), serveAssistenza = line[14].toInt(),
              numeroGuasti = line[15].toInt(), numeroPosti = line[16].toInt(),
              ingombro = line[17].toInt();
          string targa = line[2].toStdString(),
                 posizione = line[3].toStdString();
          double capacitaSerbatoio = line[5].toDouble(),
                 litriSerbatoio = line[6].toDouble();

          switch (tipo) {
          case 4: {
            model.addVehicle(
                citta,
                new Automobile(
                    targa, posizione, km, capacitaSerbatoio, litriSerbatoio,
                    static_cast<MotoreCombustione::Carburante>(carburante),
                    cilindrata, emissioni, numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, numeroPosti, ingombro));
            break;
          }
          case 5: {
            model.addVehicle(
                citta,
                new Moto(
                    targa, posizione, km, capacitaSerbatoio, litriSerbatoio,
                    static_cast<MotoreCombustione::Carburante>(carburante),
                    cilindrata, emissioni, numeroUsi, tempoServizio,
                    static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                    serveAssistenza, numeroGuasti, numeroPosti, ingombro));
            break;
          }
          }
        } else if (tipo == 6) {
          int citta = line[1].toInt(), km = line[4].toInt(),
              carburante = line[7].toInt(), cilindrata = line[8].toInt(),
              emissioni = line[9].toInt(), potenza = line[10].toInt(),
              numeroMotori = line[11].toInt(),
              caricaSupportata = line[14].toInt(), numeroUsi = line[15].toInt(),
              tempoServizio = line[16].toInt(), statoAttuale = line[17].toInt(),
              inRiserva = line[18].toInt(), serveAssistenza = line[19].toInt(),
              numeroGuasti = line[20].toInt(), inCarica = line[21].toInt(),
              colonninaAttuale = line[22].toInt(),
              numeroPosti = line[23].toInt(), ingombro = line[24].toInt();
          string targa = line[2].toStdString(),
                 posizione = line[3].toStdString();
          double capacitaSerbatoio = line[5].toDouble(),
                 litriSerbatoio = line[6].toDouble(),
                 capacitaBatteria = line[12].toDouble(),
                 capacitaAttuale = line[13].toDouble();
          model.addVehicle(
              citta,
              new AutoIbrida(
                  targa, posizione, km, capacitaSerbatoio, litriSerbatoio,
                  static_cast<MotoreCombustione::Carburante>(carburante),
                  cilindrata, emissioni, potenza, numeroMotori,
                  capacitaBatteria, capacitaAttuale,
                  static_cast<MotoreElettrico::VelocitaRicarica>(
                      caricaSupportata),
                  numeroUsi, tempoServizio,
                  static_cast<Veicolo::StatoVeicolo>(statoAttuale), inRiserva,
                  serveAssistenza, numeroGuasti, inCarica,
                  static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                  numeroPosti, ingombro));
        }
      }
    }
  }
  inputFile.close();
}
