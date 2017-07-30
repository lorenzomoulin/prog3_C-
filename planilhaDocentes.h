/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   planilhaDocentes.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 13:34
 */

#ifndef PLANILHADOCENTES_H
#define PLANILHADOCENTES_H

#include <map>
#include <string>
#include <iostream>
#include "DateUtils.h"
#include "docentes.h"

using namespace std;

namespace trabalho{
class planilhaDocentes {
    map<int,docentes> mapaDocentes;
public:
    planilhaDocentes();
    map<int,docentes> getListaDocentes();
    void setListaDocentes(map<int,docentes> mapaDocentes);
    map<int,docentes> ler(char** args, int argc);
    void codigoRepetidoParaDocente(map<int,docentes> mapaDocentes);
    
private:

};
}
#endif /* PLANILHADOCENTES_H */

