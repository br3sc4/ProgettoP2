#include "samecityexception.h"

SameCityException::SameCityException(): std::runtime_error("Exception: trying to move a vehicle to the initial city.") {}
