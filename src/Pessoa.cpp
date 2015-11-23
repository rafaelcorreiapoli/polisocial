#include "Pessoa.h"
#include "Functions.h"
#include <iostream>
#include <sstream>




Pessoa::Pessoa(string nome, string dataDeNascimento, string pais) : Perfil(nome)
{
    this->dataDeNascimento = dataDeNascimento;
    this->pais = pais;
}

Pessoa::~Pessoa()
{
    //dtor
    delete this;
}



string Pessoa::getDataDeNascimento(){
    return dataDeNascimento;
}

string Pessoa::getPais(){
    return pais;
}

void Pessoa::adiciona(Perfil *contato){
    std::ostringstream oss;

    this->contatos[this->nContatos] = contato;
    this->nContatos++;



    if (ehDepartamento(contato)){
        contato->adicionadoPor(this);
    }else { //apenas pessoas que são adicionadas recebem essa msg
        oss << this->getNome() << " adicionou você como contato";
        Mensagem* m = new Mensagem(oss.str(), false);
        contato->recebe(m);
    }
}

void Pessoa::adicionadoPor(Perfil* contato){

}

void Pessoa::envia(string texto, Perfil* contato) {
    Mensagem *m = new Mensagem(texto, true);  //msg privada sempre pode ser curtida
    this->msgsEnviadas->pushFinal(m);
    contato->recebe(m);
};

