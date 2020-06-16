#ifndef MODEL_H
#define MODEL_H

#include "MODELS/array.h"
#include "MODELS/citta.h"
#include "EXCEPTIONS/samecityexception.h"

class Model {
public:
    Model();
    ~Model();

    Array<Citta*> getCities() const;
    Citta* getCity(unsigned int index) const;
    void addCity(Citta* const city);

    void addVehicle(unsigned int city, Veicolo* const vehicle);
    Veicolo* getVehicle(unsigned int city, unsigned int vehicle) const;
    Veicolo* removeVehicle(unsigned int city, unsigned int vehicle);
    void moveVehicle(unsigned int fromCity, unsigned int toCity, unsigned int vehicle);

private:
    Array<Citta*> _cities;
};

#endif // MODEL_H
