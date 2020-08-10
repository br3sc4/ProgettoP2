#include "citywizard.h"
#include "addcitypage.h"
#include "selectcitypage.h"
#include "vehiclefieldspage.h"
#include "selectenginepage.h"
#include "combustionenginepage.h"
#include "electricenginepage.h"
#include "Models/veicolo.h"

CityWizard::CityWizard(bool addCityMode, Controller* controller, QWidget* parent): QWizard(parent), _controller(controller), _addCityMode(addCityMode) {
    setPage(AddCity_Page, new AddCityPage);
    setPage(SelectCity_Page, new SelectCityPage);
    setPage(Vehicle_Page, new VehicleFieldsPage);
    setPage(SelectEngine_Page, new SelectEnginePage);
    setPage(ComustionEngine_Page, new CombustionEnginePage);
    setPage(ElectricEngine_Page, new ElectricEnginePage);

    setStartId(addCityMode ? AddCity_Page : SelectCity_Page);

    setWindowTitle(tr("Strumento aggiunta"));
}

void CityWizard::accept() {
    std::string targa = field("targa").toString().toStdString();
    std::string pos = field("posizione").toString().toStdString();
    unsigned long km = field("km").toULongLong();
    unsigned short posti = field("posti").toUInt();
    unsigned short ingombro = field("ingombro").toUInt();
    unsigned short tipoMotore = field("tipoMotore").toUInt();
    unsigned short tipoVeicolo = field("tipoVeicolo").toUInt();

    if (_addCityMode) {
        std::string cityName = field("cityName").toString().toStdString();
        if (!_controller->searchCity(cityName))
            _controller->addCity(cityName);
        else
            _controller->showMessage("Città già esistente.");
        _city = _controller->getCities().size() - 1;
    }

    if (_controller->searchVehicle(_city, targa))
        _controller->showMessage("Veicolo già esistente.");
    else {
        if (tipoMotore == SelectEnginePage::Engines::CombustionEngine) {
            double capacita = field("capacità").toDouble();
            MotoreCombustione::Carburante carburante = MotoreCombustione::Carburante(field("carburante").toUInt());
            unsigned short cilindrata = field("cilindrata").toUInt();
            unsigned short emissioni = field("emissioni").toUInt();

            if (tipoVeicolo == SelectEnginePage::Vehicles::Auto)
                _controller->addVehicle(_city, new Automobile(targa, pos, km, capacita, capacita, carburante, cilindrata, emissioni,
                                                              0, 0, Veicolo::libero, false, false, 0, posti, ingombro));
            else if (tipoVeicolo == SelectEnginePage::Vehicles::Moto)
                _controller->addVehicle(_city, new Moto(targa, pos, km, capacita, capacita, carburante, cilindrata, emissioni,
                                                        0, 0, Veicolo::libero, false, false, 0, posti, ingombro));
        } else if (tipoMotore == SelectEnginePage::Engines::CombustionEngine) {
            unsigned short potenza = field("potenza").toUInt();
            unsigned short motori = field("motori").toUInt();
            double capacita = field("capacitaBatteria").toDouble();
            MotoreElettrico::VelocitaRicarica carica = MotoreElettrico::VelocitaRicarica(field("carica").toUInt());

            if (tipoVeicolo == SelectEnginePage::Vehicles::Auto)
                _controller->addVehicle(_city, new AutomobileElettrica(targa, pos, km, potenza, motori, capacita, capacita, carica, 0, 0,
                                                                       Veicolo::libero, false, false, 0, false, MotoreElettrico::Colonnina::nessuna,
                                                                       posti, ingombro));
            else if (tipoVeicolo == SelectEnginePage::Vehicles::Moto)
                _controller->addVehicle(_city, new MotoElettrica(targa, pos, km, potenza, motori, capacita, capacita, carica, 0, 0,
                                                                 Veicolo::libero, false, false, 0, false, MotoreElettrico::Colonnina::nessuna,
                                                                 posti, ingombro));
            else if (tipoVeicolo == SelectEnginePage::Vehicles::Bici)
                _controller->addVehicle(_city, new Bicicletta(targa, pos, km, potenza, motori, capacita, capacita, carica, 0, 0,
                                                              Veicolo::libero, false, false, 0, false, MotoreElettrico::Colonnina::nessuna,
                                                              posti, ingombro));
            else
                _controller->addVehicle(_city, new Monopattino(targa, pos, km, potenza, motori, capacita, capacita, carica, 0, 0,
                                                               Veicolo::libero, false, false, 0, false, MotoreElettrico::Colonnina::nessuna,
                                                               posti, ingombro));
        } else {
            double capacita = field("capacità").toDouble();
            MotoreCombustione::Carburante carburante = MotoreCombustione::Carburante(field("carburante").toUInt());
            unsigned short cilindrata = field("cilindrata").toUInt();
            unsigned short emissioni = field("emissioni").toUInt();
            unsigned short potenza = field("potenza").toUInt();
            unsigned short motori = field("motori").toUInt();
            double capacitaBatteria = field("capacitaBatteria").toDouble();
            MotoreElettrico::VelocitaRicarica carica = MotoreElettrico::VelocitaRicarica(field("carica").toUInt());

            _controller->addVehicle(_city, new AutoIbrida(targa, pos, km, capacita, capacita, carburante, cilindrata, emissioni, potenza, motori,
                                                          capacitaBatteria, capacitaBatteria, carica, 0, 0, Veicolo::libero, false, false, 0,
                                                          false, MotoreElettrico::Colonnina::nessuna, posti, ingombro));
        }
    }

    QDialog::accept();
}

Array<Citta*> CityWizard::getCities() const {
    return _controller->getCities();
}

void CityWizard::setCity(unsigned int index) {
    _city = index;
}
