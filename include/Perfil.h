#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#include <vector>
#include "Mensagem.h"
#include "ListaDeMensagens.h"
using namespace std;


// Imprime a lista de contatos a
void verContatosAlcancaveis();

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
        ListaDeMensagens* getMensagensRecebidas();
        // Obtêm a lista ligada com as mensagens enviadas.
        ListaDeMensagens* getMensagensEnviadas();
        // REMOVER?
        void verContatos();
        // retorna a lista de contatos de um perfil.
        vector<Perfil*>* getContatos();
        // Imprime a lista de contatos alcançáveis.
        void verContatosAlcancaveis();
    protected:
        string nome;
        int nContatos;
        ListaDeMensagens *msgsEnviadas;
        ListaDeMensagens *msgsRecebidas;
        vector<Perfil*>* contatos;
        //Perfil *contatos[9];
    private:
};

#endif // PERFIL_H
