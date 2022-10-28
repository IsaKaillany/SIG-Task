#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "compromissos.h"
#include "validacoes.h"


void moduloUsuarios(void)
{
    Usuarios* funcionario;
    char opcao;        
    do
    {
        opcao = telaUsuarios();
        switch (opcao)
        {
            case '1':
                funcionario = cadastroUsuario();
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
                usuariosCadastrados(funcionario);
                break;
        }           
    } while (opcao != '0');
    free(funcionario);
}

// void navegacaoUsuariosCadastrados(void)
// {
//     char opcao;        
//     do
//     {
//         opcao = departamentoUsuario();
//         switch (opcao)
//         {
//             case '1':
//                 usuariosCadastrados();
//                 break;
//             case '2':
//                 usuariosCadastrados();
//                 break;
//             case '3':
//                 usuariosCadastrados();
//                 break;
//         }           
//     } while (opcao != '0');
// }

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


Usuarios* cadastroUsuario()
{
    Usuarios* usu;
    usu = (Usuarios*) malloc(sizeof(Usuarios));
    int cargo, depart;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do
    {
        printf("Nome: "); //Buga se der espaço
        scanf(" %49[^\n]", usu->nome);
        getchar();
    } while(validaNome(usu->nome));  
    do
    {
        printf("E-mail: ");
        scanf(" %49[^\n]", usu->email);
        getchar();
    } while(validaEmail(usu->email));
    do
    {
        printf("Telefone [00999999999]: ");
        scanf(" %11[^\n]", usu->telefone);
        getchar();
    } while(validaTelefone(usu->telefone));

    printf("Cargo:\n");
    cargo = escolhaCargo();
    if (cargo == 2)
    {
        depart = escolhaDepartamento();
    }    
    //Por enquanto vai ser manual (Colocar o depart no final do id, posteriormente)
    printf("ID [6 digitos]: ");
    scanf(" %[0-9]", usu->id);
    getchar();

    do
    {
        printf("Senha [letras e numeros [tamanho 8]]: ");
        scanf(" %s", usu->senha);
        getchar(); 
    } while(validaSenha(usu->senha));   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();

    return usu;
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
    scanf(" %d", &cargo);
    getchar();

    return cargo;
}

void buscarUsuario(void)
{
    char id[7];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    B U S C A R    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf(" %[0-9]", id);
    getchar();
    // Printar o usuário com o ID informado
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}

void atualizarUsuario(void)
{
    char id[7];
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-     A T U A L I Z A R     -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf(" %[0-9]", id);
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
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

void deletarUsuario(void)
{
    char id[7], senha[9];
    int validadorSenha;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nID: ");
    scanf(" %[0-9]", id);
    getchar();
    //Senha para confirmação antes de deletar
    do
    {
        printf("Senha [8 digitos]: ");
        scanf("%s", senha);
        getchar(); 
        validadorSenha = validaSenha(senha);
    } while(validadorSenha != 0);   
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

void usuariosCadastrados(const Usuarios* func)
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-     U S U A R I O S  C A D A S T R A D O S    -=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Em desenvolvimento...\n");
    printf("Nome: %s\n", func->nome);
    printf("E-mail: %s\n", func->email);
    printf("Telefone: %s\n", func->telefone);
    printf("Id: %s\n", func->id);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    getchar();
}