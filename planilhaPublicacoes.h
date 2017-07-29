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
using namespace std;

namespace trabalho{
class planilhaPublicacoes {
    vector<publicacoes> vetorPublicacoes;
public:
    planilhaPublicacoes();
    vector<publicacoes> getListaPublicacoes();
    void setListaPublicacoes(vector<publicacoes> vetorPublicacoes);
    vector<publicacoes> ler(int argc, char ** argv, vector <docentes> vetorDocentes);
    void codigoDocenteNaoEspecificado(vector<publicacoes> vetorPublicacoes,
            vector<docentes> listaDocentes);
private:

};
}
#endif /* PLANILHAPUBLICACOES_H */

