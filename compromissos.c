#include <stdio.h>
#include <stdlib.h>
#include "compromissos.h"


void navegacaoCrudCompromissos(void)
{
    char opcao;
    do
    {
        opcao = crudCompromissos();
        switch (opcao)
        {
        case '1':
            cadastroCompromissos();
            break;
        case '2':
            buscarCompromissos();
            break;
        case '3':
            atualizarCompromissos();
            break;
        case '4':
            deletarCompromissos();
            break;
        }
    } while (opcao != '0');
}

char crudCompromissos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Compromisso\n");
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

// Tirar setor, chamar a função escolhaDepartamento na variavel depart, tirar o vetor de depart
void cadastroCompromissos(void)
{
    char titulo[20], descri[250], data[10], hora[10];
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
    printf("Horario [00:00]: ");
    scanf("%[0-9:]", hora);
    // Criar código juntando a data e a hora e mostrar no final
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
}


void buscarCompromissos(void)
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

void atualizarCompromissos(void)
{
    char codigo[10], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    //  printf("\nMostrar os compromissos da data informada")
    printf("Codigo: ");
    scanf("%[0-9]", codigo);
    getchar();
    oqueAtualizarCompromissos(); //Colocar depois em uma váriavel resp(char)
    // printf("%c", resp);
    // Para confirmar a atualização usar a senha (E vai mudar de lugar)
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

char oqueAtualizarCompromissos(void)
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
    printf("\t5 - Hora\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

void deletarCompromissos(void)
{
    char codigo[10], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    //  printf("\nMostrar os comprimissos da data informada")
    printf("Codigo: ");
    scanf("%[0-9]", codigo);
    getchar();
    //Senha para confirmação
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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