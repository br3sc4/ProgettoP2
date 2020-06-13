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

Citta* Model::getCity(const std::string& city) const {
    return (*searchCity(city));
}

Citta *Model::getCity(unsigned int index) const {
    return _cities[index];
}

void Model::addCity(Citta* const city) {
    _cities.push_back(city);
}

void Model::addVehicle(const std::string& city, Veicolo* const vehicle) {
    Array<Citta*>::iterator it = searchCity(city);
    (*it)->addVeicolo(vehicle);
}

Veicolo* Model::getVehicle(const std::string& city, unsigned int vehicle) const{
    Array<Citta*>::iterator it = searchCity(city);
    return (*it)->getVeicolo(vehicle);
}

Veicolo* Model::getVehicle(const std::string& city, const std::string& vehicle) const{
    Array<Veicolo*>::iterator it = searchVehicle(city, vehicle);
    return *it;
}

Array<Veicolo*>::iterator Model::removeVehicle(const std::string& city, const std::string& vehicle) {
    Array<Veicolo*>::iterator it = searchVehicle(city, vehicle);
    Array<Veicolo*>* vehicles = (*searchCity(city))->getVeicoli();
    Array<Veicolo*>::iterator res;

    if (it != vehicles->end()) {
        delete *it;
        res = vehicles->erase(it);
    }

    return res;
}

void Model::moveVehicle(const std::string& from, const std::string& to, const std::string& vehicle) {
    Array<Veicolo*>::iterator it = removeVehicle(from, vehicle);
    addVehicle(to, *it);
}

Array<Citta*>::iterator Model::searchCity(const std::string& city) const {
    Array<Citta*>::iterator it = _cities.begin();

    while (it != _cities.end() && (*it)->getNome() != city) {
        it++;
    }

    return it;
}

Array<Veicolo*>::iterator Model::searchVehicle(const std::string& city, const std::string& vehicle) const {
    Array<Citta*>::iterator it = searchCity(city);
    Array<Veicolo*>* vehicles = (*it)->getVeicoli();
    Array<Veicolo*>::iterator vit = vehicles->begin();

    while (vit != vehicles->end() && (*vit)->targa() != vehicle) {
        vit++;
    }

    return vit;
}
