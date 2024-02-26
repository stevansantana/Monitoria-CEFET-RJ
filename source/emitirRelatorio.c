#include "funcoes.h"

void emitirRelatorio(int qtdClientes, struct Cliente clientes[], double matrizInvestimentos[][3], double totalMovimentacoesNaoRealizadas)
{
    system("cls");
    printf("\nRESULTADO ESPERADO:");
    printf("\n\n-------------------------------");

    for (int i = 0; i < qtdClientes; i++)
    {
        printf("\n\nNome: %s\n\n", clientes[i].nome);
        printf("Codigo: %d\n\n", clientes[i].codigo);

        if(i == qtdClientes - 1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 2)
                {
                    printf("Valor Ap %d: %.2lf", j+1, matrizInvestimentos[i][j]);
                }
                else
                {
                    printf("Valor Ap %d: %.2lf\n\n", j+1, matrizInvestimentos[i][j]);
                }
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 2)
                {
                    printf("Valor Ap %d: %.2lf", j+1, matrizInvestimentos[i][j]);
                }
                else
                {
                    printf("Valor Ap %d: %.2lf\n\n", j+1, matrizInvestimentos[i][j]);
                }
            }
            printf("\n\n-------------------------------");
        }
    }

    printf("\n\n\nValor total de transacoes nao realizadas = %.2lf\n\n", totalMovimentacoesNaoRealizadas);
    printf("--------------------------------------------------------------------------------------------");
}
