#include <stdio.h>
#include <stdlib.h>
#include "compromissos.h"
#include "avisos.h"

void navegacaoCrudAvisos(void)
{
    char opcao;
    do
    {
        opcao = crudAvisos();
        switch (opcao)
        {
        case '1':
            cadastroAvisos();
            break;
        case '2':
            buscarAvisos();
            break;
        case '3':
            atualizarAvisos();
            break;
        case '4':
            deletarAvisos();
            break;
        }
    } while (opcao != '0');
}


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
    char titulo[100], descri[1000], data[6];
    // char codigo;
    int depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTitulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    printf("Descricao: ");
    scanf("%[A-Z a-z]", descri);
    getchar();
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("Departamento:\n");
    depart = escolhaDepartamento(); 
    //Criar código
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
}

void buscarAvisos(void)
{
    char data[6];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nData [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarAvisos(void)
{
    char senha[9], resp;
    // char codigo;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo: ");
    // scanf("%[0-9]", codigo);
    getchar();
    resp = oqueAtualizarAvisos(); 
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
    char senha[9];
    // char codigo;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo: ");
    // scanf("%[0-9]", codigo);
    getchar();
    //Senha para confirmação
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}