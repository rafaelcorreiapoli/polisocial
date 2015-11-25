#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>
#include "Perfil.h"

using namespace std;

class Perfil;
class Mensagem
{
    public:
        Mensagem(string texto, Perfil* autor);
        virtual ~Mensagem();
        string getTexto();
        Perfil* getAutor();

    protected:
    private:
        string texto;
        Perfil* autor;
};

#endif // MENSAGEM_H
