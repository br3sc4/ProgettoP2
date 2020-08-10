#ifndef CITYWIZARD_H
#define CITYWIZARD_H

#include "controller.h"
#include <QWizard>

class CityWizard : public QWizard {
    Q_OBJECT

public:
    explicit CityWizard(bool addCityMode, Controller* controller, QWidget* parent = nullptr);

    void accept() override;

    enum { AddCity_Page, SelectCity_Page, Vehicle_Page, SelectEngine_Page, ComustionEngine_Page, ElectricEngine_Page };

    Array<Citta*> getCities() const;
    void setCity(unsigned int index);

private:
    Controller* _controller;    
    unsigned int _city;
    bool _addCityMode;
};

#endif // CITYWIZARD_H
