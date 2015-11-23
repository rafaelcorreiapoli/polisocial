#include "Elemento.h"

Elemento::Elemento () {
    next = NULL; // Construtor padrão
}


Elemento::~Elemento()
{
    delete this;
    //dtor
}
