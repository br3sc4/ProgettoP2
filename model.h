#ifndef MODEL_H
#define MODEL_H

#include "Models/array.h"
#include "Models/citta.h"
#include "Models/automobile.h"
#include "Models/bicicletta.h"
#include "Models/automobileelettrica.h"
#include "Models/autoibrida.h"
#include "Models/monopattino.h"
#include "Models/moto.h"
#include "Models/motoelettrica.h"
#include "Exceptions/samecityexception.h"

class Model {
public:
    Model();
    ~Model();

    Array<Citta*> getCities() const;
    Citta* getCity(unsigned int index) const;
    void addCity(Citta* const city);
    Citta* removeCity(unsigned int city);

    void addVehicle(unsigned int city, Veicolo* const vehicle);
    Veicolo* getVehicle(unsigned int city, unsigned int vehicle) const;
    Veicolo* removeVehicle(unsigned int city, unsigned int vehicle);
    void moveVehicle(unsigned int fromCity, unsigned int toCity, unsigned int vehicle);

    bool searchCity(const std::string& city) const;
    bool searchVehicle(unsigned int city, const std::string& vehicle) const;

    void sortVehicleByState(unsigned city, bool ascending = true);

private:
    Array<Citta*> _cities;
};

#endif // MODEL_H
