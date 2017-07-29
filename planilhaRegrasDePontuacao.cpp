/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaRegrasDePontuacao.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 16:18
 */

#include "planilhaRegrasDePontuacao.h"
#include "Tokenizer.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "NumberUtils.h"
#include "StringUtils.h"
#include "DateUtils.h"

using namespace trabalho;
using namespace std;
using namespace cpp_util;

planilhaRegrasDePontuacao::planilhaRegrasDePontuacao() {
}

vector<regrasDePontuacao> planilhaRegrasDePontuacao::getListaRegras(){
    return vetorRegras;
}

void planilhaRegrasDePontuacao::setListaRegras(vector<regrasDePontuacao> vetorRegras){
    this->vetorRegras = vetorRegras;
}

vector<regrasDePontuacao> planilhaRegrasDePontuacao::ler(int argc, char** argv){
    int tiraTitulo = 0;
    vector<string> args(argv, argv + argc );
    
    //converte char** para string
    
    for (int i = 0; i < argc; i++) {
        if (args[i].compare("-r") == 0) {
            ifstream file (args[i + 1].c_str());
            if (file.is_open()){
                
                string linha;
                
                while (! file.eof()) {
                    if (tiraTitulo == 0) {
                        getline(file, linha);
                        //cout << linha << endl;
                        tiraTitulo++;
                        
                        continue;
                    }
                    regrasDePontuacao regra;

                    
                    getline(file, linha);
                    //cout << linha << endl;
                    
                    vector<string> linhaDividida;
                    istringstream f(linha);
                    string temp;
                    
                    //Lê a linha inteira e divide em um vetor de 5 posicoes
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
                    string inicioVigencia = trim(linhaDividida[0]);
                    string fimVigencia = trim(linhaDividida[1]);
                    string qualis = trim(linhaDividida[2]);

                    string pontos = trim(linhaDividida[3]);
                    string multiplicador = trim(linhaDividida[4]);
                    string anos = trim(linhaDividida[5]);
                    string minimoPontos = trim(linhaDividida[6]);
                    
                    
                               
                    //Converte as variaveis para os tipos necessarios
                    
                    
                    

                    int anos2 = atoi(anos.c_str());
                    locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
                    double multiplicador2 = parseDouble(multiplicador,LOCALE_PT_BR);
                    int minimoPontos2 = atoi(minimoPontos.c_str());                
                    
                     /*qualis separados por virgula, e pontos tambem.
                        Por isso, e necessario fazer um vetor com eles*/
                    Tokenizer token1(qualis, ',');
                    Tokenizer token2(pontos, ',');
                    
                    vector<string> qualis2 = token1.remaining();
                    
                    vector<string> pontos2 = token2.remaining();
                    
                    //Convertendo o vetor de string para inteiro
                    
                    vector<int> pontos3;
                    //cout << pontos3.size() << "<<<<<<<<" << endl;
                    for (int j = 0; j < pontos2.size(); j++) {
                        pontos3.push_back(atoi(pontos2[j].c_str()));
                        
                    }
                    
                    //Insere infos na qualificacao
                    regra.setDataFim(parseDate(fimVigencia,"%d/%m/%Y"));
                    regra.setDataInicio(parseDate(inicioVigencia,"%d/%m/%Y"));
                    regra.setMultiplicador(multiplicador2);
                    regra.setPontos(pontos3);
                    regra.setPontuacaoMinimaRecredenciamento(minimoPontos2);
                    regra.setQualis(qualis2);
                    regra.setQuantidadeAnosConsiderar(anos2);

                    //Insere o docente na lista de docentes
                    vetorRegras.push_back(regra);

                }
            }
        
        }
    }

        //codigoRepetidoParaDocente(vetorDocentes);
        return vetorRegras;
}

void planilhaRegrasDePontuacao::qualisDesconhecidoParaRegras(vector<regrasDePontuacao> vetorRegras){
    
}