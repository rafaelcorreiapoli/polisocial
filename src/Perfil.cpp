#include "Perfil.h"
#include "MensagemComCurtir.h"
Perfil::Perfil(string nome)
{
    this->nome = nome;
    this->nContatos = 0;
    this->msgsEnviadas = new list<Mensagem*>;
    this->msgsRecebidas = new list<Mensagem*>;
    this->contatos = new vector<Perfil*>;
}

Perfil::~Perfil()
{
    //dtor
}

string Perfil::getNome(){
    return nome;
}

void Perfil::setContatos(vector<Perfil*>* contatos) {
    this->contatos = contatos;
}


void Perfil::envia(string texto, bool curtir){
    Mensagem *m;

    if (curtir) {
        //MensagemComCurtir* m = dynamic_cast<MensagemComCurtir *>(m);
        m = new MensagemComCurtir(texto, this);
    }else{
        m = new Mensagem(texto, this);
    }

    this->msgsEnviadas->push_back(m);
    vector<Perfil*>::iterator it;
    for (it = this->contatos->begin(); it != this->contatos->end(); it++) {
        (*it)->recebe(m);
    }
    /*
    int i;
    for (i=0;i<nContatos;i++){
        contatos->at(i)->recebe(m);
    }
    */
};

void Perfil::recebe(Mensagem *m){
    this->msgsRecebidas->push_back(m);
}


vector<Perfil*>* Perfil::getContatos(){
    return this->contatos;
}

list<Mensagem*>* Perfil::getMensagensRecebidas(){
    return this->msgsRecebidas;
}

list<Mensagem*>* Perfil::getMensagensEnviadas(){
    return this->msgsEnviadas;
}

