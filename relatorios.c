#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "usuarios.h"
#include "compromissos.h"
#include "avisos.h"


void navegacaoRelatorios(void)
{
    char opcao;
    do
    {
        opcao = telaRelatorios();
        switch (opcao)
        {
        case '1':
            navRelatoriosUsu();
            break;
        case '2':
            navRelatoriosComp();
            break;
        case '3':
            navRelatoriosAvisos();
            break;
        }
    } while (opcao != '0');
}

char telaRelatorios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-    R E L A T O R I O S    -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Relatorios de Usuarios\n");
    printf("\t2 - Relatorios de Compromissos\n");
    printf("\t3 - Relatorios de Avisos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navRelatoriosComp(void)
{
    char opcao;
    do
    {
        opcao = relatoriosCompromissos();
        switch (opcao)
        {
        case '1':
            listaCompromissos();
            break;
        case '2':
            filtrarCompromissos();
            break;
        }
    } while (opcao != '0');
}

char relatoriosCompromissos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Listar todos\n");
    printf("\t2 - Listar por data\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}