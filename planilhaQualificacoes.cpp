/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaQualificacoes.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 15:58
 */

#include "planilhaQualificacoes.h"
#include <fstream>
#include <sstream>
#include "Tokenizer.h"
#include "StringUtils.h"
#include <string>
#include <iostream>


using namespace cpp_util;
using namespace std;
using namespace trabalho;


planilhaQualificacoes::planilhaQualificacoes() {
}


vector<qualificacoes> planilhaQualificacoes::getListaQualificacoes(){
    return vetorQualificacoes;
}

void planilhaQualificacoes::setListaQualificacoes(vector<qualificacoes> vetorQualificacoes){
    this->vetorQualificacoes = vetorQualificacoes;
}

vector<qualificacoes> planilhaQualificacoes::ler(int argc, char** argv){
    int tiraTitulo = 0;
    vector<string> args(argv, argv + argc );
    
    //converte char** para string
    
    for (int i = 0; i < argc; i++) {
        if (args[i].compare("-q") == 0) {
            ifstream file (args[i + 1].c_str());
            if (file.is_open()){
                
                string linha;
                
                 while (!file.eof()) {
                    if (tiraTitulo == 0) {
                        getline(file, linha);
                        cout << linha << endl;
                        tiraTitulo++;
                        
                        continue;
                    }
                    qualificacoes qualificacao;

                    //Lê a linha inteira e divide em um vetor de 5 posicoes
                    getline(file, linha);
                    cout << linha << endl;
                    
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
                    if (linhaDividida.size()==0)
                        break;
                    //Atribui as strings separadas para cada variavel
                    string ano = trim(linhaDividida[0]);
                     
                    string siglaVeiculo = trim(linhaDividida[1]);
                    
                    string qualis = trim(linhaDividida[2]);
                     
                    
                               
                    //Converte as variaveis para os tipos necessarios
                    
                    int ano2 = atoi(ano.c_str());                  


                    //Insere infos na qualificacao
                    qualificacao.setAno(ano2);
                    qualificacao.setQualis(qualis);
                    qualificacao.setSiglaVeiculo(siglaVeiculo);

                    //Insere o docente na lista de docentes
                    vetorQualificacoes.push_back(qualificacao);
                    

                }
                cout << "oi" ;
            }
            file.close();
        }
    }
    
    //cout << "oi";
        //codigoRepetidoParaDocente(vetorDocentes);
        return vetorQualificacoes;
}