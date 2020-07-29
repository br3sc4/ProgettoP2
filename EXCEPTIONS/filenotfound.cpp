#include "filenotfound.h"

FileNotFound::FileNotFound(int error) : std::runtime_error("Exception: FILE not found.") {
    switch (error) {
        case 0:
            std::runtime_error("Exception: dataBaseCitta.txt not found.");
        case 1:
            std::runtime_error("Exception: dataBaseBiciclette.txt not found.");
    }
}
