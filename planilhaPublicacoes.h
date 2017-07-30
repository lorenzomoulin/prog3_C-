/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaPublicacoes.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 13:33
 */

#ifndef PLANILHAPUBLICACOES_H
#define PLANILHAPUBLICACOES_H

#include <vector>
#include "publicacoes.h"
#include "docentes.h"
#include <map>

using namespace std;

namespace trabalho{
class planilhaPublicacoes {
    map<int,publicacoes> mapaPublicacoes;
public:
    planilhaPublicacoes();
    map<int,publicacoes> getListaPublicacoes();
    void setListaPublicacoes(map<int,publicacoes> mapaPublicacoes);
    map<int,publicacoes> ler(int argc, char ** argv, map<int,docentes> mapaDocentes);
    void codigoDocenteNaoEspecificado(map<int,publicacoes> mapaPublicacoes,
            map<int,docentes> mapaDocentes);
private:

};
}
#endif /* PLANILHAPUBLICACOES_H */

