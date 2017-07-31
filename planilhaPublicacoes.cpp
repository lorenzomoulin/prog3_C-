/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaPublicacoes.cpp
 * Author: lorenzo
 * 
 * Created on 28 de Julho de 2017, 13:33
 */

#include "planilhaPublicacoes.h"
#include <fstream>
#include <sstream>
#include "Tokenizer.h"
#include "StringUtils.h"
#include <string>
#include "publicacoes.h"
#include "periodicos.h"
#include "conferencias.h"
#include "veiculos.h"
#include "geraPublicacoes.h"

using namespace cpp_util;
using namespace trabalho;
using namespace std;


planilhaPublicacoes::planilhaPublicacoes() {
    
}

vector<publicacoes> planilhaPublicacoes::getListaPublicacoes(){
    return vetorPublicacoes;
}

void planilhaPublicacoes::setListaPublicacoes(vector<publicacoes> vetorPublicacoes){
    this->vetorPublicacoes = vetorPublicacoes;
}

vector<publicacoes> planilhaPublicacoes::ler(int argc, char** argv, vector<docentes> vetorDocentes, vector<veiculos> vetorVeiculos){
    int tiraTitulo = 0;
    vector<string> args(argv, argv + argc );
    
    //converte char** para string
    
    for (int i = 0; i < argc; i++) {
        if (args[i].compare("-p") == 0) {
            ifstream file (args[i + 1].c_str());
            if (file.is_open()){
                
                string linha;
                
                while (! file.eof()) {
                    if (tiraTitulo == 0) {
                        getline(file, linha);
                        
                        tiraTitulo++;
                        
                        continue;
                    }
                    publicacoes publicacao;

                    getline(file, linha);
                    
                    vector<string> linhaDividida;
                    istringstream f(linha);
                    string temp;
                    
                    
                    //Lê a linha inteira e divide em um vetor de 9 posicoes
                    while(getline(f,temp,';')) 
                        linhaDividida.push_back(temp);
                    
                    if (linhaDividida.size()==0)
                        break;
                    
                    //Atribui as strings separadas para cada variavel
                    string ano = trim(linhaDividida[0]);
                    string siglaVeiculo = trim(linhaDividida[1]);
                    string titulo = trim(linhaDividida[2]);
                    string autores = trim(linhaDividida[3]);
                    string numero = trim(linhaDividida[4]);
                    string volumePeriodico = trim(linhaDividida[5]);
                    string localConferencia = trim(linhaDividida[6]);
                    string paginaInicial = trim(linhaDividida[7]);
                    string paginaFinal = trim(linhaDividida[8]);

                    //Converte as variaveis para os tipos necessarios
                    
                    int ano2 = atoi(ano.c_str());
                    int volumePeriodico2 = 0;
                    if (volumePeriodico.compare("")) 
                        volumePeriodico2 = atoi(volumePeriodico.c_str());
                    
                    int numero2 = atoi(numero.c_str());
                    int paginaInicial2 = atoi(paginaInicial.c_str());
                    int paginaFinal2 = atoi(paginaFinal.c_str());

                    //Separa a lista de autores
                    vector<string> vetorAutores;
                    
                    istringstream g(autores);
                    
                    while(getline(g,temp,',')) 
                        vetorAutores.push_back(temp);
                    
                    //Convertendo o vetor de string para long
                    
                    vector <long> vetorAutores2;
                    
                    for (int j = 0; j < vetorAutores.size(); j++) {
                        if (vetorAutores[j].compare(""))
                            vetorAutores2.push_back(atol(vetorAutores[j].c_str()));
                    }
                    
                    veiculos veiculo;
                    for (int c = 0; c < vetorVeiculos.size() ; c++){
                        if (!vetorVeiculos[c].getSigla().compare(siglaVeiculo)){
                            veiculo = vetorVeiculos[c];
                        }
                    }
                    vector<docentes> docente;
                    for (int c = 0; c < vetorAutores2.size() ; c++){
                        for(int java = 0; java < vetorDocentes.size() ; java++){
                            if ( vetorDocentes[java].getCodigo() == vetorAutores2[c]){
                                docente.push_back(vetorDocentes[java]);
                            } 
                        }
                    }
                    
                    geraPublicacoes gera;
                    
                    //coloca na primeira posicao da lista de qualis, o qualis mais atual
                    vector<qualificacoes> vetorQualisSize1;
                    vetorQualisSize1.push_back(gera.qualisAtual(veiculo.getQualis(),ano2));
                    veiculo.setQualis(vetorQualisSize1);                   
                    
                    //Insere infos na publicacao
                    
                    if (volumePeriodico.compare("")) {
                        periodicos periodico;                       
                        
                        periodico.setAno(ano2);
                        periodico.setAutores(docente);
                        periodico.setNumero(numero2);
                        periodico.setPaginaFinal(paginaFinal2);
                        periodico.setPaginaInicial(paginaInicial2);
                        periodico.setTitulo(titulo);
                        periodico.setVeiculo(veiculo);
                        periodico.setVolume(volumePeriodico2);
                        
                        vetorPublicacoes.push_back(periodico);
                    
                    }//Insere infos na conferencia
                    else if (localConferencia.compare("")) {
                        conferencias conferencia;
                        
                        conferencia.setAno(ano2);
                        conferencia.setAutores(docente);
                        conferencia.setNumero(numero2);
                        conferencia.setPaginaFinal(paginaFinal2);
                        conferencia.setPaginaInicial(paginaInicial2);
                        conferencia.setTitulo(titulo);
                        conferencia.setVeiculo(veiculo);
                        conferencia.setLocal(localConferencia);
                        
                        vetorPublicacoes.push_back(conferencia);

                    }
                    
                   

                    
                }
            }
            file.close();
        }
        codigoDocenteNaoEspecificado(vetorPublicacoes, vetorDocentes);
    }
    

    //codigoRepetidoParaDocente(vetorDocentes);
    return vetorPublicacoes;
}

void planilhaPublicacoes::codigoDocenteNaoEspecificado(vector<publicacoes> vetorPublicacoes, vector<docentes> listaDocentes){
    
}