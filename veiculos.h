/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   veiculos.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 13:09
 */

#ifndef VEICULOS_H
#define VEICULOS_H

#include <string>

using namespace std;

namespace trabalho{
class veiculos {
    string sigla;
    string nome;
    double fatorImpacto;
    string issn;
    const char * tipo;
public:
    veiculos();
    string getSigla();

    string getNome();

    const char * getTipo();

    double getFatorImpacto();
    
    string getIssn();

    void setSigla(string sigla);

    void setNome(string nome);

    void setTipo(const char * tipo);

    void setFatorImpacto(double fatorImpacto);

    void setIssn(string issn);

    
private:

};
}
#endif /* VEICULOS_H */

