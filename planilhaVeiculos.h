/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaVeiculos.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 22:03
 */

#ifndef PLANILHAVEICULOS_H
#define PLANILHAVEICULOS_H
#include <vector>
#include "veiculos.h"
#include "publicacoes.h"
#include "qualificacoes.h"


namespace trabalho{
class planilhaVeiculos {
    vector<veiculos> vetorVeiculos;
public:
    planilhaVeiculos();
    vector<veiculos> getListaVeiculos();
    void setListaVeiculos(vector<veiculos> vetorVeiculos);
    vector<veiculos> ler(int argc,char ** argv, vector<qualificacoes>);
    void siglaVeiculoRepetida(vector<veiculos> vetorVeiculos);
    void siglaNaoDefinidaNaQualis(vector<qualificacoes> vectorQualis,
            vector<veiculos> vectorVeiculos);
    void siglaNaoDefinidaNaPubli(vector<publicacoes> vectorPublicacoes,
            vector<veiculos> vectorVeiculos);
    
private:

};
}

#endif /* PLANILHAVEICULOS_H */

