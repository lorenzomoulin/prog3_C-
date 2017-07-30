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

map<int, veiculos> planilhaVeiculos::getListaVeiculos() {
    return mapaVeiculos;
}

void planilhaVeiculos::setListaVeiculos(map<int, veiculos> mapaVeiculos) {
    this->mapaVeiculos = mapaVeiculos;
}

map<int, veiculos> planilhaVeiculos::ler(int argc, char ** argv, map<int,qualificacoes> mapaQualis, map<int,publicacoes> mapaPublicacoes) {
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
                    
                    continue;
                }
                veiculos veiculo;

                //Lê a linha inteira e divide em um mapa de 5 posicoes
                getline(file, linha);
                

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
                string issn;
                if (linhaDividida.size()==5)
                    issn = trim(linhaDividida[4]);
                else 
                    issn = ""; 
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
                mapaVeiculos[j] = veiculo;
                j++;
                
            }
            file.close();
        }
    }

    siglaVeiculoRepetida(mapaVeiculos);
    siglaNaoDefinidaNaQualis(mapaQualis, mapaVeiculos);
    siglaNaoDefinidaNaPubli(mapaPublicacoes, mapaVeiculos);

    return mapaVeiculos;
}

void planilhaVeiculos::siglaVeiculoRepetida(map<int, veiculos> mapaVeiculos) {
    
}

void planilhaVeiculos::siglaNaoDefinidaNaQualis(map<int, qualificacoes> mapaQualis,
        map<int, veiculos> mapaVeiculos) {
}

void planilhaVeiculos::siglaNaoDefinidaNaPubli(map<int, publicacoes> vectorPublicacoes,
        map<int, veiculos> mapaVeiculos) {

}