#include "notfoundexception.h"

NotFoundException::NotFoundException(): std::runtime_error("Exception: item not found") {}
