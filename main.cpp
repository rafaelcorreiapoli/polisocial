#include <iostream>
#include <string>
#include <typeinfo>
#include "Pessoa.h"
#include "Departamento.h"
#include "Functions.h"
using namespace std;

const int ROUTE_MAIN = 0;
const int ROUTE_LOGIN = 1;
const int ROUTE_REGISTER = 2;
const int ROUTE_REGISTER_DEPARTAMENTO = 22;
const int ROUTE_PROFILE = 3;
const int ROUTE_ADD_CONTACT = 4;
const int ROUTE_SENT_MESSAGES = 5;
const int ROUTE_SEND_MESSAGE = 6;
const int ROUTE_RECEIVED_MESSAGES = 7;
const int ROUTE_CONTATOS_ALCANCAVEIS = 8;
const int CMD_QUIT = 0;


//  +++++++++++++++++++ FALTA FAZER ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//  • Jogue uma exceção do tipo logic_error quando uma pessoa tentar se adicionar ou tentar
//  adicionar alguém que ela já tem como contato.
//  Trate a exceção na classe / método que faz a interface com o usuário.

//  • Jogue uma exceção do tipo logic_error quando uma pessoa tentar enviar uma mensagem
//  privada a alguém que não é seu contato.
//  o Trate a exceção na classe / método que faz a interface com o usuário.

//  • Crie um método que imprima o nome dos contatos alcançáveis de um perfil. Um contato
//  alcançável é um contato direto do perfil ou é um contato de um de seus contatos (veja maiores
//  detalhes na Seção 3).
//  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//Perfil* perfis[10];

int route = 0;
int cmd;
//int totalPerfis = 0;
int currentUser;

vector<Perfil*>* perfis = new vector<Perfil*>;

// FUNCOES DE APOIO-------------------------------------------------------
bool ehPessoa(Perfil *perfil){
    return (dynamic_cast<Pessoa*>(perfil) != NULL);
}

bool ehDepartamento(Perfil *perfil){
    return (dynamic_cast<Departamento*>(perfil) != NULL);
}

bool ehPerfil(Perfil *perfil) {
    return (dynamic_cast<Perfil*>(perfil) != NULL);
}


int printPessoas(){
    vector<Perfil*>::iterator it;
    int i = 0;
    for (it = perfis->begin(); it != perfis->end(); it++){
        if (ehPessoa(*it)){
            cout << it - perfis->begin() + 1 << ") " << (*it)->getNome() << endl;
        }
    }

    /*
    int i;
    for (i=0; i < totalPerfis; i++){
        if (ehPessoa(perfis[i])){
            cout << i+1 << ") " << perfis[i]->getNome() << endl;
        }
    }
    */
}


/*
int printDepartamentos(){
    int i;
    for (i=0; i < totalPerfis; i++){
        if (ehDepartamento(perfis[i])){
            cout << i+1 << ") " << perfis[i]->getNome() << endl;
        }
    }
}
*/

int printPerfis(){
    vector<Perfil*>::iterator it;
    int i = 0;
    for (it = perfis->begin(); it != perfis->end(); it++){
        cout << it - perfis->begin() + 1 << ") " << (*it)->getNome() << endl;
    }
}

//----------_FIM FUNCOES DE APOIO-----------------------------------------
int main()
{
    do{
        switch(route){
            case (ROUTE_MAIN):{ // TELA PRINCIPAL ---------------------------
                //OUTPUT
                cout << "PoliSocial [" << perfis->size() << "] perfis cadastrados" << endl;
                cout << "1) Cadastrar Pessoa" << endl;
                cout << "2) Cadastrar Departamento" << endl;
                cout << "3) Logar como Perfil" << endl;
                cout << "0) Terminar" << endl;

                //INPUT
                cin >> cmd;
                //CONTROLLER
                switch (cmd){
                    case 1:
                        route=ROUTE_REGISTER;
                    break;
                    case 2:
                        route=ROUTE_REGISTER_DEPARTAMENTO;
                    break;
                    case 3:
                        route=ROUTE_LOGIN;
                    break;
                }
            break;}// ----------------FIM TELA PRINCIPAL-----------------------------------------------
            case (ROUTE_LOGIN):{ // LOGIN ---------------------------
                int opt;
                //OUTPUT
                cout << "Escolha uma dos Perfis" << endl;
                printPerfis();
                cin >> opt;

                if (opt != 0){
                    opt--;

                    if (ehPessoa(perfis->at(opt)) || ehDepartamento(perfis->at(opt))){
                        route = ROUTE_PROFILE;
                        currentUser = opt;
                    }else {
                        cout << "Perfil invalido!" << endl;
                    }
                }else{
                    route = ROUTE_MAIN;
                }
            break;}// ----------------FIM LOGIN-----------------------------------------------
            case (ROUTE_REGISTER):{ // REGISTRAR PESSOA ---------------------------
                cin.ignore(100, '\n');
                string nome;
                string dataDeNascimento;
                string pais;

                cout <<"Informe os dados da pessoa" << endl;
                cout << "Nome:";
                getline(cin, nome);
                cout << "Data de Nascimento:";
                getline(cin, dataDeNascimento);
                cout << "Pais:";
                getline(cin, pais);
                cout << "Pessoa cadastrada com sucesso!" << endl;

                //pessoas[totalPessoas] =
                //perfis[totalPerfis] = new Pessoa(nome, dataDeNascimento, pais);
                perfis->push_back(new Pessoa(nome, dataDeNascimento, pais));
                //totalPerfis++;
                //totalPessoas++;

                route = ROUTE_MAIN;
            break;} // ----------------FIM REGISTRAR PESSOA-----------------------------------------------
            case (ROUTE_REGISTER_DEPARTAMENTO):{ // REGISTRAR DEPARTAMENTO ---------------------------
                cin.ignore(100, '\n');
                string nome;
                string site;
                int responsavelId;
                Pessoa* responsavel;

                cout <<"Informe os dados do departamento" << endl;
                cout << "Nome:";
                getline(cin, nome);
                cout << "Site:";
                getline(cin, site);
                cout << "Escolha um responsavel:" << endl;
                printPessoas();
                cin >> responsavelId;

                if (responsavelId != 0) {
                    responsavelId--;

                    if ( ehPessoa( perfis->at(responsavelId))){
                        responsavel = dynamic_cast<Pessoa *>(perfis->at(responsavelId));
                        perfis->push_back(new Departamento(nome, site, responsavel));
                    }else {
                        cout << "Pessoa invalida" << endl;
                    }
                }else {
                    cout << "Cancelou criação de perfil" << endl;
                }

                route = ROUTE_MAIN;
            break;}// ----------------FIM REGISTRAR DEPARTAMENTO-----------------------------------------------
            case (ROUTE_PROFILE):{ // VER PERFIL -----------------------------------------------
                int opt;
                Perfil* perfilLogado = perfis->at(currentUser);

                if (ehPessoa(perfis->at(currentUser))) {
                    Pessoa* perfilLogado = dynamic_cast<Pessoa *>(perfis->at(currentUser));
                    cout << "------------" << endl;
                    cout << "Pessoa: " << perfilLogado->getNome() << endl;
                    cout << perfilLogado->getDataDeNascimento() << " " << perfilLogado->getPais() << endl;
                    cout << "------------" << endl;

                    cout << "Contatos: " << endl;
                    //perfilLogado->verContatos();

                    cout << "1) Ver mensagens enviadas" << endl;
                    cout << "2) Ver mensagens recebidas" << endl;
                    cout << "3) Escrever Mensagem" << endl;
                    cout << "4) Ver contatos alcancáveis" << endl;
                    cout << "5) Adicionar contato" << endl;
                    cout << "0) Logoff" << endl;

                }else if (ehDepartamento(perfis->at(currentUser))) {
                    Departamento* perfilLogado = dynamic_cast<Departamento *>(perfis->at(currentUser));
                    cout << "------------" << endl;
                    cout << "Departamento: " << perfilLogado->getNome() << endl;
                    cout << "Responsavel: " << perfilLogado->getResponsavel()->getNome() << endl;
                    cout << "------------" << endl;

                    cout << "Contatos: " << endl;
                    //perfilLogado->verContatos();

                    cout << "------------" << endl;
                    cout << "1) Ver mensagens enviadas" << endl;
                    cout << "2) Ver mensagens recebidas" << endl;
                    cout << "3) Escrever Mensagem" << endl;
                    cout << "4) Ver contatos alcancáveis" << endl;
                    cout << "0) Logoff" << endl;
                }

                cin >> opt;

                switch (opt){
                    case 0:
                        cout << "Logging off..." << endl;
                        currentUser = 0;
                        route = ROUTE_MAIN;
                    break;
                    case 1:
                        route = ROUTE_SENT_MESSAGES;
                    break;
                    case 2:
                        route = ROUTE_RECEIVED_MESSAGES;
                    break;
                    case 3:
                        route = ROUTE_SEND_MESSAGE;
                    break;
                    case 4:
                        route = ROUTE_CONTATOS_ALCANCAVEIS;
                    break;
                    case 5:
                        if (ehPessoa(perfilLogado)) {
                            route = ROUTE_ADD_CONTACT;
                        }else {
                            cout << "Departamentos não adicionam contatos!";
                        }
                    break;
                }
            break;} // ----------------FIM VER PERFIL------------------------------------------------
            case (ROUTE_ADD_CONTACT):{  // ADICIONAR CONTATO -----------------------------------------------
                Pessoa* perfilLogado = dynamic_cast<Pessoa *>(perfis->at(currentUser));
                int contato;
                cout << "Adicionar contato" << endl;
                printPerfis();
                cin >> contato;

                if (contato != 0){
                    contato--;
                    if (ehPerfil(perfis->at(contato))){
                        perfilLogado->adiciona(perfis->at(contato));
                        cout << perfilLogado->getNome() << " conectado a " << perfis->at(contato)->getNome() << endl;
                        route = ROUTE_PROFILE;
                    }else {
                        cout << "Perfil invalido";
                    }
                }else {
                    route = ROUTE_PROFILE;
                }
            break;}  // ----------------FIM ADICIONAR CONTATO------------------------------------------------
            case (ROUTE_SENT_MESSAGES):{ // VER MENSAGENS ENVIADAS ------------------------------------------
                cout << "Mensagens Enviadas" << endl;
                cout << "------------------" << endl;
                Perfil* perfilLogado = perfis->at(currentUser);
                perfilLogado->getMensagensEnviadas()->imprime();
                route = ROUTE_PROFILE;
                //pessoas[currentUser]->getMensagensEnviadas()->imprime();
                //route=ROUTE_PROFILE;
            break;} // ----------------FIM VER MENSAGENS ENVIADAS------------------------------------------------
            case (ROUTE_SEND_MESSAGE):{ // ENVIAR MENSAGEM ------------------------------------------
                //Pessoa enviando mensagem
                if (ehPessoa(perfis->at(currentUser))) {
                    int privada;
                    cout << "A mensagem é privada? (0 - nao, 1 - sim)?" << endl;
                    cin >> privada;

                    if (!privada) {
                        Perfil* perfilLogado = perfis->at(currentUser);
                        int podeSerCurtida;
                        string msg;

                        cout << "A mensagem pode ser curtida? (0 - nao, 1 - sim) ?" << endl;
                        cin >> podeSerCurtida;

                        cout << "Digite a mensagem" << endl;
                        cin.ignore(100, '\n');
                        getline(cin, msg);

                        perfilLogado->envia(msg, podeSerCurtida);
                        cout << "Mensagem enviada a todos os contatos";
                    }else {
                        Pessoa* perfilLogado = dynamic_cast<Pessoa *>(perfis->at(currentUser));
                        string msg;
                        int destinatario;

                        cout << "Escolha o destinatario" << endl;
                        printPerfis();
                        cout << "Digite um numero ou 0 para cancelar:" ;
                        cin >> destinatario;

                        if (destinatario !=0) {
                            destinatario--;
                            cout << "Digite a mensagem: " ;
                            cin.ignore(100, '\n');
                            getline(cin, msg);

                            perfilLogado->envia(msg, perfis->at(destinatario));
                            cout << "Mensagem enviada a " << perfis->at(destinatario)->getNome() << endl;
                        }else {
                            route = ROUTE_PROFILE;
                        }

                    }
                }else if (ehDepartamento(perfis->at(currentUser))){ //Departamento enviando mensagem
                    Perfil* perfilLogado = perfis->at(currentUser);
                    int podeSerCurtida;
                    string msg;

                    cout << "A mensagem pode ser curtida? (0 - nao, 1 - sim) ?" << endl;
                    cin >> podeSerCurtida;

                    cout << "Digite a mensagem" << endl;
                    cin.ignore(100, '\n');
                    getline(cin, msg);

                    perfilLogado->envia(msg, podeSerCurtida);
                    cout << "Mensagem enviada a todos os contatos";
                }


                route = ROUTE_PROFILE;
            break;} // ------------------- FIM ENVIAR MENSAGEM ------------------------------------------
            case (ROUTE_RECEIVED_MESSAGES):{ // MENSAGENS RECEBIDAS ------------------------------------------
                int opt;
                Perfil* perfilLogado = perfis->at(currentUser);
                ListaDeMensagens* lista = perfilLogado->getMensagensRecebidas();

                cout<< "Mensagens Recebidas" << endl;
                cout << "------------------" << endl;
                lista->imprime();
                cout << "Digite o numero da mensagem para curtir ou 0 para voltar" << endl;
                cin >> opt;
                if (opt != 0){
                    opt--;
                    Elemento *pointer = new Elemento;
                    int i;
                    pointer = lista->getHead();
                    for (i=0; i < opt; i++){
                        pointer = pointer->next;
                    }
                    Mensagem *msg = pointer->value;
                    msg->incLikes();
                }
                route = ROUTE_PROFILE;
            break;}// ------------------- FIM MENSAGENS RECEBIDAS ------------------------------------------
        }
    }while(!(route == ROUTE_MAIN && cmd == CMD_QUIT));
}
