#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "avisos.h"
#include "compromissos.h"

void moduloAgenda(void)
{
    char opcao[3];  
    do
    {
        telaAgenda(opcao);
        if ((strcmp(opcao, "1a") == 0))
        {
            compromissosAdm();
        }
        else if ((strcmp(opcao, "2a") == 0))
        {
            compromissosComercial();
        }
        else if ((strcmp(opcao, "3a") == 0))
        {
            compromissosTec();
        }      
        
        else if ((strcmp(opcao, "1b") == 0))
        {
            avisosAdm();
        }
        else if ((strcmp(opcao, "2b") == 0))
        {
            avisosComercial();
        }
        else if ((strcmp(opcao, "3b") == 0))
        {
            avisosTec();
        }      
    } while (strcmp(opcao, "0") != 0);
}

void navegacaoAgendaGerencia(void)
{
    char opcao;
    printf(">> Letra ");
    scanf(" %c", &opcao);
    getchar();
    if (opcao == 'a')
    {
      moduloAgenda();
    }
    else if (opcao == 'b')
    {
      agendaGerenciaCodigo();
    }
}

void navegacaoAgendaFuncionarios(char idIn[])
{
    char opcao;
    do
    {
        opcao = agendaFuncionario(idIn);
        switch (opcao)
        {
            case '1':
                agendaCompromissoFunc(idIn);
                break;
            case '2':
                agendaAvisoFunc(idIn);
                break;
        }   
    } while (opcao != '0');
}


void agendaGerenciaCodigo(void)
{
    FILE* fp;
    Compromissos* task;
    char codigoBusca[10];
    
    task = (Compromissos*) malloc(sizeof(Compromissos));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID do Funcionario: ");
    scanf(" %[0-9]", codigoBusca);
    getchar();
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(task, sizeof(Compromissos), 1, fp)) 
    {
        if ((strcmp(codigoBusca, task->id) == 0) && (task->status == 'T'))
        {
            exibeCompromisso(task);
        }
    } 
    fclose(fp);
    free(task); 
}

void telaAgenda(char opcao[])
{    
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t>>> Departamento Administrativo\n");
    printf("\t\t1a - Compromissos\n");
    printf("\t\t1b - Avisos\n");
    printf("\t>>> Departamento Comercial\n");
    printf("\t\t2a - Compromissos\n");
    printf("\t\t2b - Avisos\n");
    printf("\t>>> Departamento Tecnico\n");
    printf("\t\t3a - Compromissos\n");
    printf("\t\t3b - Avisos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %s", opcao);
    getchar();
}

char agendaFuncionario(char idIn[])
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Compromissos\n");
    printf("\t2 - Avisos\n");
    printf("\t0 - Voltar a tela anterior\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

void compromissosAdm(void)
{
    FILE* fp;
    Compromissos* task;

    task = (Compromissos*) malloc(sizeof(Compromissos));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(task, sizeof(Compromissos), 1, fp)) 
    {
        if ((task->departamento == 1) && (task->status == 'T'))
        {
            exibeCompromisso(task);
        }            
    } 
    fclose(fp);
    free(task);  
}

void compromissosComercial(void)
{
    FILE* fp;
    Compromissos* task;

    task = (Compromissos*) malloc(sizeof(Compromissos));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(task, sizeof(Compromissos), 1, fp)) 
    {
        if ((task->departamento == 2) && (task->status == 'T'))
        {
            exibeCompromisso(task);
        }

    } 
    fclose(fp);
    free(task);   
}

void compromissosTec(void)
{
    FILE* fp;
    Compromissos* task;

    task = (Compromissos*) malloc(sizeof(Compromissos));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(task, sizeof(Compromissos), 1, fp)) 
    {
        if ((task->departamento == 3) && (task->status == 'T'))
        {
            exibeCompromisso(task);
        }

    } 
    fclose(fp);         
    free(task);     
}   

void avisosAdm(void)
{
    FILE* fp;
    Avisos* warning;

    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(warning, sizeof(Avisos), 1, fp)) 
    {
        if ((warning->departamento == 1) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }            
    } 
    fclose(fp);
    free(warning);  
}

void avisosComercial(void)
{
    FILE* fp;
    Avisos* warning;

    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(warning, sizeof(Avisos), 1, fp)) 
    {
        if ((warning->departamento == 2) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }            
    } 
    fclose(fp);
    free(warning);
}

void avisosTec(void)
{
    FILE* fp;
    Avisos* warning;

    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(warning, sizeof(Avisos), 1, fp)) 
    {
        if ((warning->departamento == 3) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }            
    } 
    fclose(fp);
    free(warning);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void agendaAvisoFunc(char idIn[])
{
    FILE* fp;
    Avisos* warning;


    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(warning, sizeof(Avisos), 1, fp)) 
    {
        if (((idIn[2] == '1') && (warning->departamento == 1)) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }
        else if (((idIn[2] == '2') && (warning->departamento == 2)) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }
        else if (((idIn[2] == '3') && (warning->departamento == 3)) && (warning->status == 'T'))
        {
            exibeAviso(warning);
        }
    } 
    fclose(fp);
    free(warning);
}

void agendaCompromissoFunc(char idIn[])
{
    FILE* fp;
    Compromissos* task;
    
    task = (Compromissos*) malloc(sizeof(Compromissos));
    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    while (fread(task, sizeof(Compromissos), 1, fp)) 
    {
        if ((strcmp(idIn, task->id) == 0) && (task->status == 'T'))
        {
            exibeCompromisso(task);
        }
    } 
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTecle ENTER para continuar");
    getchar();
    fclose(fp);
    free(task);
}

