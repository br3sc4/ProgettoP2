#ifndef NOTFOUNDEXCEPTION_H
#define NOTFOUNDEXCEPTION_H

#include <stdexcept>

class NotFoundException : public std::runtime_error {
public:
    NotFoundException();
};

#endif // NOTFOUNDEXCEPTION_H
