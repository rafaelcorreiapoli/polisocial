#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>

using namespace std;

class Mensagem
{
    public:
        Mensagem(string texto, bool podeSerCurtida);
        virtual ~Mensagem();
        string getTexto(){
            return texto;
        };
        void incLikes(){
            if (this->podeCurtir()){
                this->likes++;
            }
        }
        int getLikes(){
            return likes;
        }
        bool podeCurtir(){
            return podeSerCurtida;
        }
    protected:
    private:
        string texto;
        int autor;
        int likes;
        bool podeSerCurtida;
};

#endif // MENSAGEM_H
