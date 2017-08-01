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
#include <fstream>
#include <sstream>
#include "StringUtils.h"
#include "NumberUtils.h"
#include <iostream>
using namespace std;
using namespace cpp_util;
using namespace trabalho;

vector<int> estatisticasPublicacoes::numeroArtigos;
vector<string> estatisticasPublicacoes::qualis;
vector <double>estatisticasPublicacoes::numeroArtigosPorDocente;

estatisticasPublicacoes::estatisticasPublicacoes() {}

void estatisticasPublicacoes::contaNumeroArtigosPorDocentes(vector<publicacoes> vetorPublicacoes) {

    estatisticasPublicacoes::qualis.push_back("A1");
    estatisticasPublicacoes::qualis.push_back("A2");
    estatisticasPublicacoes::qualis.push_back("B1");
    estatisticasPublicacoes::qualis.push_back("B2");
    estatisticasPublicacoes::qualis.push_back("B3");
    estatisticasPublicacoes::qualis.push_back("B4");
    estatisticasPublicacoes::qualis.push_back("B5");
    estatisticasPublicacoes::qualis.push_back("C");

    estatisticasPublicacoes::numeroArtigos.reserve(8);
    estatisticasPublicacoes::numeroArtigos[0] = 0;
    estatisticasPublicacoes::numeroArtigos[1] = 0;
    estatisticasPublicacoes::numeroArtigos[2] = 0;
    estatisticasPublicacoes::numeroArtigos[3] = 0;
    estatisticasPublicacoes::numeroArtigos[4] = 0;
    estatisticasPublicacoes::numeroArtigos[5] = 0;
    estatisticasPublicacoes::numeroArtigos[6] = 0;
    estatisticasPublicacoes::numeroArtigos[7] = 0;

    estatisticasPublicacoes::numeroArtigosPorDocente.reserve(8);
    estatisticasPublicacoes::numeroArtigosPorDocente[0] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[1] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[2] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[3] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[4] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[5] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[6] = 0;
    estatisticasPublicacoes::numeroArtigosPorDocente[7] = 0;

    for (int c = 0; c < vetorPublicacoes.size(); c++) {
        for (int d = 0; d < vetorPublicacoes[c].getVeiculo().getQualis().size(); d++){
            if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("A1")) {
                estatisticasPublicacoes::numeroArtigos[0]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[0] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("A2")) {
                estatisticasPublicacoes::numeroArtigos[1]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[1] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("B1")) {
                estatisticasPublicacoes::numeroArtigos[2]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[2] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("B2")) {
                estatisticasPublicacoes::numeroArtigos[3]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[3] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("B3")) {
                estatisticasPublicacoes::numeroArtigos[4]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[4] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("B4")) {
                estatisticasPublicacoes::numeroArtigos[5]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[5] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("B5")) {
                estatisticasPublicacoes::numeroArtigos[6]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[6] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            } else if (!vetorPublicacoes[c].getVeiculo().getQualis()[d].getQualis().compare("C")) {
                estatisticasPublicacoes::numeroArtigos[7]++;
                estatisticasPublicacoes::numeroArtigosPorDocente[7] += 1.0 / (vetorPublicacoes[c].getAutores().size());

            }
        }
    }
    for (int a = 0; a < 8; a++) {
        cout << estatisticasPublicacoes::numeroArtigosPorDocente[a] << endl;
    }
    
}

void estatisticasPublicacoes::criaArquivoEstatisticas() {

    ofstream file;
    file.open("3-estatisticas.csv");
    file << "Qualis;Qtd. Artigos;Média Artigos / Docente\n";
    locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
    char buff[100];
    
   
    for (int i = 0; i < estatisticasPublicacoes::qualis.size(); i++) {
        
        
        snprintf(buff, sizeof(buff), "%.2f", numeroArtigosPorDocente[i]);
        
        string aux(buff);
        
        double d = parseDouble(aux,LOCALE_PT_BR);
        d/=100;
       
        string s = formatDoubleCurrency(d,LOCALE_PT_BR);
        
        file << estatisticasPublicacoes::qualis[i] << ";" << numeroArtigos[i] << ";" <<  s  << "\n";
    }



}

