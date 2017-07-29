/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   periodicos.cpp
 * Author: lorenzo
 * 
 * Created on 26 de Julho de 2017, 13:22
 */

#include "periodicos.h"

using namespace trabalho;

periodicos::periodicos() {
}

int periodicos::getVolume(){
    return volume;
}

void periodicos::setVolume(int volume){
    this->volume = volume;
}
