#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "avisos.h"
#include "agenda.h"
#include "perfil.h"
#include "usuarios.h"


int moduloPerfil(void) 
{
    FILE* fp;
    Usuarios* usu;
    int achou;
    char idIn[8], senhaIn[9];

    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;
    do
    { 
        telaPerfil(idIn, senhaIn);
        while((!achou) && (fread(usu, sizeof(Usuarios), 1, fp)))
        {
            if (((strcmp(usu->id, idIn) == 0) && (strcmp(usu->senha, senhaIn) == 0)) && (usu->status == 'T')) 
            {
                
                if ((idIn[0] == '1') && (idIn[1] == '1')) //Se iniciar com 11 = gerencia 
                {
                    achou = 1;
                    navegacaoPerfilGerencia(idIn);
                }
                else if ((idIn[0] == '2') && (idIn[1] == '2')) //Se iniciar com 22 = funcionario 
                {
                    achou = 1;
                    navegacaoPerfilFuncionarios(idIn);
                }
            }
        }
        fclose(fp); 
    } while (strcmp(idIn, "0") != 0);
    free(usu);
    return 0; 
}

void navegacaoPerfilGerencia(char idIn[])
{
    char opcao;
    do
    {
        opcao = telaPerfilGerencia(idIn);
        switch (opcao)
        {
            case '1':
                navegacaoCrudCompromissos();
                break;
            case '2':
                navegacaoCrudAvisos();
                break;
            case '3':
                navegacaoAgendaGerencia(idIn);
                break;
        }   
    } while (opcao != '0');
}

void navegacaoPerfilFuncionarios(char idIn[])
{
    char opcao;
    do
    {
        opcao = telaPerfilFuncionarios(idIn);
        switch (opcao)
        {
            // case '1':
            //     navegacaoCrudCompromissos();
            //     break;
            case '1':
                navegacaoAgendaFuncionarios(idIn);
                break;
        }   
    } while (opcao != '0');
}



void telaPerfil(char idIn[], char senhaIn[]) //Só reconhece a 1ª tentativa. Precisa voltar para o menu inicial para poder logar com outra conta
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    P E R F I L    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID [0 para voltar]: ");
    scanf(" %s", idIn);
    getchar();
    if (strcmp(idIn, "0") != 0)
    {
        printf("Senha: ");
        scanf(" %s", senhaIn);
        getchar();
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char telaPerfilGerencia(char idIn[])
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

char telaPerfilFuncionarios(char idIn[])
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    F U N C I O N A R I O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    // printf("\t1 - Cadastrar Compromisso\n");
    printf("\t1 - Agenda\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}