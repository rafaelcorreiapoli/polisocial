#ifndef PERSISTENCIADOPERFIL_H
#define PERSISTENCIADOPERFIL_H
#include <string>
#include <vector>
#include "Perfil.h"
using namespace std;

class PersistenciaDoPerfil
{
    public:
        PersistenciaDoPerfil(string arquivo);
        virtual ~ PersistenciaDoPerfil();
        vector<Perfil*>* obter();
        void salvar(vector<Perfil*>* perfis);
    protected:
    private:
        string arquivo;
};

#endif // PERSISTENCIADOPERFIL_H
