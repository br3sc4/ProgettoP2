#ifndef ELECTRICENGINEPAGE_H
#define ELECTRICENGINEPAGE_H

#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

class ElectricEnginePage: public QWizardPage {
    Q_OBJECT

public:
    explicit ElectricEnginePage(QWidget* parent = nullptr);

    int nextId() const override;

private:
    QLabel* _motoriLabel;
    QSpinBox* _motoriSpinBox;
    QLabel* _capacitaLabel;
    QSpinBox* _capacitaSpinBox;
    QLabel* _potenzaLabel;
    QSpinBox* _potenzaSpinBox;
    QLabel* _caricaLabel;
    QComboBox* _caricaComboBox;

    void setupMotori();
    void setupCapacita();
    void setupPotenza();
    void setupCarica();

protected:
    void setupLayout();
};

#endif // ELECTRICENGINEPAGE_H
