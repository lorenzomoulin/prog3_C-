/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   qualificacoes.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 12:49
 */

#include "qualificacoes.h"

using namespace trabalho;

qualificacoes::qualificacoes(){
    
}

int qualificacoes::getAno(){
    return ano;
}

string qualificacoes::getQualis(){
    return qualis;
}

string qualificacoes::getSiglaVeiculo(){
    return siglaVeiculo;
}

void qualificacoes::setAno(int ano){
    this->ano = ano;
}

void qualificacoes::setQualis(string qualis){
    this->qualis = qualis;
}

void qualificacoes::setSiglaVeiculo(string siglaVeiculo){
    this->siglaVeiculo = siglaVeiculo;
}