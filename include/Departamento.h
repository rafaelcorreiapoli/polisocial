#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <string>
#include "Perfil.h"
#include "Pessoa.h"
using namespace std;

class Departamento : public Perfil
{
    public:
        Departamento(string nome, string site, Pessoa* responsavel);
        virtual ~Departamento();
        string getSite();
        Pessoa* getResponsavel();
        // Redefine o método "recebe" para repassa-la ao responsável.
        // A mensagem recebida deve também ser adicionada às mensagens recebidas do
        // departamento.
        virtual void recebe(Mensagem* m);
        // Implementa o método adicionadoPor para adicionar o Perfil como contato do
        // Departamento
        virtual void adicionadoPor(Perfil* contato);
    protected:
    private:
        string site;
        Pessoa* responsavel;
};

#endif // DEPARTAMENTO_H
