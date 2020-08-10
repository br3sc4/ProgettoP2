#ifndef NOTINCHARGEEXCEPTION_H
#define NOTINCHARGEEXCEPTION_H

#include <stdexcept>

class NotInChargeException : public std::runtime_error {
public:
    NotInChargeException();
};

#endif // NOTINCHARGEEXCEPTION_H
