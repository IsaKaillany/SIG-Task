#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "compromissos.h"


void moduloUsuarios(void)
{
    char opcao;        
    do
    {
        opcao = telaUsuarios();
        switch (opcao)
        {
            case '1':
                cadastroUsuario();
                break;
            case '2':
                buscarUsuario();
                break;
            case '3':
                atualizarUsuario();
                break;
            case '4':
                deletarUsuario();
                break;
            case '5':
                navegacaoUsuariosCadastrados();
                break;
        }           
    } while (opcao != '0');
}

void navegacaoUsuariosCadastrados(void)
{
    char opcao;        
    do
    {
        opcao = departamentoUsuario();
        switch (opcao)
        {
            case '1':
                usuariosCadastrados();
                break;
            case '2':
                usuariosCadastrados();
                break;
            case '3':
                usuariosCadastrados();
                break;
        }           
    } while (opcao != '0');
}

char telaUsuarios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    U S U A R I O S    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Usuario\n");
    printf("\t2 - Buscar Dados\n");
    printf("\t3 - Atualizar Dados\n");
    printf("\t4 - Deletar Dados\n");
    printf("\t5 - Listagem de Usuarios\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


void cadastroUsuario(void)
{
    char nome[30], email[30], senha[10], telefone[12], id[6];
    int cargo, depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar();
    printf("E-mail: ");
    scanf("%[A-Za-z0-9@.]", email);
    getchar();
    printf("Telefone [999999-9999]: ");
    scanf("%[0-9]", telefone);
    getchar();
    printf("Cargo:\n");
    cargo = escolhaCargo();
    if (cargo == 2)
    {
        depart = escolhaDepartamento();
    }    
    //Por enquanto vai ser manual (Colocar o depart no final do id, posteriormente)
    printf("ID: ");
    scanf("%[0-9]", id);
    getchar();
    printf("Senha [8 digitos]: ");
    scanf("%[0-9]", senha);
    getchar();    
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();

}

int escolhaCargo(void)
{
    int cargo;
    // system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Gerencia\n");
    printf("\t2 - Funcionario\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%d", &cargo);
    getchar();

    return cargo;
}

void buscarUsuario(void)
{
    char id[6];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    B U S C A R    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf("%[0-9]", id);
    getchar();
    // Printar o usuário com o ID informado
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}

void atualizarUsuario(void)
{
    char id[6];
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-     A T U A L I Z A R     -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf("%[0-9]", id);
    getchar();
    oqueAtualizarUsuario();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}     


char oqueAtualizarUsuario(void)
{    
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-     A T U A L I Z A R     -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Tudo\n");
    printf("\t2 - Nome\n");
    printf("\t3 - Senha\n");
    printf("\t4 - E-mail\n");
    printf("\t5 - Telefone\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

void deletarUsuario(void)
{
    char id[6], senha[10];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf("%[0-9]", id);
    getchar();
    //Senha para confirmação antes de deletar
    printf("Senha: ");
    scanf("%[0-9]", senha);
    getchar();
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");   

}

char departamentoUsuario(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-     U S U A R I O S  C A D A S T R A D O S    -=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Departamento Administrativo\n");
    printf("\t2 - Departamento Comercial\n");
    printf("\t3 - Departamento Tecnico\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

void usuariosCadastrados(void)
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-     U S U A R I O S  C A D A S T R A D O S    -=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Em desenvolvimento...");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    getchar();
}