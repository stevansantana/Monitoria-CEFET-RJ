#include "funcoes.h"

int main()
{
    struct Cliente clientes[6000];
    struct Movimentacao movimentacoes[6000];
    double matrizInvestimentos[6000][3];

    printf("BEM VINDO AO BANCO PAC!!!\n\n");
    printf("Venha informar os dados de seus clientes!\n\n");
    system("pause");
    system("cls");

    int qtdClientes = leDadosClientes(clientes, matrizInvestimentos);

    if (qtdClientes == 0)
    {
        system("cls");
        printf("Nenhum cliente lido.\n");
    }
    else
    {
        double totalMovimentacoesNaoRealizadas = leMovimentacao(qtdClientes, movimentacoes, clientes, matrizInvestimentos);
        emitirRelatorio(qtdClientes, clientes, matrizInvestimentos, totalMovimentacoesNaoRealizadas);
        emitirZerados(qtdClientes, clientes, matrizInvestimentos);
        exibeMaior(qtdClientes, clientes, matrizInvestimentos);
    }
    return 0;
}
