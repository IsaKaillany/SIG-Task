#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "avisos.h"
#include "agenda.h"
#include "perfil.h"


void moduloPerfil(void)
{
    char id[7];
    
    do
    {
        telaPerfil(id);
        if (strcmp(id,"881234") == 0)
        {
            navegacaoPerfilGerencia();
        }
        if (strcmp(id,"991234") == 0)
        {
            navegacaoPerfilFuncionarios();
        }
    } while (strcmp(id, "0") != 0);
}

void navegacaoPerfilGerencia(void)
{
    char opcao;
    do
    {
        opcao = telaPerfilGerencia();
        switch (opcao)
        {
            case '1':
                navegacaoCrudCompromissos();
                break;
            case '2':
                navegacaoCrudAvisos();
                break;
            case '3':
                navegacaoAgendaGerencia();
                break;
        }   
    } while (opcao != '0');
}

void navegacaoPerfilFuncionarios(void)
{
    char opcao;
    do
    {
        opcao = telaPerfilFuncionarios();
        switch (opcao)
        {
            case '1':
                navegacaoCrudCompromissos();
                break;
            case '2':
                navegacaoAgendaFuncionarios();
                break;
        }   
    } while (opcao != '0');
}



void telaPerfil(char id[])
{
    char senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    P E R F I L    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf("%s", id);
    getchar();
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char telaPerfilGerencia(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    G E R E N C I A    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Compromissos\n");
    printf("\t2 - Avisos\n");
    printf("\t3 - Agenda\n");
    printf("\t\ta - Por Departamento\n");
    printf("\t\tb - Por Codigo\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

char telaPerfilFuncionarios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    F U N C I O N A R I O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Compromisso\n");
    printf("\t2 - Agenda\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}