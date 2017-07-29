/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   qualificacoes.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 12:49
 */

#ifndef QUALIFICACOES_H
#define QUALIFICACOES_H

#include <string>
#include <vector>

using namespace std;

namespace trabalho{
class qualificacoes {
    int ano;
    string siglaVeiculo;
    string qualis;
    vector<qualificacoes> listaQualificacoes;
public:
    qualificacoes();
    void setAno(int ano);

    void setSiglaVeiculo(string siglaVeiculo);

    void setQualis(string qualis);

    int getAno();

    string getSiglaVeiculo();

    string getQualis();
    
private:

};
}

#endif /* QUALIFICACOES_H */

