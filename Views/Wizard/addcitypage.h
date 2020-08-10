#ifndef ADDCITYPAGE_H
#define ADDCITYPAGE_H

#include "citywizard.h"
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QRegExpValidator>

class AddCityPage : public QWizardPage {
    Q_OBJECT
public:
    explicit AddCityPage(QWidget* parent = nullptr);

    virtual bool isComplete() const override;
    int nextId() const override;

private:
    QLabel* _cityLabel;
    QLineEdit* _cityLineEdit;
};

#endif // ADDCITYPAGE_H
