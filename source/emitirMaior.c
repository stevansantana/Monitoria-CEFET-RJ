#include "funcoes.h"

void exibeMaior(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3])
{
    printf("\n\nCLIENTE COM MAIOR VALOR APLICADO:\n\n");

    double soma = 0, maior = 0;
    char nome[30];

    for (int i = 0; i < qtdClientes; i++)
    {
        soma = matrizInvestimentos[i][0] + matrizInvestimentos[i][1] + matrizInvestimentos[i][2];
        if (soma > maior)
        {
            maior = soma;
            strcpy(nome, clientes[i].nome);
        }
    }
    if(maior == 0)
    {
        printf("Nao ha clientes com maior valor aplicado\n\n");
    }
    else
    {
        printf("%s\t\t\t", nome);
        printf("%.2lf\n\n", maior);
    }
    printf("--------------------------------------------------------------------------------------------");
}
