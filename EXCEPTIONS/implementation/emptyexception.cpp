#include "EXCEPTIONS/header/emptyexception.h"

EmptyException::EmptyException(): std::runtime_error("Exception: trying to remove an element from empty array.") {}
