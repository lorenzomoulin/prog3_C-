/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recredenciamento.h
 * Author: lorenzo
 *
 * Created on 30 de Julho de 2017, 15:23
 */

#ifndef RECREDENCIAMENTO_H
#define RECREDENCIAMENTO_H
#include "docentes.h"
#include "regrasDePontuacao.h"
#include "veiculos.h"
#include "publicacoes.h"
#include "qualificacoes.h"
#include <vector>
#include <sstream>
#include <string>
#include <sstream>



using namespace std;


namespace trabalho {

    class recredenciamento {
        string nomeDocente;
        double pontuacaoAlcancada;
        int recredenciado; //0 para coordenador,1 para menos de 3 anos e 2 para mais de 60 anos de idade
    public:
        recredenciamento();
        string getNomeDocente();

        void setNomeDocente(string);

        double getPontuacaoAlcancada();

        void setPontuacaoAlcancada(double);

        int getRecredenciado();

        void setRecredenciado(int);

        //dado um docente e o ano de recredenciamento, calcula sua pontuação
        static void calculaPontuacao(vector<docentes>&, int, vector<regrasDePontuacao>&, vector<publicacoes>&);
        
        static void recredencia(vector<docentes>& , int, vector<regrasDePontuacao>&,
        vector<veiculos>&, vector<publicacoes>&, vector<qualificacoes>&);
        
        static void criaArquivoRecredenciamento(vector<docentes>&);
        
        regrasDePontuacao retornaRegraRecredenciamento(vector<regrasDePontuacao>, int);
        
    private:

    };
}
#endif /* RECREDENCIAMENTO_H */

