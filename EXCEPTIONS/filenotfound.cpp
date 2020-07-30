#include "filenotfound.h"

FileNotFound::FileNotFound() : std::runtime_error("Exception: dataBase FILE not found.") {}
