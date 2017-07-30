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

estatisticasPublicacoes::estatisticasPublicacoes() {
    
    estatisticasPublicacoes::qualis.push_back("A1");
    estatisticasPublicacoes::qualis.push_back("A2");
    estatisticasPublicacoes::qualis.push_back("B1");
    estatisticasPublicacoes::qualis.push_back("B2");
    estatisticasPublicacoes::qualis.push_back("B3");
    estatisticasPublicacoes::qualis.push_back("B4");
    estatisticasPublicacoes::qualis.push_back("B5");
    estatisticasPublicacoes::qualis.push_back("C");
    
    estatisticasPublicacoes::numeroArtigos.reserve(8);
    
    
    
    
    estatisticasPublicacoes::numeroArtigosPorDocente.reserve(8);
    

}

void estatisticasPublicacoes::contaNumeroArtigosPorQualis(map<int,publicacoes> mapaPublicacoes,
        map<int,qualificacoes> mapaQualificacoes) {
        
    for (int i = 0; i < mapaPublicacoes.size(); i++) {
    OUTER:
        for (int j = 0; j < mapaQualificacoes.size(); j++) {
            if (stringCompare(mapaPublicacoes[i].getSiglaVeiculo(),mapaQualificacoes[j].getSiglaVeiculo()) == 0) {
                if (mapaQualificacoes[j].getQualis().compare("A1") == 0) {
                    estatisticasPublicacoes::numeroArtigos[0]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("A2") == 0) {
                    estatisticasPublicacoes::numeroArtigos[1]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B1") == 0) {
                    estatisticasPublicacoes::numeroArtigos[2]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B2") == 0) {
                    estatisticasPublicacoes::numeroArtigos[3]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B3") == 0) {
                    estatisticasPublicacoes::numeroArtigos[4]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B4") == 0) {
                    estatisticasPublicacoes::numeroArtigos[5]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B5") == 0) {
                    estatisticasPublicacoes::numeroArtigos[6]++;
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("C") == 0) {
                    estatisticasPublicacoes::numeroArtigos[7]++;
                    goto OUTER;
                } else
                    break;
            
            }
        }
    }
    for (int i =0;i<8;i++)
        cout << estatisticasPublicacoes::numeroArtigos[i] << endl;
}

void estatisticasPublicacoes::contaNumeroArtigosPorDocentes(map<int, publicacoes> mapaPublicacoes,
        map<int, qualificacoes> mapaQualificacoes) {
    
    for (int i = 0; i < mapaPublicacoes.size(); i++) {
        OUTER:
        for (int j = 0; j < mapaQualificacoes.size(); j++) {
            if (stringCompare(mapaPublicacoes[i].getSiglaVeiculo(),mapaQualificacoes[j].getSiglaVeiculo()) == 0) {
                if (mapaQualificacoes[j].getQualis().compare("A1") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[0] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("A2") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[1] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B1") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[2] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B2") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[3] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B3") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[4] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B4") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[5] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("B5") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[6] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                }
                if (mapaQualificacoes[j].getQualis().compare("C") == 0) {
                    estatisticasPublicacoes::numeroArtigosPorDocente[7] += 1.0 / mapaPublicacoes[i].getAutores().size();
                    goto OUTER;
                } else
                    break;
            
            }
        }
    }
    for (int i = 0; i< 8 ; i++)
        cout << estatisticasPublicacoes::numeroArtigosPorDocente[i] << endl;
}

void estatisticasPublicacoes::criaArquivoEstatisticas() {

    ofstream file;
    file.open("3-estatisticas.csv");
    file << "Qualis;Qtd. Artigos;Média Artigos / Docente\n";
    locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
    for (int i = 0; i < estatisticasPublicacoes::qualis.size(); i++) {
        //string formatado = string.format("%.2f", numeroArtigosPorDocente[i]);
        //cout << estatisticasPublicacoes::qualis[i] << ";" << estatisticasPublicacoes::numeroArtigos[i] << ";" << estatisticasPublicacoes::numeroArtigosPorDocente[i] << "\n";
        file << estatisticasPublicacoes::qualis[i] << ";" << numeroArtigos[i] << ";" << formatDouble(numeroArtigosPorDocente[i], LOCALE_PT_BR) << "\n";
    }



}

