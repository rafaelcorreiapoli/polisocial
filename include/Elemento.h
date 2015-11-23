#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <cstddef>
#include "Mensagem.h"
class Elemento
{
    public:
        Mensagem *value; // Pode ser implementado qualquer tipo de dados aqui.
        Elemento *next;
        Elemento ();
        Elemento (int _value);
        ~Elemento();
    protected:
    private:
};

#endif // ELEMENTO_H
