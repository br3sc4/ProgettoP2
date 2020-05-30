#ifndef EMPTYEXCEPTION_H
#define EMPTYEXCEPTION_H

#include <stdexcept>

class EmptyException: public std::runtime_error {
public:
    EmptyException();
};

#endif // EMPTYEXCEPTION_H
