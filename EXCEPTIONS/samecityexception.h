#ifndef SAMECITYEXCEPTION_H
#define SAMECITYEXCEPTION_H

#include <stdexcept>

class SameCityException : public std::runtime_error {
public:
    SameCityException();
};

#endif // SAMECITYEXCEPTION_H
