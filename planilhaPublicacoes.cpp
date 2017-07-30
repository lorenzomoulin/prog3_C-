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

vector<publicacoes> planilhaPublicacoes::ler(int argc, char** argv, vector<docentes> vetorDocentes){
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
                        cout << linha << endl;
                        tiraTitulo++;
                        
                        continue;
                    }
                    publicacoes publicacao;

                    getline(file, linha);
                    cout << linha << endl;
                    
                    vector<string> linhaDividida;
                    istringstream f(linha);
                    string temp;
                    
                    
                    //Lê a linha inteira e divide em um vetor de 9 posicoes
                    while(getline(f,temp,';')) 
                        linhaDividida.push_back(temp);
                    
                    /*cout << linhaDividida[0] << endl;
                    cout << linhaDividida[1] << endl;
                    cout << linhaDividida[2] << endl;
                    cout << linhaDividida[3] << endl;
                    //cout << linhaDividida[4] << endl;*/
                    //cout << linhaDividida.size() <<"<<<<<<<<<"<< endl;
                    
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


                    //Insere infos na publicacao
                    
                    if (volumePeriodico.compare("")) {
                        periodicos periodico;
                        periodico.setAno(ano2);
                        periodico.setAutores(vetorAutores2);
                        periodico.setNumero(numero2);
                        periodico.setPaginaFinal(paginaFinal2);
                        periodico.setPaginaInicial(paginaInicial2);
                        periodico.setSiglaVeiculo(siglaVeiculo);
                        periodico.setTitulo(titulo);
                        periodico.setVolume(volumePeriodico2);
                        cout << periodico.getVolume() << endl;
                        vetorPublicacoes.push_back(periodico);
                    
                    }//Insere infos na conferencia
                    else if (localConferencia.compare("")) {
                        conferencias conferencia;
                        conferencia.setAno(ano2);
                        conferencia.setAutores(vetorAutores2);
                        conferencia.setNumero(numero2);
                        conferencia.setPaginaFinal(paginaFinal2);
                        conferencia.setPaginaInicial(paginaInicial2);
                        conferencia.setSiglaVeiculo(siglaVeiculo);
                        conferencia.setTitulo(titulo);
                        conferencia.setLocal(localConferencia);
                        cout << conferencia.getLocal() << endl;
                        vetorPublicacoes.push_back(conferencia);

                    }

                    
                    

                }
            }
            file.close();
        }
        codigoDocenteNaoEspecificado(vetorPublicacoes, vetorDocentes);
    }
    /*for (int c = 0 ; c < vetorPublicacoes.size() ; c++){
        
        cout <<  vetorPublicacoes[c].getAno() << ";";
        cout <<  vetorPublicacoes[c].getSiglaVeiculo() << ";";
        
        cout << vetorPublicacoes[c].getTitulo() << ";" ;
        
        for (int d = 0 ; d < vetorPublicacoes[c].getAutores().size() ;  d++)
            cout <<  vetorPublicacoes[c].getAutores()[d] << "," ;
            
        cout <<  vetorPublicacoes[c].getNumero() << ";";
        
        cout <<  vetorPublicacoes[c].getPaginaInicial() << ";";
        cout <<  vetorPublicacoes[c].getPaginaFinal() << endl;
        
        
    }*/

    //codigoRepetidoParaDocente(vetorDocentes);
    return vetorPublicacoes;
}

void planilhaPublicacoes::codigoDocenteNaoEspecificado(vector<publicacoes> vetorPublicacoes, vector<docentes> listaDocentes){
    
}