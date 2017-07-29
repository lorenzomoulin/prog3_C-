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



using namespace std;

namespace trabalho{
class publicacoes {
    int ano;
    string titulo;
    int paginaInicial;
    int paginaFinal;
    int numero;

    string siglaVeiculo;
    vector<long> autores;

public:
    publicacoes();
    int getAno();

    void setAno(int ano);

    string getSiglaVeiculo();

    void setSiglaVeiculo(string siglaVeiculo);

    string getTitulo();

    void setTitulo(string titulo);

    vector<long> getAutores();
    
    void setAutores(vector<long> autores);

    

    int getNumero();

    void setNumero(int numero);

    int getPaginaInicial();

    void setPaginaInicial(int paginaInicial);

    int getPaginaFinal();

    void setPaginaFinal(int paginaFinal);
    
private:

};
}
#endif /* PUBLICACOES_H */

