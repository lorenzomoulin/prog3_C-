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

using namespace trabalho;

docentes::docentes(){
    
}

long docentes::getCodigo(){
    return codigo;
}

bool docentes::getEhCoordenador(){
    return EhCoordenador;
}

string docentes::getNome(){
    return nome;
}

time_t docentes::getDataIngresso(){
    return dataIngresso;
}

time_t docentes::getDataNascimento(){
    return dataNascimento;
}

void docentes::setCodigo(const long codigo){
    this->codigo = codigo;
}

void docentes::setNome(string nome){
    this->nome = nome;
}

void docentes::setEhCoordenador(bool EhCoordenador){
    this->EhCoordenador = EhCoordenador;
}

void docentes::setDataIngresso(time_t dataIngresso){
    this->dataIngresso = dataIngresso;
}

void docentes::setDataNascimento(time_t dataNascimento){
    this->dataNascimento = dataNascimento;
}