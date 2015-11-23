#include <string>
#include "Pessoa.h"

using namespace std;


Pessoa::Pessoa(string nome, string dataDeNascimento, string pais){
    this->nome = nome;
    this->dataDeNascimento = dataDeNascimento;
    this->pais = pais;
}
string Pessoa::getNome(){
    return nome;
}

string Pessoa::getDataDeNascimento(){
    return dataDeNascimento;
}

string Pessoa::getPais(){
    return pais;
}
