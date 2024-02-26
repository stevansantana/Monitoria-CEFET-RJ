#include "funcoes.h"

int leDadosClientes(struct Cliente clientes[], double matrizInvestimentos[][3])
{
    int qtdClientes = 0;
    for (int i = 0; i < 6000; i++)
    {
        system("cls");
        printf("Informe o codigo (1 a 6000) para seu cliente %d.\n", i + 1);
        printf("\n\t\tOU\n\n");
        printf("Aperte 0 para terminar a leitura de clientes.\n");

        while(scanf("%d", &clientes[i].codigo) != 1)
        {
            system("cls");
            printf("Entrada invalida. Por favor, insira um numero (1 ate 6000).\n");

            // Limpar o buffer de entrada para evitar loop infinito
            while (getchar() != '\n')
            {
                // Descartar caracteres do buffer
            }
        }
        if (clientes[i].codigo == 0)
        {
            system("cls");
            printf("Termino da leitura dos clientes\n\n");
            system("pause");
            break;
        }

        while (clientes[i].codigo < 0 || clientes[i].codigo > 6000)
        {
            system("cls");
            printf("Codigo de cliente invalido\n\n");
            printf("Informe o codigo (1 a 6000) novamente:\n");

            while(scanf("%d", &clientes[i].codigo) != 1)
            {
                system("cls");
                printf("Entrada invalida. Por favor, insira um numero (1 ate 6000).\n");

                // Limpar o buffer de entrada para evitar loop infinito
                while (getchar() != '\n')
                {
                // Descartar caracteres do buffer
                }
            }
        }

        system("cls");
        printf("Informe o nome do seu cliente %d:\n", i + 1);

        // Consumir o caractere de nova linha deixado pelo scanf anterior
        getchar();
        fgets(clientes[i].nome, sizeof(clientes[i].nome), stdin);

        // Remover a quebra de linha do final da string
        int tamanhoNome = strlen(clientes[i].nome);
        if (tamanhoNome > 0 && clientes[i].nome[tamanhoNome - 1] == '\n')
        {
            clientes[i].nome[tamanhoNome - 1] = '\0';
        }

        for (int j = 0; j < 3; j++)
        {
            system("cls");
            printf("Informe o investimento %d de %s:\n", j + 1, clientes[i].nome);

            while(scanf("%lf", &clientes[i].investimentos[j]) != 1)
            {
                system("cls");
                printf("Entrada invalida. Por favor, insira um valor (numero) para o investimento %d.\n", j+1);

                // Limpar o buffer de entrada para evitar loop infinito
                while (getchar() != '\n')
                {
                    // Descartar caracteres do buffer
                }
            }
            matrizInvestimentos[i][j] = clientes[i].investimentos[j];
        }
        qtdClientes++;
    }
    return qtdClientes;
}
