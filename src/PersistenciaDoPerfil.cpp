#include "PersistenciaDoPerfil.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include "Perfil.h"
#include "Pessoa.h"
#include "Departamento.h"
#include "Functions.h"
using namespace std;



PersistenciaDoPerfil::PersistenciaDoPerfil(string arquivo)
{
    this->arquivo = arquivo;
    ifstream inFile;
    inFile.open(arquivo.c_str());

    if (inFile.fail()) {
        ofstream outFile;
        outFile.open(arquivo.c_str());
        outFile.close();
    }
    inFile.close();

}


vector<Perfil*>* PersistenciaDoPerfil::obter()
{
    vector<Perfil*>* perfis = new vector<Perfil*>();

    ifstream inFile;
    inFile.open(this->arquivo.c_str());

    if (inFile.fail()){
        throw new runtime_error("Nao conseguiu abrir o arquivo");
    } else {
        string line;
        int i = 0;
        string perfilNome;
        string perfilDataDeNascimento;
        string perfilPais;
        string perfilSite;


        while (getline(inFile, line)){
            if (line=="P"){
                getline(inFile, perfilNome);
                getline(inFile, perfilDataDeNascimento);
                getline(inFile, perfilPais);

                Pessoa* p = new Pessoa(perfilNome, perfilDataDeNascimento, perfilPais);
                perfis->push_back(p);
            } else if (line=="D"){
                getline(inFile, perfilNome);
                getline(inFile, perfilSite);

                Departamento *d = new Departamento(perfilNome, perfilSite);
                perfis->push_back(d);
            } else if (line == "#"){
                int j = 0;
                while (getline(inFile, line)) {
                    Perfil* perfil = perfis->at(j);

                    int numeroDeContatos;
                    istringstream iss(line);
                    iss >> numeroDeContatos;
                    vector<Perfil*>* contatos = new vector<Perfil*>;

                    for (int i = 0; i < numeroDeContatos; i++){
                        int intContato;
                        iss >> intContato;
                        intContato--;

                        contatos->push_back(perfis->at(intContato));
                    }
                    perfil->setContatos(contatos);

                    if (ehDepartamento(perfil)) {
                        Departamento* d = dynamic_cast<Departamento*>(perfil);

                        int intResponsavel;
                        iss >> intResponsavel;
                        intResponsavel--;
                        Pessoa* responsavel = dynamic_cast<Pessoa*>(perfis->at(intResponsavel));

                        d->setResponsavel(responsavel);
                    }

                    j++;
                }

            }
        }
    }
    inFile.close();
    return perfis;
}

void PersistenciaDoPerfil::salvar(vector<Perfil*>* perfis)
{
    vector<Perfil*>::iterator it;
    ofstream outFile;

    outFile.open(this->arquivo.c_str());

    if (outFile.fail()) {

    }else {
        for (it = perfis->begin(); it != perfis->end(); it++) {
            if (ehPessoa(*it)) {
                Pessoa* p = dynamic_cast<Pessoa*>(*it);
                outFile << "P" << endl;
                outFile << p->getNome() << endl;
                outFile << p->getDataDeNascimento() << endl;
                outFile << p->getPais() << endl;
            } else if (ehDepartamento((*it))) {
                Departamento *d = dynamic_cast<Departamento*>(*it);
                outFile << "D" << endl;
                outFile << d->getNome() << endl;
                outFile << d->getSite() << endl;


            }
        }

        outFile << "#" << endl;
        for (it = perfis->begin(); it !=perfis->end(); it++){
            vector<Perfil*>::iterator it2;
            vector<Perfil*>* contatos = (*it)->getContatos();

            outFile << contatos->size();
            for (it2 = contatos->begin(); it2 != contatos->end(); it2++) {
                vector<Perfil*>::iterator it3 = find(perfis->begin(), perfis->end(), (*it2));
                int intContato = distance(perfis->begin(), it3) + 1;
                outFile << " " << intContato;
            }

            if (ehDepartamento(*it)) {
                Departamento *d = dynamic_cast<Departamento*>(*it);
                vector<Perfil*>::iterator it3 = find(perfis->begin(), perfis->end(), d->getResponsavel());
                int intResponsavel = distance(perfis->begin(), it3) + 1;
                outFile << " " << intResponsavel;
            }

            outFile << endl;
        }


    }

    outFile.close();
}


PersistenciaDoPerfil::~PersistenciaDoPerfil()
{
    //dtor
}
