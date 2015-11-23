
#include "Mensagem.h"
#include "ListaDeMensagens.h"
#include "Perfil.h"
#include <string>
#ifndef PESSOA_H
#define PESSOA_H

using namespace std;
class Pessoa : public Perfil
{
    public:
        Pessoa(string nome, string dataDeNascimento, string pais);
        virtual ~Pessoa();
        string getPais();
        string getDataDeNascimento();
        // Adiciona o contato à lista de contatos da Pessoa
        void adiciona(Perfil *contato);
        // Implementa o método adicionadoPor para adicionar uma mensagem à pessoa que
        // ela foi adicionada pelo contato
        virtual void adicionadoPor(Perfil *contato);
        // Envia uma mensagem privada para um conta
        void envia(string texto, Perfil* contato);
    protected:
    private:
        string dataDeNascimento;
        string pais;

};

#endif // PESSOA_H




