/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   geraPublicacoes.cpp
 * Author: lorenzo
 * 
 * Created on 29 de Julho de 2017, 19:16
 */

#include "geraPublicacoes.h"
#include <fstream>
#include <sstream>
#include "NumberUtils.h"
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace cpp_util;
using namespace std;
using namespace trabalho;

geraPublicacoes::geraPublicacoes() {
}

int geraPublicacoes::getAnoPublicacao() {
    return anoPublicacao;
}

void geraPublicacoes::setAnoPublicacao(int anoPublicacao) {
    this->anoPublicacao = anoPublicacao;
}

double geraPublicacoes::getFatorImpactoVeiculo() {
    return fatorImpactoVeiculo;
}

void geraPublicacoes::setFatorImpactoVeiculo(double fatorImpactoVeiculo) {
    this->fatorImpactoVeiculo = fatorImpactoVeiculo;
}

vector<string> geraPublicacoes::getListaDocentes() {
    return vetorDocentes;
}

void geraPublicacoes::setListaDocentes(vector<string> listaDocentes) {
    this->vetorDocentes = vetorDocentes;
}

string geraPublicacoes::getNomeVeiculo() {
    return nomeVeiculo;
}

void geraPublicacoes::setNomeVeiculo(string nomeVeiculo) {
    this->nomeVeiculo = nomeVeiculo;
}

string geraPublicacoes::getQualisVeiculo() {
    return qualisVeiculo;
}

void geraPublicacoes::setQualisVeiculo(string qualisVeiculo) {
    this->qualisVeiculo = qualisVeiculo;
}

string geraPublicacoes::getSiglaVeiculo() {
    return siglaVeiculo;
}

void geraPublicacoes::setSiglaVeiculo(string siglaVeiculo) {
    this->siglaVeiculo = siglaVeiculo;
}

string geraPublicacoes::getTituloPublicacao() {
    return tituloPublicacao;
}

void geraPublicacoes::setTituloPublicacao(string tituloPublicacao) {
    this->tituloPublicacao = tituloPublicacao;
}

void geraPublicacoes::publicacoesParaRelatorio(vector<publicacoes> vetorPublicacoes) {

    stable_sort(vetorPublicacoes.begin(), vetorPublicacoes.end(), publicacoes::compareTo);
    criaArquivoPublicacoes(vetorPublicacoes);
}

void geraPublicacoes::criaArquivoPublicacoes(vector<publicacoes> vetorPublicacoes) {

    ofstream file("2-publicacoes.csv");
    file << "Ano;Sigla Veículo;Veículo;Qualis;Fator de Impacto;Título;Docentes\n";
    locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
    char buff[100];
    //awe
    for (int i = 0; i < vetorPublicacoes.size(); i++) {
        
        file << vetorPublicacoes[i].getAno() << ";" << vetorPublicacoes[i].getVeiculo().getSigla()
                << ";" << vetorPublicacoes[i].getVeiculo().getNome() << ";";
        
        geraPublicacoes g;
        
        //GAMBIARRA ---->>> xD converte desconverte divide por 1000 converte resize xDDDD
        snprintf(buff, sizeof(buff), "%.3f", vetorPublicacoes[i].getVeiculo().getFatorImpacto());
        
        string aux(buff);
        
        double d = parseDouble(aux,LOCALE_PT_BR);
        
        d/=1000;
        
        string s = formatDouble(d,LOCALE_PT_BR);
        s.resize(s.size()-3);
        
        
        
        qualificacoes qualis = g.qualisAtual(vetorPublicacoes[i].getVeiculo().getQualis(), vetorPublicacoes[i].getAno());
        
        file << qualis.getQualis() << ";" << s << ";" << vetorPublicacoes[i].getTitulo() << ";";

        for (int j = 0; j < vetorPublicacoes[i].getAutores().size(); j++) {
            
            if (j == vetorPublicacoes[i].getAutores().size() - 1)
                file << vetorPublicacoes[i].getAutores()[j].getNome();
            else
                file << vetorPublicacoes[i].getAutores()[j].getNome() << ",";
        }
        
        file << endl;
    }
}

qualificacoes geraPublicacoes::qualisAtual(vector<qualificacoes> vetorQualis, int ano) {

    int menor = INT_MAX, posicao = 0;
    for (int i = 0; i < vetorQualis.size(); i++) {
        int diff = ano - vetorQualis[i].getAno();
        if (diff >= 0 && diff <= menor) {
            menor = diff;
            posicao = i;
        }
    }
    
    
    if (menor == INT_MAX){
        qualificacoes qualis;
        qualis.setQualis("NC");
        return qualis;
    }
    return vetorQualis[posicao];
}