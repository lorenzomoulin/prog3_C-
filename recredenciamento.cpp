/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recredenciamento.cpp
 * Author: lorenzo
 * 
 * Created on 30 de Julho de 2017, 15:23
 */

#include "recredenciamento.h"
#include "DateUtils.h"
#include "NumberUtils.h"
#include "Tokenizer.h"
#include "geraPublicacoes.h"
#include "docentes.h"
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;
using namespace cpp_util;
using namespace trabalho;

recredenciamento::recredenciamento() {
}

string recredenciamento::getNomeDocente() {
    return nomeDocente;
}

void recredenciamento::setNomeDocente(string nomeDocente) {
    this->nomeDocente = nomeDocente;
}

double recredenciamento::getPontuacaoAlcancada() {
    return pontuacaoAlcancada;
}

void recredenciamento::setPontuacaoAlcancada(double pontuacaoAlcancada) {
    this->pontuacaoAlcancada = pontuacaoAlcancada;
}

int recredenciamento::getRecredenciado() {
    return recredenciado;
}

void recredenciamento::setRecredenciado(int recredenciado) {
    this->recredenciado = recredenciado;
}

void recredenciamento::calculaPontuacao(vector<docentes>& vetorDocentes, int ano, vector<regrasDePontuacao>& vetorRegras, vector<publicacoes>& vetorPublicacoes) {

    regrasDePontuacao regra;

    recredenciamento r;
    regra = r.retornaRegraRecredenciamento(vetorRegras, ano);

    geraPublicacoes g;
    int diferenca = 0;
    qualificacoes qualis;

    /////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < vetorDocentes.size(); i++) {
        for (int j = 0; j < vetorPublicacoes.size(); j++) {
            vector<docentes> autores(vetorPublicacoes[j].getAutores());
            for (int k = 0; k < autores.size(); k++) {
                if (vetorDocentes[i].getCodigo() == autores[k].getCodigo()) {
                    
                    qualis = g.qualisAtual(vetorPublicacoes[j].getVeiculo().getQualis(), vetorPublicacoes[j].getAno());
                    string tipo = vetorPublicacoes[j].getVeiculo().getTipo();
                    
                    for (int l = 0; l < regra.getQualis().size(); l++) {
                        
                        diferenca = ano - vetorPublicacoes[j].getAno();
                        if (diferenca <= regra.getQuantidadeAnosConsiderar() && diferenca != 0) {
                            
                            if (regra.getQualis()[l] == qualis.getQualis()) {
                                
                                if (tipo == "P")
                                    vetorDocentes[i].setPontuacao(vetorDocentes[i].getPontuacao() + regra.getPontos()[l] * regra.getMultiplicador());
                                else if (tipo == "C")
                                    vetorDocentes[i].setPontuacao(vetorDocentes[i].getPontuacao() + regra.getPontos()[l]);
                            }
                        }
                    }
                }
            }
        }
        cout << "pontuacao: " << vetorDocentes[i].getPontuacao() << endl;
    }


    


}

void recredenciamento::recredencia(vector<docentes>& vetorDocentes, int ano,
        vector<regrasDePontuacao>& vetorRegras, vector<veiculos>& vetorVeiculos,
        vector<publicacoes>& vetorPublicacoes, vector<qualificacoes>& vetorQualis) {
    
    vector<recredenciamento> vetorRecredencia;
    calculaPontuacao(vetorDocentes, ano, vetorRegras, vetorPublicacoes);
    
    for (int i = 0; i < vetorDocentes.size(); i++) {
        for (int j = 0; j < vetorRegras.size(); j++) {
            time_t dataInicio = vetorRegras[j].getDataInicio();
            string aux = formatDate(dataInicio, "%d/%m/%Y");
            Tokenizer token(aux,'/');
            vector<string> s = token.remaining();
            
            int anoDaRegra = atoi(s[2].c_str());
            if (ano == anoDaRegra) {
                
                
                //coordenadores, docentes com menos de 3 anos de entrada e docentes com mais de 60 anos sao recredenciados automaticamente
                //caso contrario, verifica se a pontuação obtida é suficiente para recredenciar o docente
                if (vetorDocentes[i].getEhCoordenador() == true) {
                    vetorDocentes[i].setRecredenciado(0);
                } else if (vetorDocentes[i].entrouMenosDe3Anos(vetorRegras[j]) == true) {
                    vetorDocentes[i].setRecredenciado(1);
                } else if (vetorDocentes[i].temMaisDe60Anos(vetorRegras[j]) == true) {
                    vetorDocentes[i].setRecredenciado(2);
                } else if (vetorDocentes[i].getPontuacao() >= vetorRegras[j].getPontuacaoMinimaRecredenciamento()) {
                    vetorDocentes[i].setRecredenciado(3);
                } else {
                    vetorDocentes[i].setRecredenciado(4);
                }
            
           
                
              }
        }
    }

    //ordena a vetor de recredenciamento
    docentes d;
    stable_sort(vetorDocentes.begin(), vetorDocentes.end(), d.comparador);
    criaArquivoRecredenciamento(vetorDocentes);
}

void recredenciamento::criaArquivoRecredenciamento(vector<docentes>& vetorDocentes) {

    ofstream file("1-recredenciamento.csv");
    file << "Docente;Pontuação;Recredenciado?\n";
    
    for (int i = 0; i < vetorDocentes.size(); i++) {
        locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
        string formatado = formatDouble(vetorDocentes[i].getPontuacao(), LOCALE_PT_BR);
        char buff[100];
        snprintf(buff, sizeof(buff), "%.1f", vetorDocentes[i].getPontuacao());
        
        string aux(buff);
        
        double d = parseDouble(aux,LOCALE_PT_BR);
        
        d/=10;
        
        string s = formatDouble(d,LOCALE_PT_BR);
        s.resize(s.size()-5);
        
        file << vetorDocentes[i].getNome() << ";"
                << s << ";";

        switch (vetorDocentes[i].getRecredenciado()) {
            case 0:
                file << "Coordenador\n";
                break;
            case 1:
                file << "PPJ\n";
                break;
            case 2:
                file << "PPS\n";
                break;
            case 3:
                file << "Sim\n";
                break;
            case 4:
                file << "Não\n";
                break;
            default:
                file << "Default\n";
                break;
        }

    }


}


//retorna 
regrasDePontuacao recredenciamento::retornaRegraRecredenciamento(vector<regrasDePontuacao> vetorRegras, int ano) {


    for (int i = 0; i < vetorRegras.size(); i++) {
        string tempo = formatDate(vetorRegras[i].getDataFim(), "%d/%m/%Y");
        vector<string> tempoSeparado;
        Tokenizer token(tempo, '/');
        tempoSeparado = token.remaining();
        int anoString = atoi(tempoSeparado[2].c_str());

        if (anoString == ano) {
            return vetorRegras[i];
        }
    }
}

