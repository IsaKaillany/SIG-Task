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
    scanf("%s", &login);
    getchar();
    printf("Senha: ");
    scanf("%s", &senha);
    getchar();
    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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

///////////////////////////////////////////////////////////////////////////////////////////////

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
    int depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Titulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    printf("Departamento:\n");
    depart = escolhaDepartamento();
    printf("%d", depart);
    getchar();
    printf("Descricao: ");
    scanf("%s", &descri);
    getchar();
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("Horario [00:00]: ");
    scanf("%[0-9:]", hora);
    // Criar código juntando a data e a hora e mostrar no final
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarCompromissos(void)
{
    char codigo[10], data[10], senha[10], resp;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    //  printf("\nMostrar os comprimissos da data informada")
    printf("Codigo: ");
    scanf("%s", &codigo);
    getchar();
    resp = oqueAtualizarCompromissos();
    printf("%c", resp);
    // Para confirmar a atualização usar a senha (E vai mudar de lugar)
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n");
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
    scanf("%s", &codigo);
    getchar();
    printf("\n");
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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
    int depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Titulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    printf("Departamento:\n");
    depart = escolhaDepartamento();
    printf("%d", depart);
    printf("\nDescricao: ");
    scanf("%s", &descri);
    getchar();
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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
    printf("\n");
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
    // Após colocar o título e escolher qual aviso quer atualizar, aparecerá o que ele quer atualizar...tudo, data, hora...etc
    printf("\n");
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
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
    printf("\n");
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}
