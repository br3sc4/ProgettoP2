#ifndef FILENOTFOUNDEXCEPTION_H
#define FILENOTFOUNDEXCEPTION_H

#include <stdexcept>

class FileNotFound : public std::runtime_error {
public:
    FileNotFound(int);
};

#endif // FILENOTFOUNDEXCEPTION_H
