#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "avisos.h"
#include "agenda.h"
#include "perfil.h"
#include "usuarios.h"


void moduloPerfil(void) //Só funciona com o primeiro Usuario do arquivo
{
    FILE* fp;
    Usuarios* usu;
    int achou;
    char idIn[7], senhaIn[9];

    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;

    while((!achou) && (fread(usu, sizeof(Usuarios), 1, fp)))
    {
        do
        {
            telaPerfil(idIn, senhaIn);
            if ((strcmp(usu->id, idIn) == 0) && (strcmp(usu->senha, senhaIn) == 0) && (usu->status == 'T')) 
            {
                if ((idIn[0] == '1') && (idIn[1] == '1')) //Se iniciar com 11 = gerencia 
                {
                    navegacaoPerfilGerencia();
                    achou = 1;
                }
                else if ((idIn[0] == '2') && (idIn[1] == '2')) //Se iniciar com 22 = funcionario 
                {
                    navegacaoPerfilFuncionarios();
                    achou = 1;
                }
            }
        } while (strcmp(idIn, "0") != 0);
    }
    fclose(fp);
    free(usu); 
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
            // case '2':
            //     navegacaoAgendaFuncionarios();
            //     break;
        }   
    } while (opcao != '0');
}



void telaPerfil(char id[])
{
    char senha[9];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    P E R F I L    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID [0 para voltar]: ");
    scanf(" %s", id);
    getchar();
    if (strcmp(id, "0") != 0)
    {
        printf("Senha: ");
        scanf(" %s", senha);
        getchar();
    }      
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
    printf("\t\ta - Departamento\n");
    printf("\t\tb - Funcionario\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
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
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}