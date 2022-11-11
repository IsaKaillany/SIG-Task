#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

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

void navegacaoAgendaFuncionarios(void)
{
    char opcao;
    do
    {
        opcao = agendaFuncionario();
        switch (opcao)
        {
            case '1':
                mostragemAgendaCompromissos();
                break;
            case '2':
                mostragemAgendaAvisos();
                break;
        }   
    } while (opcao != '0');
}


void agendaGerenciaCodigo(void)
{
    char codigo[10];
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo [9 digitos]: ");
    scanf(" %[0-9]", codigo);
    getchar();
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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

char agendaFuncionario(void)
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

void mostragemAgendaCompromissos(void)
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    getchar();
}

void mostragemAgendaAvisos(void)
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    getchar();
}


