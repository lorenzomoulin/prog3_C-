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

#include <vector>
#include <string>
#include <iostream>
#include "DateUtils.h"
#include "docentes.h"

using namespace std;

namespace trabalho{
class planilhaDocentes {
    vector<docentes> vetorDocentes;
public:
    planilhaDocentes();
    vector<docentes> getListaDocentes();
    void setListaDocentes(vector<docentes> vetorDocentes);
    vector<docentes> ler(char** args, int argc);
    void codigoRepetidoParaDocente(vector<docentes> listaDocentes);
    
private:

};
}
#endif /* PLANILHADOCENTES_H */

