#include "Departamento.h"
#include "Pessoa.h"
#include <string>
#include <sstream>
#include <list>
using namespace std;
Departamento::Departamento(string nome, string site, Pessoa* responsavel):Perfil(nome)
{
    this->site = site;
    this->responsavel = responsavel;
}

Departamento::Departamento(string nome, string site) : Perfil(nome)
{
    this->site = site;
}

Departamento::~Departamento()
{
    //dtor
}

string Departamento::getSite(){
    return this->site;
}
void Departamento::setResponsavel(Pessoa* responsavel)
{
    this->responsavel = responsavel;
}

void Departamento::adicionadoPor(Perfil* contato){
    /*
    this->contatos[this->nContatos] = contato;
    this->nContatos++;
    */
    this->contatos->push_back(contato);

    ostringstream oss;
    oss << this->getNome() << " adicionou você como contato";
    Mensagem* m = new Mensagem(oss.str(), false);
    contato->recebe(m);
}

void Departamento::recebe(Mensagem* mensagem){
    this->msgsRecebidas->push_back(mensagem);
    this->getResponsavel()->recebe(mensagem);
}

Pessoa* Departamento::getResponsavel()
{
    return this->responsavel;
}
