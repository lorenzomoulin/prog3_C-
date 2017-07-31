/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaQualificacoes.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 15:58
 */

#ifndef PLANILHAQUALIFICACOES_H
#define PLANILHAQUALIFICACOES_H

#include "qualificacoes.h"
#include "veiculos.h"



namespace trabalho{
class planilhaQualificacoes {
    vector<qualificacoes> vetorQualificacoes; 
public:
    planilhaQualificacoes();
    vector<qualificacoes> getListaQualificacoes();
    void setListaQualificacoes(vector<qualificacoes> vetorQualificacoes);
    vector<qualificacoes> ler(int argc, char** argv);
        
private:

};
}
#endif /* PLANILHAQUALIFICACOES_H */

