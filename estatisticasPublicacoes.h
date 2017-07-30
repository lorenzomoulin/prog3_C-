/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   estatisticasPublicacoes.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 23:41
 */

#ifndef ESTATISTICASPUBLICACOES_H
#define ESTATISTICASPUBLICACOES_H
#include <string>
#include <vector>
#include "publicacoes.h"
#include "qualificacoes.h"


using namespace std;

namespace trabalho{
class estatisticasPublicacoes {
    static vector<string> qualis;
    static vector<int> numeroArtigos;
    static vector<double> numeroArtigosPorDocente;
public:
    
    estatisticasPublicacoes();
    static void contaNumeroArtigosPorQualis(map<int,publicacoes>,
            map<int, qualificacoes>);
    static void contaNumeroArtigosPorDocentes(map<int,publicacoes>, map<int, qualificacoes>);
    static void criaArquivoEstatisticas();
private:

};
}
#endif /* ESTATISTICASPUBLICACOES_H */

