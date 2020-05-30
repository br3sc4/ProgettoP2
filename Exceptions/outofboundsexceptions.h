#ifndef OUTOFBOUNDEXCEPTIONS_H
#define OUTOFBOUNDEXCEPTIONS_H

#include <stdexcept>

class OutOfBoundsExceptions : public std::range_error {
public:
    OutOfBoundsExceptions();
};

#endif // OUTOFBOUNDEXCEPTIONS_H
