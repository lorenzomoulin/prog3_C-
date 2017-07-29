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

publicacoes::publicacoes(){
    
}

int publicacoes::getAno(){
    return ano;
}

int publicacoes::getNumero(){
    return numero;
}

int publicacoes::getPaginaFinal(){
    return paginaFinal;
}

int publicacoes::getPaginaInicial(){
    return paginaInicial;
}

string publicacoes::getSiglaVeiculo(){
    return siglaVeiculo;
}

string publicacoes::getTitulo(){
    return titulo;
}

vector<long>publicacoes::getAutores(){
    return autores;
}

void publicacoes::setAno(int ano){
    this->ano = ano;
}

void publicacoes::setNumero(int numero){
    this->numero = numero;
}

void publicacoes::setPaginaFinal(int paginaFinal){
    this->paginaFinal = paginaFinal;
}

void publicacoes::setPaginaInicial(int paginaInicial){
    this->paginaInicial = paginaInicial;
}

void publicacoes::setSiglaVeiculo(string siglaVeiculo){
    this->siglaVeiculo = siglaVeiculo;
}

void publicacoes::setTitulo(string titulo){
    this->titulo = titulo;
}

void publicacoes::setAutores(vector<long> autores){
    this->autores = autores;
}