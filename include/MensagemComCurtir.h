#ifndef MENSAGEMCOMCURTIR_H
#define MENSAGEMCOMCURTIR_H
#include <string>
#include "Perfil.h"
using namespace std;

class MensagemComCurtir : public Mensagem
{
    public:
        MensagemComCurtir(string texto, Perfil* autor);
        virtual ~MensagemComCurtir();
        void curtir();
        int getCurtidas();
    protected:
    private:
        int curtidas;
};

#endif // MENSAGEMCOMCURTIR_H
