#ifndef OUTOFBOUNDEXCEPTIONS_H
#define OUTOFBOUNDEXCEPTIONS_H

#include <stdexcept>

class OutOfBoundsException: public std::range_error {
public:
    OutOfBoundsException();
};

#endif // OUTOFBOUNDEXCEPTIONS_H
