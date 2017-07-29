/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   periodicos.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 13:22
 */

#ifndef PERIODICOS_H
#define PERIODICOS_H
#include "publicacoes.h"

namespace trabalho{
class periodicos : public publicacoes {
    int volume;
public:
    periodicos();
    int getVolume();
    void setVolume(int volume);
private:

};
}
#endif /* PERIODICOS_H */

