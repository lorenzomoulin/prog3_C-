/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   veiculos.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 13:09
 */

#include "veiculos.h"

using namespace trabalho;

veiculos::veiculos() {
}

vector<qualificacoes> veiculos::getQualis(){
    return qualis;
}
    
void veiculos::setQualis(vector<qualificacoes> qualis){
    this->qualis = qualis;
}

double veiculos::getFatorImpacto(){
    return fatorImpacto;
}

string veiculos::getIssn(){
    return issn;
}

string veiculos::getNome(){
    return nome;
}

string veiculos::getSigla(){
    return sigla;
}

string veiculos::getTipo(){
    return tipo;
}

void veiculos::setFatorImpacto(double fatorImpacto){
    this->fatorImpacto = fatorImpacto;
}

void veiculos::setIssn(string issn){
    this->issn = issn;
}

void veiculos::setNome(string nome){
    this->nome = nome;
}

void veiculos::setSigla(string sigla){
    this->sigla = sigla;
}

void veiculos::setTipo(string tipo){
    this->tipo = tipo;
}

