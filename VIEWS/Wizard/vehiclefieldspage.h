#ifndef VEHICLEFIELDSPAGE_H
#define VEHICLEFIELDSPAGE_H

#include "citywizard.h"
#include <QWizardPage>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QRegExp>
#include <QRegExpValidator>
#include <QSpinBox>

class VehicleFieldsPage : public QWizardPage {
    Q_OBJECT

public:
    explicit VehicleFieldsPage(QWidget *parent = nullptr);

    virtual bool isComplete() const override;
    int nextId() const override;

private:
    QLabel* _targaLabel;
    QLineEdit* _targaLineEdit;
    QLabel* _posizioneLabel;
    QLineEdit* _posizioneLineEdit;
    QLabel* _chilometraggioLabel;
    QSpinBox* _chilometraggioSpinBox;        

    void setupTarga();
    void setupPosizione();
    void setupKm();    
    void setupLayout();
};

#endif // VEHICLEFIELDSPAGE_H
