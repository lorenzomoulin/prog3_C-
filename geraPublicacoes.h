/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   geraPublicacoes.h
 * Author: lorenzo
 *
 * Created on 29 de Julho de 2017, 19:16
 */

#ifndef GERAPUBLICACOES_H
#define GERAPUBLICACOES_H
#include "qualificacoes.h"
#include "docentes.h"
#include "publicacoes.h"
#include "veiculos.h"



namespace trabalho{
class geraPublicacoes {
    
    string siglaVeiculo;
    string nomeVeiculo;
    string qualisVeiculo;
    double fatorImpactoVeiculo;
    string tituloPublicacao;
    int anoPublicacao;
    vector<string> vetorDocentes;
    
public:
    geraPublicacoes();
    
    int getAnoPublicacao();
    
    void setAnoPublicacao(int anoPublicacao);
    
    string getSiglaVeiculo();
    
    void setSiglaVeiculo(string siglaVeiculo);
    
    string getNomeVeiculo();
    
    void setNomeVeiculo(string nomeVeiculo);

    string getQualisVeiculo();

    void setQualisVeiculo(string qualisVeiculo);

    double getFatorImpactoVeiculo();

    void setFatorImpactoVeiculo(double fatorImpactoVeiculo); 

    string getTituloPublicacao();
    
    void setTituloPublicacao(string tituloPublicacao);

    vector<string> getListaDocentes(); 

    void setListaDocentes(vector<string> listaDocentes);
    
    static void criaArquivoEstatisticas(vector<geraPublicacoes> vetorGera);
    
private:

};
}

#endif /* GERAPUBLICACOES_H */

