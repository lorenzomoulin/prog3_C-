/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 12:01
 */

#include <cstdlib>
#include "planilhaDocentes.h"
#include "docentes.h"
#include <vector>
#include <valarray>
#include "planilhaPublicacoes.h"
#include "planilhaQualificacoes.h"
#include "planilhaRegrasDePontuacao.h"
#include "planilhaVeiculos.h"
#include "estatisticasPublicacoes.h"
#include "regrasDePontuacao.h"
#include "geraPublicacoes.h"
#include "recredenciamento.h"
#include "trabalhoException.h"


using namespace std;
using namespace trabalho;

/*
 * 
 */
int main(int argc, char** argv) {

    try {
        
        if (argc == 13) {
            //le a planilha de qualis
            planilhaQualificacoes pq;
            vector<qualificacoes> vetorQualificacoes = pq.ler(argc, argv);

            //le a planiçha de docentes
            planilhaDocentes pd;
            vector<docentes> vetorDocentes = pd.ler(argv, argc);

            //le a planilha de veiculos
            planilhaVeiculos pv;
            vector<veiculos> vetorVeiculos = pv.ler(argc, argv, vetorQualificacoes);

            //le a planilha de publicacoes
            planilhaPublicacoes pp;
            vector<publicacoes> vetorPublicacoes = pp.ler(argc, argv, vetorDocentes, vetorVeiculos);

            //le a planilha de regras
            planilhaRegrasDePontuacao pr;
            vector<regrasDePontuacao> vetorRegras = pr.ler(argc, argv);

            //converte argv para vetor de string
            vector<string> args(argv, argv + argc);

            // PROCURA ANO DE RECREDENCIAMENTO
            int ano = 0;
            for (int i = 0; i < argc; i++)
                if (args[i].compare("-a") == 0)
                    ano = atoi(args[i + 1].c_str());

            // PARA ATRIBUIR QUALIS A SEUS RESPECTIVOS PONTOS DADO UM ANO
            regrasDePontuacao::expandeQualis(vetorRegras, ano);

            // PARA O RELATORIO DE ESTATISTICAS
            estatisticasPublicacoes::contaNumeroArtigosPorDocentes(vetorPublicacoes);
            estatisticasPublicacoes::criaArquivoEstatisticas();

            // PARA O RELATORIO DE PUBLICACOES
            geraPublicacoes::publicacoesParaRelatorio(vetorPublicacoes);

            // PARA O RELATORIO DE RECREDENCIAMENTO, DADO UM ANO
            recredenciamento::recredencia(vetorDocentes, ano, vetorRegras, vetorVeiculos, vetorPublicacoes, vetorQualificacoes); //Não é necessario criar ou ler .dat.
        } else {
            throw trabalhoException("Erro de I/O");
        }
    } catch (trabalhoException e) {
        cout << e.what() << endl;
    }


    return 0;
}