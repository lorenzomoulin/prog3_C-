/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaDocentes.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 13:34
 */

#include "planilhaDocentes.h"
#include <fstream>
#include <sstream>
#include "Tokenizer.h"
#include "StringUtils.h"
#include <string>
#include "docentes.h"

using namespace cpp_util;
using namespace trabalho;
using namespace std;

planilhaDocentes::planilhaDocentes() {
}

map<int,docentes> planilhaDocentes::getListaDocentes(){
    return mapaDocentes;
}

void planilhaDocentes::setListaDocentes(map<int,docentes> mapaDocentes){
    this->mapaDocentes = mapaDocentes;
}

map<int,docentes> planilhaDocentes::ler(char **argv, int argc){
    int tiraTitulo = 0;
    vector<string> args(argv, argv + argc );
    
    //converte char** para string
    
    for (int i = 0; i < argc; i++) {
        if (args[i].compare("-d") == 0) {
            ifstream file (args[i + 1].c_str());
            if (file.is_open()){
                
                string linha;
                int j =0;
                while (! file.eof()) {
                    if (tiraTitulo == 0) {
                        getline(file, linha);
                        //cout << linha << endl;
                        tiraTitulo++;
                        
                        continue;
                    }
                    docentes docente;

                    //Lê a linha inteira e divide em um vetor de 5 posicoes
                    getline(file, linha);
                    //cout << linha << endl;
                    
                    vector<string> linhaDividida;
                    istringstream f(linha);
                    string temp;
                    
                    while(getline(f,temp,';')) 
                        linhaDividida.push_back(temp);
                    
                    /*cout << linhaDividida[0] << endl;
                    cout << linhaDividida[1] << endl;
                    cout << linhaDividida[2] << endl;
                    cout << linhaDividida[3] << endl;
                    //cout << linhaDividida[4] << endl;*/
                    
                    //Atribui as strings separadas para cada variavel
                    //cout << linhaDividida.size() << "<<<<<<<"<< endl;
                    if (linhaDividida.size()==0)
                        break;
                    string codigo = linhaDividida[0];
                    
                    codigo = trim(codigo);
                     
                    string nome = trim(linhaDividida[1]);
                    
                    string dataNascimento = trim(linhaDividida[2]);
                     
                    string dataIngresso = trim(linhaDividida[3]);
                    
                    bool ehCoordenador2 = false;
                    
                    if(linhaDividida.size()==5){
                        string ehCoordenador = trim(linhaDividida[4]);
                        
                        if (!ehCoordenador.compare("X")) {
                            ehCoordenador2 = true;
                        }
                    }
                    
                    

                    

                    //Converte as variaveis para os tipos necessarios
                    long codigo_convertido = atol(codigo.c_str());
                    
                    
                    


                    //Insere infos no docente
                    docente.setCodigo(codigo_convertido);
                    docente.setDataIngresso(parseDate(dataIngresso,DATE_FORMAT_PT_BR_SHORT));
                    docente.setDataNascimento(parseDate(dataNascimento,DATE_FORMAT_PT_BR_SHORT));
                    docente.setEhCoordenador(ehCoordenador2);
                    docente.setNome(nome);
                    

                    //Insere o docente na lista de docentes
                    mapaDocentes[j] = docente;
                    j++;
                }
            }
            file.close();
        }
    }
    //for da sorte, vai dar certo, só confia
    /*for (int c = 0 ; c < vetorDocentes.size() ; c++){
        
        cout <<  vetorDocentes[c].getCodigo() << ";";
        cout <<  vetorDocentes[c].getNome() << ";";
        
        cout << formatDate(vetorDocentes[c].getDataNascimento(),"%d/%m/%Y") << ";" ;
        cout <<  formatDate(vetorDocentes[c].getDataIngresso(),"%d/%m/%Y") << ";" ;
        if (vetorDocentes[c].getEhCoordenador())
            cout <<  vetorDocentes[c].getEhCoordenador() << endl ;
        else 
            cout << endl;
        
    }*/

        //codigoRepetidoParaDocente(vetorDocentes);
        return mapaDocentes;
}

void planilhaDocentes::codigoRepetidoParaDocente(map<int,docentes> mapaDocentes){
    
}