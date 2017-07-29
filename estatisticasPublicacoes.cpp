/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estatisticasPublicacoes.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 23:41
 */

#include "estatisticasPublicacoes.h"

using namespace trabalho;
estatisticasPublicacoes::estatisticasPublicacoes() {
    qualis.push_back("A1");
    qualis.push_back("A2");
    qualis.push_back("B1");
    qualis.push_back("B2");
    qualis.push_back("B3");
    qualis.push_back("B4");
    qualis.push_back("B5");
    qualis.push_back("C");
    
    
}


void contaNumeroArtigosPorQualis(vector<publicacoes> vetorPublicacoes,
            vector<qualificacoes> vetorQualificacoes){
    
    for (int i = 0; i < vetorPublicacoes.size(); i++) {
            OUTER:
            for (int j = 0; j < vetorQualificacoes.size(); j++) {
                if (vetorPublicacoes.get(i).getSiglaVeiculo().equals(vetorQualificacoes.get(j).getSiglaVeiculo())) {
                    switch (vetorQualificacoes.get(j).getQualis()) {
                        case "A1":
                            numeroArtigos[0]++;
                            break OUTER;
                        case "A2":
                            numeroArtigos[1]++;
                            break OUTER;
                        case "B1":
                            numeroArtigos[2]++;
                            break OUTER;
                        case "B2":
                            numeroArtigos[3]++;
                            break OUTER;
                        case "B3":
                            numeroArtigos[4]++;
                            break OUTER;
                        case "B4":
                            numeroArtigos[5]++;
                            break OUTER;
                        case "B5":
                            numeroArtigos[6]++;
                            break OUTER;
                        case "C":
                            numeroArtigos[7]++;
                            break OUTER;
                        default:
                            break;
                    }
                }
            }
        }
}

void contaNumeroArtigosPorDocentes(vector<publicacoes> vetorPublicacoes,
        vector<qualificacoes> vetorQualificacoes){
    
}
void criaArquivoEstatisticas(){

}

