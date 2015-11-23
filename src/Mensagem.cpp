#include "Mensagem.h"

Mensagem::Mensagem(string texto, bool podeSerCurtida)
{
    this->texto = texto;
    this->likes = 0;
    this->podeSerCurtida = podeSerCurtida;
    return;
}

Mensagem::~Mensagem()
{
    delete this;
    //dtor
}
