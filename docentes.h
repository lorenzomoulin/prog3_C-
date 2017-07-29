/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   docentes.h
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 12:04
 */

#ifndef DOCENTES_H
#define DOCENTES_H

#include <iostream>
#include <string>
#include "DateUtils.h"


using namespace std;

namespace trabalho {
    class docentes {
        
        string nome;
        time_t dataNascimento;
        time_t dataIngresso;
        bool EhCoordenador;
        long codigo;
        
        public:
            docentes();
            
            
            long getCodigo();
            bool getEhCoordenador();
            string getNome();
            time_t getDataNascimento();       
            time_t getDataIngresso(); 
            
            void setNome(string nome);

            void setDataNascimento(time_t dataNascimento);

            void setDataIngresso(time_t dataIngresso);
            
            void setCodigo(long codigo);
            void setEhCoordenador(bool EhCoordenador);
            
            //bool entrouMenosDe3Anos(RegrasDePontuacao regra);
            //bool temMaisDe60Anos(RegrasDePontuacao regra);
            
            
        private:

            
            
            
            
            
    };
    
    
}
#endif /* DOCENTES_H */

