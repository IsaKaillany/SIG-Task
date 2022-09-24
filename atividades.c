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
            crudCompromissos();
            break;
        case '2':
            crudAvisos();
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
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    P E R F I L    -=-=-=-=-=-=-=-=-=-\n");
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

char escolhaDepartamento(void)
{
    int opcao;
    system("clear||cls");
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
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

//Tirar setor, chamar a função escolhaDepartamento na variavel depart, tirar o vetor de depart
int cadastroCompromissos(void)
{
    char titulo[20], depart[20], setor[10], descri[250], data[10], hora[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    printf("\nDepartamento: ");
    scanf("%[A-Z a-z]", depart);
    printf("\nSetor: ");
    scanf("%[A-Z a-z]", setor);
    printf("\nDescrição: ");
    scanf("%s", descri);
    printf("\nData: ");
    scanf("%[0-9/]", data);
    printf("\nHorário: ");
    scanf("%[min0-9:h]", hora);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    return 0;
}

int buscarCompromissos(void)
{
    char data[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
}

int atualizarCompromissos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
//  printf("\nMostrar os comprimissos da data informada")
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    // Após colocar o título e escolher qual compromisso quer atualizar, aparecerá o que ele quer atualizar...tudo, data, hora...etc
    printf("\n");
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
}


int deletarCompromissos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
//  printf("\nMostrar os comprimissos da data informada")
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    printf("\n");
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
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
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

//Tirar setor, chamar a função escolhaDepartamento na variavel depart, tirar o vetor de depart
int cadastroAvisos(void)
{
    char titulo[20], depart[20], setor[10], descri[200];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    printf("\nDepartamento: ");
    scanf("%[A-Z a-z]", depart);
    printf("\nSetor: ");
    scanf("%[A-Z a-z]", setor);
    printf("\nDescrição: ");
    scanf("%s", descri);
    // Terá uma opção perguntando quanto tempo o usuário deseja que o aviso fique agendado
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    return 0;
}


int buscarAvisos(void)
{
    char data[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
}


int atualizarAvisos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
//  printf("\nMostrar os avisos da data informada")
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    // Após colocar o título e escolher qual aviso quer atualizar, aparecerá o que ele quer atualizar...tudo, data, hora...etc
    printf("\n");
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
}

int deletarAvisos(void)
{
    char titulo[20], data[10], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\nData: ");
    scanf("%[0-9/]", data);
//  printf("\nMostrar os avisos da data informada")
    printf("\nTítulo: ");
    scanf("%[A-Z a-z]", titulo);
    printf("\n");
    printf("\nSenha: ");
    scanf("%[0-9]", senha);
    printf("\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    

    return 0;
}
