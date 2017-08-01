/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   docentes.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 12:04
 */

#include "docentes.h"
#include <ctime>
using namespace trabalho;

docentes::docentes() {

}

int docentes::getRecredenciado(){
    return recredenciado;
}  
            
void docentes::setRecredenciado(int recredenciado){
    this->recredenciado = recredenciado;
}


double docentes::getPontuacao(){
    return pontuacao;
}

void docentes::setPontuacao(double pontuacao){
    this->pontuacao = pontuacao;
}

long docentes::getCodigo() {
    return codigo;
}

bool docentes::getEhCoordenador() {
    return EhCoordenador;
}

string docentes::getNome() {
    return nome;
}

time_t docentes::getDataIngresso() {
    return dataIngresso;
}

time_t docentes::getDataNascimento() {
    return dataNascimento;
}

void docentes::setCodigo(const long codigo) {
    this->codigo = codigo;
}

void docentes::setNome(string nome) {
    this->nome = nome;
}

void docentes::setEhCoordenador(bool EhCoordenador) {
    this->EhCoordenador = EhCoordenador;
}

void docentes::setDataIngresso(time_t dataIngresso) {
    this->dataIngresso = dataIngresso;
}

void docentes::setDataNascimento(time_t dataNascimento) {
    this->dataNascimento = dataNascimento;
}

bool docentes::entrouMenosDe3Anos(regrasDePontuacao regra) {
    
    time_t temp = regra.getDataInicio();
    
    //time_t inicioVigenciaMili = time(&temp);
    
    time_t temp1 = this->dataIngresso;
    
    //time_t dataIngressoMili = time(&temp1);
    
    
    
    long tempo = (temp - temp1)*1000 + 3600;
    
    
    tempo = tempo / 31557600000L;
    
    return tempo < 3;
}

bool docentes::temMaisDe60Anos(regrasDePontuacao regra) {
    
    time_t temp = regra.getDataInicio();
    
    time_t temp1 = this->dataNascimento;
    

    long tempo = (temp - temp1)*1000 + 3600;
    
    tempo = tempo / 31557600000L;

    return tempo >= 60;
}

bool docentes::comparador(docentes d1, docentes d2){
    return d1.nome < d2.nome;
}