#include "Mensagem.h"

Mensagem::Mensagem(string texto, Perfil* autor)
{
    this->texto = texto;
    this->autor = autor;
    return;
}

Mensagem::~Mensagem()
{
    delete this;
    //dtor
}

string Mensagem::getTexto(){
    return texto;
};
