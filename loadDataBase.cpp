#include "model.h"
#include "EXCEPTIONS/filenotfound.h"
#include <fstream>
#include <QFile>
#include <QTextStream>

void loadCitta(Model& model) {
    QFile inputFile(":/database/dataBaseCitta.txt");
    if (inputFile.open(QIODevice::ReadOnly)) {
       QTextStream in(&inputFile);
       while (!in.atEnd()) {
          QString line = in.readLine();
          model.addCity(new Citta(line.toStdString()));
       }
       inputFile.close();
    }
}

void loadIbrida(Model& model) {
    QFile inputFile(":/database/dataBaseAutoIbride.txt");
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
                   numMotori = line[10].toInt(),
                   caricaSupp = line[13].toInt(),
                   inCarica = line[14].toInt(),
                   colonninaAtt = line[15].toInt(),
                   numPost = line[16].toInt(),
                   ingombro = line[17].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capSerba = line[4].toDouble(),
                      litSerba = line[5].toDouble(),
                      capBatteria = line[11].toDouble(),
                      capAttuale = line[12].toDouble();
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
           }
           inputFile.close();
        }
}

void loadVeicoliElettrici(Model& model, int tipo, QString file) {
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
                   numMotori = line[5].toInt(),
                   caricaSupp = line[8].toInt(),
                   inCarica = line[9].toInt(),
                   colonninaAtt = line[10].toInt(),
                   numPost = line[11].toInt(),
                   ingombro = line[12].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capBatteria = line[6].toDouble(),
                      capAttuale = line[7].toDouble();
               switch (tipo) {
               case 0:{
                   model.addVehicle(
                       citta,
                       new Bicicletta(
                           targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
                           static_cast<Bicicletta::VelocitaRicarica>(caricaSupp), inCarica,
                           static_cast<Bicicletta::Colonnina>(colonninaAtt), numPost,
                           ingombro));
               break;}
               case 1:{
                   model.addVehicle(
                       citta,
                       new AutomobileElettrica(
                           targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
                           static_cast<AutomobileElettrica::VelocitaRicarica>(caricaSupp),
                           inCarica,
                           static_cast<AutomobileElettrica::Colonnina>(colonninaAtt),
                           numPost, ingombro));
               break;}
               case 2:{
                   model.addVehicle(
                       citta,
                       new Monopattino(
                           targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
                           static_cast<AutomobileElettrica::VelocitaRicarica>(caricaSupp),
                           inCarica,
                           static_cast<AutomobileElettrica::Colonnina>(colonninaAtt),
                           numPost, ingombro));
               break;}
               case 3:{
                   model.addVehicle(
                       citta,
                       new MotoElettrica(
                           targa, posizione, km, potenza, numMotori, capBatteria, capAttuale,
                           static_cast<AutomobileElettrica::VelocitaRicarica>(caricaSupp),
                           inCarica,
                           static_cast<AutomobileElettrica::Colonnina>(colonninaAtt),
                           numPost, ingombro));
               break;}
                }
               }
           }
           inputFile.close();
        }
}

void loadVeicoliNormali(Model& model, int tipo, QString file) {
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
                   numPost = line[9].toInt(),
                   ingombro = line[10].toInt();
               string targa = line[1].toStdString(),
                      posizione = line[2].toStdString();
               double capSerba = line[4].toDouble(),
                      litSerba = line[5].toDouble();
               switch (tipo) {
               case 0:
                   model.addVehicle(
                       citta, new Automobile(targa, posizione, km, capSerba, litSerba,
                                             static_cast<Automobile::Carburante>(carburante),
                                             cilindrata, emissioni, numPost, ingombro));
               case 1:
                   model.addVehicle(
                       citta, new Moto(targa, posizione, km, capSerba, litSerba,
                                             static_cast<Automobile::Carburante>(carburante),
                                             cilindrata, emissioni, numPost, ingombro));
                 }
               }
             }
           }
           inputFile.close();
}

void loadVeicoli(Model& model) {
    QString a = ":/database/dataBaseBiciclette.txt",
            b = ":/database/dataBaseAutoElettriche.txt";
    loadVeicoliElettrici(model, 0, a);
    loadVeicoliElettrici(model, 1, b);
    loadVeicoliElettrici(model, 2, ":/database/dataMonopattini.txt");
    loadVeicoliElettrici(model, 3, ":/database/dataBaseMotoElettriche.txt");

    loadVeicoliNormali(model, 0, ":/database/dataAutomobili.txt");
    loadVeicoliNormali(model, 1, ":/database/dataMoto.txt");

    loadIbrida(model);
}
