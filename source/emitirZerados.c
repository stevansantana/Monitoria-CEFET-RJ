#include "funcoes.h"

void emitirZerados(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3])
{
    printf("\n\nCLIENTES COM TODAS AS APLICACOES ZERADAS:\n\n");

    int flag = 1;
    for (int i = 0; i < qtdClientes; i++)
    {
        if (matrizInvestimentos[i][0] == 0 && matrizInvestimentos[i][1] == 0 && matrizInvestimentos[i][2] == 0)
        {
            printf("%s\n", clientes[i].nome);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("Nenhum cliente com aplicacao zerada\n");
    }
    printf("\n--------------------------------------------------------------------------------------------");
}
