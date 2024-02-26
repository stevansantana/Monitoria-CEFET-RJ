#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente
{
    int codigo;
    char nome[30];
    double investimentos[3];
};

struct Movimentacao
{
    int codigoCliente;
    char codigoOperacao;
    int codigoInvestimento;
    double valor;
};

int leDadosClientes(struct Cliente clientes[], double matrizInvestimentos[][3]);
int busca(int qtdClientes, int codigo, struct Cliente clientes[]);
void emitirRelatorio(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3], double totalMovimentacoesNaoRealizadas);
void emitirZerados(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3]);
void exibeMaior(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3]);
double leMovimentacao(int qtdClientes, struct Movimentacao movimentacoes[], struct Cliente clientes[], double matrizInvestimentos[][3]);

#endif // FUNCOES_H_INCLUDED
