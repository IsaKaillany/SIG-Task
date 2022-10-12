#include <stdio.h>
#include <stdlib.h>


void navegacaoCrudAvisos(void)
{
    char opcao;
    do
    {
        opcao = crudAvisos();
        switch (opcao)
        {
        case '1':
            cadastroAvisos();
            break;
        case '2':
            buscarAvisos();
            break;
        case '3':
            atualizarAvisos();
            break;
        case '4':
            deletarAvisos();
            break;
        }
    } while (opcao != '0');
}