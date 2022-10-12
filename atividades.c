#include <stdio.h>
#include <stdlib.h>
#include "atividades.h"
#include "usuarios.h"

void moduloAtividades(void)
{
    char opcao;
    telaPerfil();
    do
    {
        opcao = telaGerenciaAtividades();
        switch (opcao)
        {
        case '1':
            navegacaoCrudCompromissos();
            break;
        case '2':
            navegacaoCrudAvisos();
            break;
        }
    } while (opcao != '0');
}




/*
1º Perguntar se tem cadastro (S/N)
2º Se S = Login e senha
3º Se N = Chamar o cadastroUsuarios();
*/
void telaPerfil(void)
{
    char login[30], senha[10];
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    P E R F I L    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Login: ");
    scanf("%[A-Z a-z]", login);
    getchar();
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

char telaGerenciaAtividades(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    G E R E N C I A    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Compromissos\n");
    printf("\t2 - Avisos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

int escolhaDepartamento(void)
{
    int opcao;
    // system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Departamento Administrativo\n");
    printf("\t2 - Departamento Comercial\n");
    printf("\t3 - Departamento Tecnico\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%d", &opcao);
    getchar();

    return opcao;
}


