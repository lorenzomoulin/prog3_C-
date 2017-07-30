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
#include <map>


namespace trabalho{
class planilhaVeiculos {
    map<int, veiculos> mapaVeiculos;
public:
    planilhaVeiculos();
    map<int, veiculos> getListaVeiculos();
    void setListaVeiculos(map<int, veiculos> mapaVeiculos);
    map<int, veiculos> ler(int argc,char ** argv, map<int,qualificacoes> , map<int,publicacoes> );
    void siglaVeiculoRepetida(map<int, veiculos> mapaVeiculos);
    void siglaNaoDefinidaNaQualis(map<int,qualificacoes>, map<int, veiculos>);
    void siglaNaoDefinidaNaPubli(map<int,publicacoes>, map<int, veiculos>);
    
private:

};
}

#endif /* PLANILHAVEICULOS_H */

