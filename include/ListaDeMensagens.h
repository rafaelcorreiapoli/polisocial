#ifndef LISTADEMENSAGENS_H
#define LISTADEMENSAGENS_H
#include "Elemento.h"
#include "Mensagem.h"
#include <iostream>


using namespace std;
class ListaDeMensagens
{
    public:
        Elemento *head; // A "cabeça" é um ponteiro para o primeiro elemento da lista.
        ListaDeMensagens ();
        ~ListaDeMensagens();
        void pushFinal (Mensagem *x);
        void imprime();
        Mensagem find (int x);
        Elemento* getHead();

};

#endif // LISTADEMENSAGENS_H
