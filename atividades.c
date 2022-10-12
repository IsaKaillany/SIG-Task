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


/////////////////////////////////////////////////////////////////////////////////////////////////


char crudAvisos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Avisos\n");
    printf("\t2 - Buscar Dados\n");
    printf("\t3 - Atualizar Dados\n");
    printf("\t4 - Deletar Dados\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


void cadastroAvisos(void)
{
    char titulo[20], descri[250], data[10];
    // int depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Titulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    printf("Departamento:\n");
    escolhaDepartamento(); //Colocar depois na variável depart 
    printf("Descricao: ");
    scanf("%[A-Z a-z]", descri);
    getchar();
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
}

void buscarAvisos(void)
{
    char data[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarAvisos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data: ");
    scanf("%[0-9/]", data);
    getchar();
    //  printf("\nMostrar os avisos da data informada")
    printf("Titulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    oqueAtualizarAvisos(); //Colocar depois numa variavel resp(char)
    //Senha para confirmar a atualização
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

char oqueAtualizarAvisos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-     A T U A L I Z A R     -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Tudo\n");
    printf("\t2 - Titulo\n");
    printf("\t3 - Descricao\n");
    printf("\t4 - Data\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

void deletarAvisos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data: ");
    scanf("%[0-9/]", data);
    getchar();
    //  printf("\nMostrar os avisos da data informada")
    printf("Titulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    //Senha para confirmação
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
