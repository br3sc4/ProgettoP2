#include "notinchargeexception.h"

NotInChargeException::NotInChargeException(): std::runtime_error("Exception: trying to calculate charge remaining time of an disconnected veicle.") {}
