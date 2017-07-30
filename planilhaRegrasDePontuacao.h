/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaRegrasDePontuacao.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 16:18
 */

#ifndef PLANILHAREGRASDEPONTUACAO_H
#define PLANILHAREGRASDEPONTUACAO_H
#include <vector>
#include "regrasDePontuacao.h"

namespace trabalho{
class planilhaRegrasDePontuacao {
    map<int,regrasDePontuacao> mapaRegras;
public:
    planilhaRegrasDePontuacao();
    map<int,regrasDePontuacao> getListaRegras();
    void setListaRegras(map<int, regrasDePontuacao> mapaRegras);
    map<int,regrasDePontuacao> ler(int argc, char ** argv);
    void qualisDesconhecidoParaRegras(map<int, regrasDePontuacao> mapaRegras);
private:

};
}
#endif /* PLANILHAREGRASDEPONTUACAO_H */

