#include "funcoes.h"

int busca(int qtdClientes, int codigo, struct Cliente clientes[])
{
    for (int i = 0; i < qtdClientes; i++)
    {
        if (codigo == clientes[i].codigo)
        {
            return i;
        }
    }
    return -1;
}
