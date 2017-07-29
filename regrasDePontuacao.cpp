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
    
}