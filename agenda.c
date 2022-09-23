#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

void moduloAgenda(void)
{
    char opcao;
    while (opcao != '0')
    {
      opcao = telaAgenda();
      if ((opcao == '1') || (opcao == '2') || (opcao == '3'))
      {
        mostragemAgendaCompromissos();
      }
      if ((opcao == '4') || (opcao == '5') || (opcao == '6'))
      {
        mostragemAgendaAvisos();
      }
    } 
}

char telaAgenda(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t>>> Departamento Administrativo\n");
    printf("\t\t1A - Compromissos\n");
    printf("\t\t4B - Avisos\n");
    printf("\t>>> Departamento Comercial\n");
    printf("\t\t2A - Compromissos\n");
    printf("\t\t5B - Avisos\n");
    printf("\t>>> Departamento Tecnico\n");
    printf("\t\t3A - Compromissos\n");
    printf("\t\t6B - Avisos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
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


