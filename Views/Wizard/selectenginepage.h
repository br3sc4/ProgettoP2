#ifndef BASEENGINEPAGE_H
#define BASEENGINEPAGE_H

#include "citywizard.h"
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

class SelectEnginePage: public QWizardPage {
    Q_OBJECT

public:
    explicit SelectEnginePage(QWidget* parent = nullptr);

    int nextId() const override;

    enum Engines { CombustionEngine, ElectricEngine, HybridEngine };
    enum Vehicles { Auto, Moto, Bici, Monopattino };

private:
    QLabel* _postiLabel;
    QSpinBox* _postiSpinBox;
    QLabel* _ingombroLabel;
    QSpinBox* _ingombroSpinBox;
    QLabel* _tipoMotoreLabel;
    QComboBox* _tipoMotoreComboBox;
    QLabel* _tipoVeicoloLabel;
    QComboBox* _tipoVeicoloComboBox;

    // QComboBox QStringLists per la scelta dinamica del veicolo
    const QStringList _combustione, _elettrico, _ibrido;

    void setupPosti();
    void setupIngombro();
    void setupMotore();
    void setupVeicolo();
    void setupLayout();

private slots:
    void changeTipoVeicoloLabels(const QString& text);
};

#endif // BASEENGINEPAGE_H
