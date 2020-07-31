#include "model.h"
#include "EXCEPTIONS/filenotfound.h"
#include <fstream>
#include <QFile>
#include <QTextStream>

void loadCitta(Model& model) {
    QFile inputFile(":/database/Citta.txt");
    if (inputFile.open(QIODevice::ReadOnly)) {
       QTextStream in(&inputFile);
       while (!in.atEnd()) {
          QString line = in.readLine();
          model.addCity(new Citta(line.toStdString()));
       }
       inputFile.close();
    }
}

void loadVeicoliIbridi(Model& model, QString file) {
    QFile inputFile(file);
    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd()) {
            QString text = in.readLine();
            if (!text.isEmpty()) {
               QStringList line = text.split(' ');

               int citta = line[0].toInt(),
                   km = line[3].toInt(),
                   carburante = line[6].toInt(),
                   cilindrata = line[7].toInt(),
                   emissioni = line[8].toInt(),
                   potenza = line[9].toInt(),
                   numeroMotori = line[10].toInt(),
                   caricaSupportata = line[13].toInt(),
                   numeroUsi = line[14].toInt(),
                   tempoServizio = line[15].toInt(),
                   statoAttuale = line[16].toInt(),
                   inRiserva = line[17].toInt(),
                   serveAssistenza = line[18].toInt(),
                   numeroGuasti = line[19].toInt(),
                   inCarica = line[20].toInt(),
                   colonninaAttuale = line[21].toInt(),
                   numeroPosti = line[22].toInt(),
                   ingombro = line[23].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capacitaSerbatoio = line[4].toDouble(),
                      litriSerbatoio = line[5].toDouble(),
                      capacitaBatteria = line[11].toDouble(),
                      capacitaAttuale = line[12].toDouble();
               model.addVehicle(
                   citta,
                   new AutoIbrida(
                             targa,
                             posizione,
                             km,
                             capacitaSerbatoio,
                             litriSerbatoio,
                             static_cast<MotoreCombustione::Carburante>(carburante),
                             cilindrata,
                             emissioni,
                             potenza,
                             numeroMotori,
                             capacitaBatteria,
                             capacitaAttuale,
                             static_cast<MotoreElettrico::VelocitaRicarica>(caricaSupportata),
                             numeroUsi,
                             tempoServizio,
                             static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                             inRiserva,
                             serveAssistenza,
                             numeroGuasti,
                             inCarica,
                             static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                             numeroPosti,
                             ingombro));
             }
           }
           inputFile.close();
        }
}

void loadVeicoliElettrici(Model& model, QString file) {
    QFile inputFile(file);
    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd()) {
            QString text = in.readLine();
            if (!text.isEmpty()) {
               QStringList line = text.split(' ');

               int citta = line[0].toInt(),
                   km = line[3].toInt(),
                   potenza = line[4].toInt(),
                   numeroMotori = line[5].toInt(),
                   caricaSupportata = line[8].toInt(),
                   numeroUsi = line[9].toInt(),
                   tempoServizio = line[10].toInt(),
                   statoAttuale = line[11].toInt(),
                   inRiserva = line[12].toInt(),
                   serveAssistenza = line[13].toInt(),
                   numeroGuasti = line[14].toInt(),
                   inCarica = line[15].toInt(),
                   colonninaAttuale = line[16].toInt(),
                   numeroPosti = line[17].toInt(),
                   ingombro = line[18].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capacitaBatteria = line[6].toDouble(),
                      capacitaAttuale = line[7].toDouble();
               switch (line[19].toInt()) {
               case 0:{
                   model.addVehicle(
                       citta,
                       new Bicicletta(
                                   targa,
                                   posizione,
                                   km,
                                   potenza,
                                   numeroMotori,
                                   capacitaBatteria,
                                   capacitaAttuale,
                                   static_cast<MotoreElettrico::VelocitaRicarica>(caricaSupportata),
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   inCarica,
                                   static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                                   numeroPosti,
                                   ingombro));
               break;}
               case 1:{
                   model.addVehicle(
                       citta,
                       new AutomobileElettrica(
                                   targa,
                                   posizione,
                                   km,
                                   potenza,
                                   numeroMotori,
                                   capacitaBatteria,
                                   capacitaAttuale,
                                   static_cast<MotoreElettrico::VelocitaRicarica>(caricaSupportata),
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   inCarica,
                                   static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                                   numeroPosti,
                                   ingombro));
               break;}
               case 2:{
                   model.addVehicle(
                       citta,
                       new Monopattino(
                                   targa,
                                   posizione,
                                   km,
                                   potenza,
                                   numeroMotori,
                                   capacitaBatteria,
                                   capacitaAttuale,
                                   static_cast<MotoreElettrico::VelocitaRicarica>(caricaSupportata),
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   inCarica,
                                   static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                                   numeroPosti,
                                   ingombro));
               break;}
               case 3:{
                   model.addVehicle(
                       citta,
                       new MotoElettrica(
                                   targa,
                                   posizione,
                                   km,
                                   potenza,
                                   numeroMotori,
                                   capacitaBatteria,
                                   capacitaAttuale,
                                   static_cast<MotoreElettrico::VelocitaRicarica>(caricaSupportata),
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   inCarica,
                                   static_cast<MotoreElettrico::Colonnina>(colonninaAttuale),
                                   numeroPosti,
                                   ingombro));
               break;}
                }
               }
           }
           inputFile.close();
        }
}

void loadVeicoliNormali(Model& model, QString file) {
    QFile inputFile(file);
    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd()) {
            QString text = in.readLine();
            if (!text.isEmpty()) {
               QStringList line = text.split(' ');

               int citta = line[0].toInt(),
                   km = line[3].toInt(),
                   carburante = line[6].toInt(),
                   cilindrata = line[7].toInt(),
                   emissioni = line[8].toInt(),
                   numeroUsi = line[9].toInt(),
                   tempoServizio = line[10].toInt(),
                   statoAttuale = line[11].toInt(),
                   inRiserva = line[12].toInt(),
                   serveAssistenza = line[13].toInt(),
                   numeroGuasti = line[14].toInt(),
                   numeroPosti = line[15].toInt(),
                   ingombro = line[16].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capacitaSerbatoio = line[4].toDouble(),
                      litriSerbatoio = line[5].toDouble();
               switch (line[17].toInt()) {
               case 0:{
                   model.addVehicle(
                       citta, new Automobile(
                                   targa,
                                   posizione,
                                   km,
                                   capacitaSerbatoio,
                                   litriSerbatoio,
                                   static_cast<MotoreCombustione::Carburante>(carburante),
                                   cilindrata,
                                   emissioni,
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   numeroPosti,
                                   ingombro));
               break;}
               case 1:{
                   model.addVehicle(
                       citta, new Moto(
                                   targa,
                                   posizione,
                                   km,
                                   capacitaSerbatoio,
                                   litriSerbatoio,
                                   static_cast<MotoreCombustione::Carburante>(carburante),
                                   cilindrata,
                                   emissioni,
                                   numeroUsi,
                                   tempoServizio,
                                   static_cast<Veicolo::StatoVeicolo>(statoAttuale),
                                   inRiserva,
                                   serveAssistenza,
                                   numeroGuasti,
                                   numeroPosti,
                                   ingombro));
               break;}
                 }
               }
             }
           }
           inputFile.close();
}

void loadVeicoli(Model& model) {
    QString a = ":/database/veicoliElettrici.txt",
            b = ":/database/veicoliNormali.txt",
            c = ":/database/veicoliIbridi.txt";

    loadVeicoliElettrici(model, a);
    loadVeicoliNormali(model, b);
    loadVeicoliIbridi(model, c);
}
