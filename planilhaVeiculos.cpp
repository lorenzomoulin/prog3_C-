/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaVeiculos.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 22:03
 */

#include "planilhaVeiculos.h"
#include "StringUtils.h"
#include "NumberUtils.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace cpp_util;
using namespace std;
using namespace trabalho;

planilhaVeiculos::planilhaVeiculos() {
}

vector<veiculos> planilhaVeiculos::getListaVeiculos() {
    return vetorVeiculos;
}

void planilhaVeiculos::setListaVeiculos(vector<veiculos> vetorVeiculos) {
    this->vetorVeiculos = vetorVeiculos;
}

vector<veiculos> planilhaVeiculos::ler(int argc, char ** argv, vector<qualificacoes> vetorQualis, vector<publicacoes> vetorPublicacoes) {
    int tiraTitulo = 0;
    vector<string> args(argv, argv + argc);
    for (int i = 0; i < args.size(); i++) {
        if (args[i].compare("-v") == 0) {
            ifstream file(args[i + 1].c_str());

            string linha;
            int j = 0;
            while (!file.eof()) {
                if (tiraTitulo == 0) {
                    getline(file, linha);

                    tiraTitulo++;
                    j++;
                    continue;
                }
                veiculos veiculo;

                //Lê a linha inteira e divide em um vetor de 5 posicoes
                getline(file, linha);
                cout << linha << endl;

                vector<string> linhaDividida;
                istringstream f(linha);
                string temp;

                while (getline(f, temp, ';'))
                    linhaDividida.push_back(temp);

                
                if(linhaDividida.size()==0)
                    break;
                // Atribui as strings separadas para cada variavel
                string sigla = trim(linhaDividida[0]);
                string nome = trim(linhaDividida[1]);
                string tipo = trim(linhaDividida[2]);
                string fatorImpacto = trim(linhaDividida[3]);
                string issn = trim(linhaDividida[4]);

                // Converte as variaveis para os tipos necessarios
                locale LOCALE_PT_BR(locale(), new NumPunctPTBR());
                double fatorImpacto2 = parseDouble(fatorImpacto,LOCALE_PT_BR);
                const char * tipo2 = tipo.c_str();

                /*if (tipo2 != 'P' && tipo2 != 'C') {
                    throw new tipoDeVeiculoDesconhecidoParaVeiculo(sigla, tipo2);
                }*/

                // Insere infos no veiculo
                veiculo.setFatorImpacto(fatorImpacto2);
                veiculo.setNome(nome);
                veiculo.setSigla(sigla);
                veiculo.setTipo(tipo2);
                veiculo.setIssn(issn);

                // Insere o veiculo na lista de veiculos
                vetorVeiculos.push_back(veiculo);

            }

        }
    }

    siglaVeiculoRepetida(vetorVeiculos);
    siglaNaoDefinidaNaQualis(vetorQualis, vetorVeiculos);
    siglaNaoDefinidaNaPubli(vetorPublicacoes, vetorVeiculos);

    return vetorVeiculos;
}

void planilhaVeiculos::siglaVeiculoRepetida(vector<veiculos> vetorVeiculos) {
}

void planilhaVeiculos::siglaNaoDefinidaNaQualis(vector<qualificacoes> vectorQualis,
        vector<veiculos> vectorVeiculos) {
}

void planilhaVeiculos::siglaNaoDefinidaNaPubli(vector<publicacoes> vectorPublicacoes,
        vector<veiculos> vectorVeiculos) {

}