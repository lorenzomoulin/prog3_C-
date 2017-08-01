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
#include "regrasDePontuacao.h"


using namespace std;

namespace trabalho {
    class docentes {
        
        string nome;
        time_t dataNascimento;
        time_t dataIngresso;
        bool EhCoordenador;
        long codigo;
        double pontuacao;
        int recredenciado;
        
        public:
            docentes();
            
            int getRecredenciado();
            
            void setRecredenciado(int);
            
            double getPontuacao();
            
            void setPontuacao(double);
            
            long getCodigo();
            
            bool getEhCoordenador();
            
            string getNome();
            
            time_t getDataNascimento();       
            
            time_t getDataIngresso(); 
            
            void setNome(string);

            void setDataNascimento(time_t);

            void setDataIngresso(time_t);
            
            void setCodigo(long);
            
            void setEhCoordenador(bool);
            
            bool entrouMenosDe3Anos(regrasDePontuacao);
            
            bool temMaisDe60Anos(regrasDePontuacao);
                   
            static bool comparador(docentes,docentes);
        private:

            
            
            
            
            
    };
    
    
}
#endif /* DOCENTES_H */

