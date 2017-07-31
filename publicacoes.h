/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   publicacoes.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 12:34
 */

#ifndef PUBLICACOES_H
#define PUBLICACOES_H

#include <string>
#include <vector>
#include "veiculos.h"
#include "docentes.h"


using namespace std;

namespace trabalho{
class publicacoes {
    int ano;
    string titulo;
    int paginaInicial;
    int paginaFinal;
    int numero;

    veiculos veiculo;
    vector<docentes> autores;

public:
    publicacoes();
    
    int getAno();

    void setAno(int);

    string getTitulo();

    void setTitulo(string);

    vector<docentes> getAutores();
    
    void setAutores(vector<docentes>);

    veiculos getVeiculo();
    
    void setVeiculo(veiculos);

    int getNumero();

    void setNumero(int);

    int getPaginaInicial();

    void setPaginaInicial(int);

    int getPaginaFinal();

    void setPaginaFinal(int);
    
    static bool compareTo(publicacoes,publicacoes);
    
private:

};


}
#endif /* PUBLICACOES_H */

