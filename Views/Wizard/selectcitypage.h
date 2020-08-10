#ifndef SELECTCITYPAGE_H
#define SELECTCITYPAGE_H

#include "citywizard.h"
#include <QWizardPage>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>

class SelectCityPage : public QWizardPage {
    Q_OBJECT

public:
    explicit SelectCityPage(QWidget* parent = nullptr);

    virtual bool isComplete() const override;
    int nextId() const override;
    void initializePage() override;

private:
    QLabel* _vehiclesLabel;
    QTableWidget* _vehiclesList;

    void setupTable();
};

#endif // SELECTCITYPAGE_H
