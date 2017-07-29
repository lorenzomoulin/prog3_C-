/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   regrasDePontuacao.h
 * Author: lorenzo
 *
 * Created on 28 de Julho de 2017, 16:22
 */

#ifndef REGRASDEPONTUACAO_H
#define REGRASDEPONTUACAO_H
#include <vector>
#include <string>

using namespace std;

namespace trabalho{
class regrasDePontuacao {
    double fatorMultiplicador;
    time_t dataInicio;
    time_t dataFim;
    int quantidadeAnos;
    int pontuacaoMinima;
    vector<string> qualis; // VETOR de qualis e de pontos tem mesmo tamanho
    vector<int> pontos;
public:
    regrasDePontuacao();
    
    time_t getDataInicio();

    void setDataInicio(time_t dataInicio);

    time_t getDataFim();

    void setDataFim(time_t dataFim); 

    vector<string> getQualis();

    void setQualis(vector<string> qualis);

    vector<int> getPontos();

    void setPontos(vector<int> pontos);

    double getMultiplicador();

    void setMultiplicador(double multiplicador);

    int getQuantidadeAnosConsiderar();

    void setQuantidadeAnosConsiderar(int quantidadeAnosConsiderar);

    int getPontuacaoMinimaRecredenciamento();

    void setPontuacaoMinimaRecredenciamento(int pontuacaoMinimaRecredenciamento);
    
    void expandeQualis(vector<regrasDePontuacao> vetorRegras, int ano);
    
private:

};
}
#endif /* REGRASDEPONTUACAO_H */

