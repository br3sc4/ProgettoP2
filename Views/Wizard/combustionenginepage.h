#ifndef COMBUSTIONENGINEPAGE_H
#define COMBUSTIONENGINEPAGE_H

#include "citywizard.h"
#include "selectenginepage.h"
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QVBoxLayout>

class CombustionEnginePage: public QWizardPage {
    Q_OBJECT

public:
    explicit CombustionEnginePage(QWidget* parent = nullptr);

    int nextId() const override;

private:
    QLabel* _cilindrataLabel;
    QSpinBox* _cilindrataSpinBox;
    QLabel* _capacitaLabel;
    QSpinBox* _capacitaSpinBox;
    QLabel* _emissioniLabel;
    QDoubleSpinBox* _emissioniSpinBox;
    QLabel* _carburanteLabel;
    QComboBox* _carburanteComboBox;

    void setupCilindrata();
    void setupCapacita();
    void setupEmissioni();
    void setupCarburante();

protected:
    void setupLayout();
};

#endif // COMBUSTIONENGINEPAGE_H
