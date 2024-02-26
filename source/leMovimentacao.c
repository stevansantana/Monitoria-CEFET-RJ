#include "funcoes.h"

double leMovimentacao(int qtdClientes, struct Movimentacao movimentacoes[], struct Cliente clientes[], double matrizInvestimentos[][3])
{
    double totalMovimentacoesNaoRealizadas = 0;
    int posicao, flag = 1, i = 0;

    do
    {
        system("cls");
        printf("Informe o codigo do cliente que voce deseja fazer as movimentacoes.");
        printf("\n\n\t\tOU\n\n");
        printf("Aperte 0 para terminar a leitura das movimentacoes.\n");

        while(scanf("%d", &movimentacoes[i].codigoCliente) != 1)
        {
            system("cls");
            printf("Entrada invalida.\n\n");
            printf("Informe o codigo do cliente que voce deseja fazer as movimentacoes.");
            printf("\n\n\t\tOU\n\n");
            printf("Aperte 0 para terminar a leitura das movimentacoes.\n");

            // Limpar o buffer de entrada para evitar loop infinito
            while (getchar() != '\n')
            {
                // Descartar caracteres do buffer
            }
        }

        if(movimentacoes[i].codigoCliente == 0)
        {
            system("cls");
            printf("Termino da leitura das movimentacoes\n\n");
            system("pause");
            break;
        }

        posicao = busca(qtdClientes, movimentacoes[i].codigoCliente, clientes);

        while (posicao == -1)
        {
            system("cls");
            printf("Codigo de cliente invalido\n\n");
            printf("Informe novamente:\n");

            while(scanf("%d", &movimentacoes[i].codigoCliente) != 1)
            {
                system("cls");
                printf("Entrada invalida.\n\n");
                printf("Informe o codigo do cliente que voce deseja fazer as movimentacoes.\n");

                // Limpar o buffer de entrada para evitar loop infinito
                while (getchar() != '\n')
                {
                    // Descartar caracteres do buffer
                }
            }
            posicao = busca(qtdClientes, movimentacoes[i].codigoCliente, clientes);
        }

        system("cls");
        printf("Informe o tipo de investimento (1, 2 ou 3) para o cliente de codigo %d\n", movimentacoes[i].codigoCliente);

        while(scanf("%d", &movimentacoes[i].codigoInvestimento) != 1)
        {
            system("cls");
            printf("Entrada invalida.\n\n");
            printf("Informe o tipo de investimento (1, 2 ou 3) para o cliente de codigo %d\n", movimentacoes[i].codigoCliente);

            // Limpar o buffer de entrada para evitar loop infinito
            while (getchar() != '\n')
            {
                // Descartar caracteres do buffer
            }
        }

        while (movimentacoes[i].codigoInvestimento != 1 && movimentacoes[i].codigoInvestimento != 2 && movimentacoes[i].codigoInvestimento != 3)
        {
            system("cls");
            printf("Codigo de investimento invalido\n\n");
            printf("Informe novamente:\n");

            while(scanf("%d", &movimentacoes[i].codigoInvestimento) != 1)
            {
                system("cls");
                printf("Entrada invalida.\n\n");
                printf("Informe o tipo de investimento (1, 2 ou 3) para o cliente de codigo %d\n", movimentacoes[i].codigoCliente);

                // Limpar o buffer de entrada para evitar loop infinito
                while (getchar() != '\n')
                {
                    // Descartar caracteres do buffer
                }
            }
        }

        switch (movimentacoes[i].codigoInvestimento)
        {
        case 1:

            system("cls");
            printf("Investimento 1 do cliente de codigo %d\n\n", movimentacoes[i].codigoCliente);
            printf("Aperte 'A' - Para fazer uma aplicacao");
            printf("\n\nOU\n\n");
            printf("Aperte 'R' - Para fazer um resgate\n");
            scanf(" %c", &movimentacoes[i].codigoOperacao);

            while (movimentacoes[i].codigoOperacao != 'A' && movimentacoes[i].codigoOperacao != 'R')
            {
                system("cls");
                printf("Codigo de operacao invalido\n\n");
                printf("Informe novamente:\n");
                scanf(" %c", &movimentacoes[i].codigoOperacao);
            }

            if (movimentacoes[i].codigoOperacao == 'A')
            {
                system("cls");
                printf("Informe o valor que deseja aplicar:\n");

                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Informe o valor que deseja aplicar\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }
                matrizInvestimentos[posicao][0] += movimentacoes[i].valor;
            }
            else if (movimentacoes[i].codigoOperacao == 'R')
            {
                system("cls");
                printf("Informe o valor que deseja resgatar:\n");

                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Informe o valor que deseja resgatar\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }

                while (movimentacoes[i].valor > matrizInvestimentos[posicao][0])
                {
                    totalMovimentacoesNaoRealizadas += movimentacoes[i].valor;

                    system("cls");
                    printf("Saldo insuficiente\n\n");
                    printf("Por favor, informe um valor que seja possivel sacar:\n");

                    while(scanf("%lf", &movimentacoes[i].valor) != 1)
                    {
                        system("cls");
                        printf("Entrada invalida.\n\n");
                        printf("Por favor, informe um valor que seja possivel sacar:\n");

                        // Limpar o buffer de entrada para evitar loop infinito
                        while (getchar() != '\n')
                        {
                            // Descartar caracteres do buffer
                        }
                    }
                }
                matrizInvestimentos[posicao][0] -= movimentacoes[i].valor;
            }
            break;

        case 2:

            system("cls");
            printf("Investimento 2 do cliente de codigo %d\n\n", movimentacoes[i].codigoCliente);
            printf("Aperte 'A' - Para fazer uma aplicacao");
            printf("\n\nOU\n\n");
            printf("Aperte 'R' - Para fazer um resgate\n");
            scanf(" %c", &movimentacoes[i].codigoOperacao);

            while(movimentacoes[i].codigoOperacao != 'A' && movimentacoes[i].codigoOperacao != 'R')
            {
                system("cls");
                printf("Codigo de operacao invalido\n\n");
                printf("Informe novamente:\n");
                scanf(" %c", &movimentacoes[i].codigoOperacao);
            }

            if (movimentacoes[i].codigoOperacao == 'A')
            {
                system("cls");
                printf("Informe o valor que deseja aplicar:\n");
                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Por favor, informe que deseja aplicar:\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }
                matrizInvestimentos[posicao][1] += movimentacoes[i].valor;
            }
            else if (movimentacoes[i].codigoOperacao == 'R')
            {
                system("cls");
                printf("Informe o valor que deseja resgatar:\n");
                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Por favor, informe um valor que deseja resgatar:\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }

                while (movimentacoes[i].valor > matrizInvestimentos[posicao][1])
                {
                    totalMovimentacoesNaoRealizadas += movimentacoes[i].valor;

                    system("cls");
                    printf("Saldo insuficiente\n\n");
                    printf("Por favor, informe um valor que seja possivel sacar:\n");

                    while(scanf("%lf", &movimentacoes[i].valor) != 1)
                    {
                        system("cls");
                        printf("Entrada invalida.\n\n");
                        printf("Por favor, informe um valor que seja possivel sacar:\n");

                        // Limpar o buffer de entrada para evitar loop infinito
                        while (getchar() != '\n')
                        {
                            // Descartar caracteres do buffer
                        }
                    }
                }

                matrizInvestimentos[posicao][1] -= movimentacoes[i].valor;
            }
            break;

        case 3:

            system("cls");
            printf("Investimento 3 do cliente de codigo %d\n\n", movimentacoes[i].codigoCliente);
            printf("Aperte 'A' - Para fazer uma aplicacao");
            printf("\n\nOU\n\n");
            printf("Aperte 'R' - Para fazer um resgate\n");
            scanf(" %c", &movimentacoes[i].codigoOperacao);

            while (movimentacoes[i].codigoOperacao != 'A' && movimentacoes[i].codigoOperacao != 'R')
            {
                system("cls");
                printf("Codigo de operacao invalido\n\n");
                printf("Informe novamente:\n");
                scanf(" %c", &movimentacoes[i].codigoOperacao);
            }

            if (movimentacoes[i].codigoOperacao == 'A')
            {
                system("cls");
                printf("Informe o valor que deseja aplicar:\n");
                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Por favor, informe um valor que deseja aplicar:\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }
                matrizInvestimentos[posicao][2] += movimentacoes[i].valor;
            }
            else if (movimentacoes[i].codigoOperacao == 'R')
            {
                system("cls");
                printf("Informe o valor que deseja resgatar:\n");
                while(scanf("%lf", &movimentacoes[i].valor) != 1)
                {
                    system("cls");
                    printf("Entrada invalida.\n\n");
                    printf("Por favor, informe o valor que deseja resgatar:\n");

                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                    {
                        // Descartar caracteres do buffer
                    }
                }

                while (movimentacoes[i].valor > matrizInvestimentos[posicao][2])
                {
                    totalMovimentacoesNaoRealizadas += movimentacoes[i].valor;

                    system("cls");
                    printf("Saldo insuficiente\n\n");
                    printf("Por favor, informe um valor que seja possivel sacar:\n");

                    while(scanf("%lf", &movimentacoes[i].valor) != 1)
                    {
                        system("cls");
                        printf("Entrada invalida.\n\n");
                        printf("Por favor, informe um valor que seja possivel sacar:\n");

                        // Limpar o buffer de entrada para evitar loop infinito
                        while (getchar() != '\n')
                        {
                            // Descartar caracteres do buffer
                        }
                    }
                }
                matrizInvestimentos[posicao][2] -= movimentacoes[i].valor;
            }
            break;
        }
    }while(movimentacoes[i].codigoCliente != 0);

    return totalMovimentacoesNaoRealizadas;
}
