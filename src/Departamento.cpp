#include "Departamento.h"
#include "Pessoa.h"
#include <string>
#include <sstream>

using namespace std;
Departamento::Departamento(string nome, string site, Pessoa* responsavel):Perfil(nome)
{
    this->site = site;
    this->responsavel = responsavel;
}

Departamento::~Departamento()
{
    //dtor
}


void Departamento::adicionadoPor(Perfil* contato){
    this->contatos[this->nContatos] = contato;
    this->nContatos++;

    ostringstream oss;
    oss << this->getNome() << " adicionou você como contato";
    Mensagem* m = new Mensagem(oss.str(), false);
    contato->recebe(m);
}

void Departamento::recebe(Mensagem* mensagem){
    this->msgsRecebidas->pushFinal(mensagem);
    this->getResponsavel()->recebe(mensagem);
}

Pessoa* Departamento::getResponsavel()
{
    return this->responsavel;
}
