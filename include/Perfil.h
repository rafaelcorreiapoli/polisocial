#ifndef PERFIL_H
#define PERFIL_H

#include <string>
#include <vector>
#include <list>
#include "Mensagem.h"

using namespace std;

class Mensagem;
class Perfil
{
    public:
        Perfil(string nome);
        virtual ~Perfil();
        // Obtêm o nome do Perfil.
        string getNome();
        // Informa que o perfil foi adicionado pelo perfil "contato"
        virtual void adicionadoPor(Perfil* contato) = 0;
        // Envia uma mensagem para todos os contatos do perfil.
        // O curtir informa se a mensagem pode ser curtida ou não.
        virtual void envia(string texto, bool curtir);
        // Recebe uma mensagem.
        virtual void recebe(Mensagem* m);
        // Obtêm a lista ligada com as mensagens recebidas.
        list<Mensagem*>* getMensagensRecebidas();
        // Obtêm a lista ligada com as mensagens enviadas.
        list<Mensagem*>* getMensagensEnviadas();
        // Método que define os contatos do Perfil
        // Deve ser usado apenas pela persistência
        void setContatos(vector<Perfil*>* perfis);
        // retorna a lista de contatos de um perfil.
        vector<Perfil*>* getContatos();
        // Retorna a lista de contatos alcançáveis.
        vector<Perfil*>* getContatosAlcancaveis();
    protected:
        string nome;
        int nContatos;
        list<Mensagem*> *msgsEnviadas;
        list<Mensagem*> *msgsRecebidas;
        vector<Perfil*> *contatos;
        //Perfil *contatos[9];
    private:
};

#endif // PERFIL_H
