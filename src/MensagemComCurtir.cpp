#include "MensagemComCurtir.h"

MensagemComCurtir::MensagemComCurtir(string texto, Perfil* autor) : Mensagem(texto, autor)
{
    this->curtidas = 0;
}

MensagemComCurtir::~MensagemComCurtir()
{
    //dtor
}

int MensagemComCurtir::getCurtidas(){
    return this->curtidas;
}

void MensagemComCurtir::curtir(){
    this->curtidas++;
}
