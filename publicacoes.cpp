/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   publicacoes.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 12:34
 */

#include "publicacoes.h"

using namespace trabalho;

publicacoes::publicacoes() {

}

int publicacoes::getAno() {
    return ano;
}

int publicacoes::getNumero() {
    return numero;
}

int publicacoes::getPaginaFinal() {
    return paginaFinal;
}

int publicacoes::getPaginaInicial() {
    return paginaInicial;
}

veiculos publicacoes::getVeiculo() {
    return veiculo;
}

void publicacoes::setVeiculo(veiculos veiculo) {
    this->veiculo = veiculo;
}

string publicacoes::getTitulo() {
    return titulo;
}

vector<docentes>publicacoes::getAutores() {
    return autores;
}

void publicacoes::setAno(int ano) {
    this->ano = ano;
}

void publicacoes::setNumero(int numero) {
    this->numero = numero;
}

void publicacoes::setPaginaFinal(int paginaFinal) {
    this->paginaFinal = paginaFinal;
}

void publicacoes::setPaginaInicial(int paginaInicial) {
    this->paginaInicial = paginaInicial;
}

void publicacoes::setTitulo(string titulo) {
    this->titulo = titulo;
}

void publicacoes::setAutores(vector<docentes> autores) {
    this->autores = autores;
}

bool publicacoes::compareTo(publicacoes publicacao1, publicacoes publicacao2) {

    string qualis1 = publicacao1.getVeiculo().getQualis()[0].getQualis();
    string qualis2 = publicacao2.getVeiculo().getQualis()[0].getQualis();
    int a = qualis1.compare(qualis2);
    if (a)
        return a < 0;

    int anos1 = publicacao1.getAno();
    int anos2 = publicacao2.getAno();
    int b = anos2 - anos1;
    if (b)
        return b < 0;

    string sigla1 = publicacao1.getVeiculo().getSigla();
    string sigla2 = publicacao2.getVeiculo().getSigla();
    int c = sigla1.compare(sigla2);
    if (c)
        return c < 0;

    string tituloPublicacao1 = publicacao1.getTitulo();
    string tituloPublicacao2 = publicacao2.getTitulo();
    int d = tituloPublicacao1.compare(tituloPublicacao2);

    if (d)
        return d < 0;




}