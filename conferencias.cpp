/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conferencias.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 13:18
 */

#include "conferencias.h"

using namespace trabalho;

conferencias::conferencias() {
}

string conferencias::getLocal(){
    return local;
}

void conferencias::setLocal(string local){
    this->local = local;
}