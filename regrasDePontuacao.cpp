/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   regrasDePontuacao.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 16:22
 */

#include "regrasDePontuacao.h"
#include "DateUtils.h"
#include "StringUtils.h"
#include <iostream>
#include "Tokenizer.h"

using namespace std;
using namespace cpp_util;
using namespace trabalho;

regrasDePontuacao::regrasDePontuacao() {
}

time_t regrasDePontuacao::getDataInicio(){
    return dataInicio;
}

void regrasDePontuacao::setDataInicio(time_t dataInicio){
    this->dataInicio = dataInicio;
}

time_t regrasDePontuacao::getDataFim(){
    return dataFim;
}

void regrasDePontuacao::setDataFim(time_t dataFim){
    this->dataFim = dataFim;
}

vector<string> regrasDePontuacao::getQualis(){
    return qualis;
}

void regrasDePontuacao::setQualis(vector<string> qualis){
    this->qualis = qualis;
}

vector<int> regrasDePontuacao::getPontos(){
    return pontos;
}

void regrasDePontuacao::setPontos(vector<int> pontos){
    this->pontos = pontos; 
}

double regrasDePontuacao::getMultiplicador(){
    return fatorMultiplicador;
}

void regrasDePontuacao::setMultiplicador(double multiplicador){
    this->fatorMultiplicador = fatorMultiplicador;
}

int regrasDePontuacao::getQuantidadeAnosConsiderar(){
    return quantidadeAnos;
}

void regrasDePontuacao::setQuantidadeAnosConsiderar(int quantidadeAnosConsiderar){
    this->quantidadeAnos = quantidadeAnosConsiderar;
}

int regrasDePontuacao::getPontuacaoMinimaRecredenciamento(){
    return pontuacaoMinima;
}

void regrasDePontuacao::setPontuacaoMinimaRecredenciamento(int pontuacaoMinimaRecredenciamento){
    this->pontuacaoMinima = pontuacaoMinima;
}

void regrasDePontuacao::expandeQualis(vector<regrasDePontuacao> vetorRegras, int ano){
    
    vector<string> qualis;
    vector<int> pontos;
    
    qualis.push_back("A1");
    qualis.push_back("A2");
    qualis.push_back("B1");
    qualis.push_back("B2");
    qualis.push_back("B3");
    qualis.push_back("B4");
    qualis.push_back("B5");
    qualis.push_back("C");
    
    //preenche o vetor de pontos com -1 em cada posicao
    for (int i = 0; i<8 ; i++)
        pontos.push_back(-1);
    
    for (int i = 0; i < vetorRegras.size(); i++) {

        
        time_t anoRegra = vetorRegras[i].dataInicio;
        
        vector<string> data_formatada;
        Tokenizer token(formatDate(anoRegra, "%d/%m/%Y"), '/');
        
        data_formatada = token.remaining();
        int anoDaRegra = atoi(data_formatada[2].c_str());
        

        if (anoDaRegra == ano) {
            for (int k = 0; k < vetorRegras[i].getQualis().size(); k++) {
                for (int j = 0; j < qualis.size(); j++) {
                    if (vetorRegras[i].getQualis()[k].compare(qualis[j]) == 0) {
                        pontos[j] = vetorRegras[i].getPontos()[k];
                        break;
                    }
                }
            }
        }

        for (int x = 0; x < (pontos.size() - 1); x++) 
            if (pontos[x + 1] == -1) 
                pontos[x + 1] = pontos[x];
        

        vetorRegras[i].setQualis(qualis); 
        vetorRegras[i].setPontos(pontos);
            
        
    }
    

}