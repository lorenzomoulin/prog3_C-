/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   geraPublicacoes.cpp
 * Author: lorenzo
 * 
 * Created on 29 de Julho de 2017, 19:16
 */

#include "geraPublicacoes.h"


using namespace trabalho;

geraPublicacoes::geraPublicacoes() {
}

int geraPublicacoes::getAnoPublicacao(){
    return anoPublicacao;
}

void geraPublicacoes::setAnoPublicacao(int anoPublicacao){
    this->anoPublicacao = anoPublicacao;
}

double geraPublicacoes::getFatorImpactoVeiculo(){
    return fatorImpactoVeiculo;
}

void geraPublicacoes::setFatorImpactoVeiculo(double fatorImpactoVeiculo){
    this->fatorImpactoVeiculo = fatorImpactoVeiculo;
}

vector<string> geraPublicacoes::getListaDocentes(){
    return vetorDocentes;
}

void geraPublicacoes::setListaDocentes(vector<string> listaDocentes){
    this->vetorDocentes = vetorDocentes;
}

string geraPublicacoes::getNomeVeiculo(){
    return nomeVeiculo;
}

void geraPublicacoes::setNomeVeiculo(string nomeVeiculo){
    this->nomeVeiculo = nomeVeiculo;
}

string geraPublicacoes::getQualisVeiculo(){
    return qualisVeiculo;
}

void geraPublicacoes::setQualisVeiculo(string qualisVeiculo){
    this->qualisVeiculo = qualisVeiculo;
}

string geraPublicacoes::getSiglaVeiculo(){
    return siglaVeiculo;
}

void geraPublicacoes::setSiglaVeiculo(string siglaVeiculo){
    this->siglaVeiculo = siglaVeiculo;
}

string geraPublicacoes::getTituloPublicacao(){
    return tituloPublicacao;
}

void geraPublicacoes::setTituloPublicacao(string tituloPublicacao){
    this->tituloPublicacao = tituloPublicacao;
}

void criaArquivoPublicacoes(vector<geraPublicacoes> vetorGera){
    
}
