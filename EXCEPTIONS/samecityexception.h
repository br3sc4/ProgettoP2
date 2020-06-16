#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H

#include <stdexcept>

class SameCityException : public std::runtime_error {
public:
    SameCityException();
};

#endif // NOTFOUNDEXCEPTION_H
