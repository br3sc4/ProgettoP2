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

Citta* Model::removeCity(unsigned int city) {
    Array<Citta*>::iterator it = _cities.begin();
    Citta* res;

    for (unsigned int i = 0; i < city; i++)
        it++;

    res = _cities.erase(it);

    return res;
}

void Model::addVehicle(unsigned int city, Veicolo* const vehicle) {
    _cities[city]->addVeicolo(vehicle);
}

Veicolo* Model::getVehicle(unsigned int city, unsigned int vehicle) const {
    return _cities[city]->getVeicoli()[vehicle];
}

Veicolo* Model::removeVehicle(unsigned int city, unsigned int vehicle) {
    Array<Veicolo*>::iterator it = _cities[city]->getVeicoli().begin();
    Veicolo* res;

    for (unsigned int i = 0; i < vehicle; i++)
        it++;

    res = _cities[city]->getVeicoli().erase(it);

    return res;
}

void Model::moveVehicle(unsigned int fromCity, unsigned int toCity, unsigned int vehicle) {
    if (fromCity == toCity) throw new SameCityException();
    addVehicle(toCity, removeVehicle(fromCity, vehicle));
}

bool Model::searchCity(const std::string& city) const {
    bool found = false;
    Array<Citta*>::const_iterator it = _cities.cbegin();

    while (!found && it != _cities.cend()) {
        if ((*it)->getNome() == city) found = true;
        ++it;
    }

    return found;
}

bool Model::searchVehicle(unsigned int city, const std::string& vehicle) const {
    bool found = false;
    Array<Veicolo*>::const_iterator it = _cities[city]->getVeicoli().cbegin();

    while (!found && it != _cities[city]->getVeicoli().cend()) {
        if ((*it)->targa() == vehicle) found = true;
        ++it;
    }

    return found;
}

void Model::sortVehicleByState(unsigned city, bool ascending) {
    Array<Veicolo*>* vehicles = &(_cities[city]->getVeicoli());

    std::stable_sort(vehicles->begin(), vehicles->end(), [=](Veicolo* const lhs, Veicolo* const rhs) {
        return ascending ? lhs->statoAttuale() < rhs->statoAttuale() : lhs->statoAttuale() > rhs->statoAttuale();
    });
}
