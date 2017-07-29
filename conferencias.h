/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conferencias.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 13:18
 */

#ifndef CONFERENCIAS_H
#define CONFERENCIAS_H

#include "publicacoes.h"
#include <string>

using namespace std;

namespace trabalho{
class conferencias : public publicacoes {
    string local;
public:
    conferencias();
    string getLocal();
    void setLocal(string local);
private:

};
}
#endif /* CONFERENCIAS_H */

