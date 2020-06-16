#include "model.h"

Model::Model(): _cities() {}

Model::~Model() {
    for (Array<Citta*>::iterator it = _cities.begin(); it != _cities.end(); it++) {
        delete *it;
    }
}

Array<Citta *> Model::getCities() const {
    return _cities;
}

Citta *Model::getCity(unsigned int index) const {
    return _cities[index];
}

void Model::addCity(Citta* const city) {
    _cities.push_back(city);
}

void Model::addVehicle(unsigned int city, Veicolo* const vehicle) {
    _cities[city]->addVeicolo(vehicle);
}

Veicolo* Model::getVehicle(unsigned int city, unsigned int vehicle) const {
    return _cities[city]->getVeicoli()->operator[](vehicle);
}

Veicolo* Model::removeVehicle(unsigned int city, unsigned int vehicle) {
    Array<Veicolo*>::iterator it = _cities[city]->getVeicoli()->begin();
    Array<Veicolo*>* vehicles = _cities[city]->getVeicoli();
    Veicolo* res;

    for (unsigned int i = 0; i < vehicle; i++)
        it++;

    res = vehicles->erase(it);

    return res;
}

void Model::moveVehicle(unsigned int fromCity, unsigned int toCity, unsigned int vehicle) {
    if (fromCity == toCity) throw new SameCityException();
    addVehicle(toCity, removeVehicle(fromCity, vehicle));
}
