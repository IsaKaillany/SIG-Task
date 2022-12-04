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
        // case '1':
        //     navRelatoriosUsu();
        //     break;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navRelatoriosAvisos(void)
{
    char opcao;
    do
    {
        opcao = relatoriosAvisos();
        switch (opcao)
        {
        case '1':
            listaAvisos();
            break;
        case '2':
            filtrarAvisos();
            break;
        }
    } while (opcao != '0');
}

char relatoriosAvisos(void)
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int filtrarCompromissos(void)
{
    FILE* fp;
    Compromissos* task;
    int dia, mes, achou;

    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe uma data:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    getchar();
    printf("Mes: ");
    scanf("%d", &mes);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    task = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((fread(task, sizeof(Compromissos), 1, fp)))
    {        
        if (((task->dia == dia) && (task->mes == mes)) && (task->status == 'T'))
        {
            exibeCompromisso(task);
            achou = 1;
        }        
    }
    fclose(fp);
    if (achou)
    {
        return 0;
    }
    else 
    {
        printf("\nNao existem compromissos na data %d/%d", dia, mes);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(task);   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int filtrarAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    int dia, mes, achou;

    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe uma data:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    getchar();
    printf("Mes: ");
    scanf("%d", &mes);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    warning = (Avisos*) malloc(sizeof(Avisos));
    achou = 0;
    while((fread(warning, sizeof(Avisos), 1, fp)))
    {        
        if (((warning->dia == dia) && (warning->mes == mes)) && (warning->status == 'T'))
        {
            exibeAviso(warning);
            achou = 1;
        }        
    }
    fclose(fp);
    if (achou)
    {
        return 0;
    }
    else 
    {
        printf("\nNao existem avisos na data %d/%d", dia, mes);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(warning);   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}