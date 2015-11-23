#include "Perfil.h"

Perfil::Perfil(string nome)
{
    this->nome = nome;
    this->nContatos = 0;
    this->msgsEnviadas = new ListaDeMensagens();
    this->msgsRecebidas = new ListaDeMensagens();
}

Perfil::~Perfil()
{
    //dtor
}

string Perfil::getNome(){
    return nome;
}



void Perfil::verContatos(){
    int i;
    for (i = 0; i < nContatos; i++){
        cout << contatos[i]->getNome() << endl;
    }
}



void Perfil::envia(string texto, bool curtir){
    Mensagem *m = new Mensagem(texto, curtir);
    this->msgsEnviadas->pushFinal(m);

    int i;
    for (i=0;i<nContatos;i++){
        contatos[i]->recebe(m);
    }
};

void Perfil::recebe(Mensagem *m){
    cout << "[" << this->getNome() <<"] recebendo mensagem..." <<endl;
    this->msgsRecebidas->pushFinal(m);
}


ListaDeMensagens* Perfil::getMensagensRecebidas(){
    return this->msgsRecebidas;
}

ListaDeMensagens* Perfil::getMensagensEnviadas(){
    return this->msgsEnviadas;
}

