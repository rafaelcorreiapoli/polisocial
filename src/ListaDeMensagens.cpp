#include "ListaDeMensagens.h"
#include "Mensagem.h"
ListaDeMensagens::~ListaDeMensagens()
{
    delete[] this;
}


        ListaDeMensagens::ListaDeMensagens () { // Construtor padrão; único
            head = NULL;
        }

        Elemento* ListaDeMensagens::getHead(){
            return head;
        }
        void ListaDeMensagens::pushFinal (Mensagem *x) { // Método para adicionar um elemento novo ao final da lista.
            Elemento *novo = new Elemento;
            novo->value = x;
            if (head == NULL)
                head = novo;
            else {
                Elemento *onde = head;
                while (onde->next)
                    onde = onde->next;
                onde->next = novo;
            }
        }

        void ListaDeMensagens::imprime(){ // Método para imprimir, na saída padrão, todos os elementos na tela;
            Elemento* temp = head;
            int i = 0;
            while (temp) {
                i++;
                Mensagem* msg = temp->value;

                cout << i << ") " << msg->getTexto();
                if (msg->podeCurtir()){
                    cout << " (" << msg->getLikes() << " curtidas)";
                }
                cout << endl;
                temp = temp->next;
            }
            return;
        }


