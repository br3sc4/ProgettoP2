#ifndef AUTOIBRIDA_H
#define AUTOIBRIDA_H

#include "motorecombustione.h"
#include "motoreelettrico.h"

class autoibrida: public motoreCombustione, public motoreElettrico
{
public:
    autoibrida();
};

#endif // AUTOIBRIDA_H
