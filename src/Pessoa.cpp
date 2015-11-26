#include "Pessoa.h"
#include "Functions.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

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
    this->contatos->push_back(contato);
    contato->adicionadoPor(this);

    /*
    if (ehDepartamento(contato)){
        contato->adicionadoPor(this);
    }else { //apenas pessoas que são adicionadas recebem essa msg
        oss << this->getNome() << " adicionou você como contato";
        Mensagem* m = new Mensagem(oss.str(), false);
        contato->recebe(m);
    }
    */
}

void Pessoa::adicionadoPor(Perfil* contato){
    std::ostringstream oss;
    oss << contato->getNome() << " adicionou você como contato";
    Mensagem* m = new Mensagem(oss.str(), false);
    this->recebe(m);
}

bool Pessoa::remove(Perfil* contato) {
    ostringstream oss;

    vector<Perfil*>::iterator it = find(this->contatos->begin(), this->contatos->end(), contato);
    if (it != this->contatos->end()) {
        this->contatos->erase(it);

        oss << this->getNome() << " removeu voce como contato";


        Mensagem* m = new Mensagem(oss.str(), this);
        (*it)->recebe(m);
        return true;
    }

    return false;
}


void Pessoa::envia(string texto, Perfil* contato) {
    Mensagem *m = new Mensagem(texto, this);  //msg privada sempre pode ser curtida
    cout << m->getAutor()->getNome();
    this->msgsEnviadas->push_back(m);
    contato->recebe(m);
};

