/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lorenzo
 *
 * Created on 26 de Julho de 2017, 12:01
 */

#include <cstdlib>
#include "planilhaDocentes.h"
#include "docentes.h"
#include <vector>
#include "planilhaPublicacoes.h"
#include "planilhaQualificacoes.h"
#include "planilhaRegrasDePontuacao.h"


using namespace std;
using namespace trabalho;

/*
 * 
 */
int main(int argc, char** argv) {
    planilhaDocentes pd; 
    vector<docentes> vetorDocentes = pd.ler(argv, argc);
    
    planilhaPublicacoes pp;
    vector<publicacoes> vetorPublicacoes = pp.ler(argc,argv, vetorDocentes);
    
    planilhaQualificacoes pq;
    vector<qualificacoes> vetorQualificacoes = pq.ler(argc,argv);
    
    planilhaRegrasDePontuacao pr;
    vector<regrasDePontuacao> vetorRegras = pr.ler(argc, argv);
    
    
    
    return 0;
}

/*/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 
package br.ufes.trabalho.prog3.principal;

import br.ufes.trabalho.prog3.Excecoes.*;
import static br.ufes.trabalho.prog3.principal.RegrasDePontuacao.expandeQualis;
import static br.ufes.trabalho.prog3.Relatorios.EstatisticasDePublicacoes.*;
import static br.ufes.trabalho.prog3.Relatorios.GeraPublicacoes.PublicacoesParaRelatorio;
import static br.ufes.trabalho.prog3.Relatorios.Recredenciamento.recredencia;

import java.io.IOException;
import java.text.ParseException;
import java.util.List;

/**
 *
 * @author Daniel
 
public class Main {

    /**
     * @param args the command line arguments
     
    public static void main(String[] args) {
        try {
            // LE PLANILHA DE DOCENTES E CRIA UMA LISTA DE DOCENTES
            List<Docentes> listaDocentes = br.ufes.trabalho.prog3.Leitura.PlanilhaDocentes.Ler(args);

            // LE PLANILHA DE PUBLICACOES E CRIA UMA LISTA DE PUBLICACOES
            List<Publicacoes> listaPublicacoes = br.ufes.trabalho.prog3.Leitura.PlanilhaPublicacoes.Ler(args, listaDocentes);

            // LE PLANILHA DE QUALIS E CRIA UMA LISTA DE QUALIS
            List<Qualificacoes> listaQualis = br.ufes.trabalho.prog3.Leitura.PlanilhaQualificacoes.Ler(args);

            // LE PLANILHA DE REGRAS E CRIA UMA LISTA DE REGRAS
            List<RegrasDePontuacao> listaRegras = br.ufes.trabalho.prog3.Leitura.PlanilhaRegrasDePontuacao.Ler(args);

            // LE PLANILHA DE VEICULOS E CRIA UMA LISTA DE VEICULOS
            List<Veiculos> listaVeiculos = br.ufes.trabalho.prog3.Leitura.PlanilhaVeiculos.Ler(args, listaQualis, listaPublicacoes);

            int ano = 0;
            // PROCURA ANO DE RECREDENCIAMENTO
            for (int i = 0; i < args.length; i++) {
                if (args[i].compareTo("-a") == 0) {
                    ano = Integer.parseInt(args[i + 1]);
                }
            }

            // PARA ATRIBUIR QUALIS A SEUS RESPECTIVOS PONTOS DADO UM ANO
            expandeQualis(listaRegras, ano);

            // PARA O RELATORIO DE ESTATISTICAS
            contaNumeroArtigosPorQualis(listaPublicacoes, listaQualis);
            contaNumeroArtigosPorDocentes(listaPublicacoes, listaQualis);
            criaArquivoEstatisticas();

            // PARA O RELATORIO DE PUBLICACOES
            PublicacoesParaRelatorio(listaPublicacoes, listaQualis, listaVeiculos, listaDocentes);

            // PARA O RELATORIO DE RECREDENCIAMENTO, DADO UM ANO
            recredencia(listaDocentes, ano, listaRegras, listaVeiculos, listaPublicacoes, listaQualis);

        } catch (tipoDeVeiculoDesconhecidoParaVeiculo e1) {
            System.out.println(e1);
        } catch (qualisDesconhecidoParaQualificacao e2) {
            System.out.println(e2);
        } catch (codigoRepetidoParaDocente e3) {
            System.out.println(e3);
        } catch (siglaRepetidaParaVeiculo e4) {
            System.out.println(e4);
        } catch (siglaNaoDefinidaNaPublicacao e5) {
            System.out.println(e5);
        } catch (codigoDocenteNaoEspecificado e6) {
            System.out.println(e6);
        } catch (siglaNaoDefinidaNaQualificacao e7) {
            System.out.println(e7);
        } catch (qualisDesconhecidoParaRegra e8) {
            System.out.println(e8);
        } catch (IOException e9) {
            System.out.println("Erro de I/O");
        } catch (ParseException e10) {
            System.out.println("Erro de formatação");
        } catch (NumberFormatException e11) {
            System.out.println("Erro de formatação");
        }
    }
}
*/