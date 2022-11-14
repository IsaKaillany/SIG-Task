#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "compromissos.h"
#include "validacoes.h"


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
                listaUsuario();
                break;
            // case '6':
            //     break;
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
    printf("\t6 - Listagem de Usuarios por Departamento\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


void cadastroUsuario(void)
{
    Usuarios* usu;
    usu = (Usuarios*) malloc(sizeof(Usuarios));
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    do
    {
        printf("Nome: ");
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
    usu->cargo = escolhaCargo();
    // if (usu->cargo == 1)
    // {
    //     usu->id = '00';
    // }    
    if (usu->cargo == 2)
    {
        usu->departamento = escolhaDepartamento();
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
    usu->status = 'T';
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();

    gravaUsuario(usu);
    free(usu);
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
    FILE* fp;
    Usuarios* usu;
    int achou;
    char idBusca[7];
    
    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    B U S C A R    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");   
    printf("Informe o ID: "); 
    scanf(" %[0-9]", idBusca);
    getchar();

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;
    while((!achou) && (fread(usu, sizeof(Usuarios), 1, fp))) 
    {        
        if ((strcmp(usu->id, idBusca) == 0) && (usu->status == 'T')) 
        {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou)
    {
        exibeUsuario(usu);
    }
    else
    {
        printf("O funcionario de id = %s nao foi encontrado\n", idBusca);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(usu); 
}

void atualizarUsuario(void)
{
    FILE* fp;
    Usuarios* usu;
    int achou;
    char resp;
    char idBusca[7];
    // char senhaAntiga[9];

    fp = fopen("usuario.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-     A T U A L I Z A R     -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe o ID: ");
    scanf(" %[0-9]", idBusca);
    getchar();

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;
    while((!achou) && (fread(usu, sizeof(Usuarios), 1, fp))) 
    {
        if ((strcmp(usu->id, idBusca) == 0) && (usu->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeUsuario(usu);
        resp = oqueAtualizarUsuario();
        printf("\n");
        if (resp == '1')
        {
            do
            {
                printf("Nome: ");
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
            do
            {
                printf("Senha [letras e numeros [tamanho 8]]: ");
                scanf(" %s", usu->senha);
                getchar(); 
            } while(validaSenha(usu->senha));  
        }
        else if (resp == '2')
        {
            do
            {
                printf("Nome: ");
                scanf(" %49[^\n]", usu->nome);
                getchar();
            } while(validaNome(usu->nome));  
        }
        else if (resp == '3')
        {
            do
            {
                printf("E-mail: ");
                scanf(" %49[^\n]", usu->email);
                getchar();
            } while(validaEmail(usu->email));
        }
        else if (resp == '4')
        {
            do
            {
                printf("Telefone [00999999999]: ");
                scanf(" %11[^\n]", usu->telefone);
                getchar();
            } while(validaTelefone(usu->telefone));
        }
        // else if (resp == '5')
        // {
        //     printf("Informe a senha antiga: ");
        //     scanf(" %s", senhaAntiga);
        //     if (strcmp(usu->senha, senhaAntiga) == 0)
        //     {
        //         do
        //         {
        //             printf("Nova senha [letras e numeros (tamanho 8)]: ");
        //             scanf(" %s", usu->senha);
        //             getchar(); 
        //         } while(validaSenha(usu->senha));   
        //     }
        //     else
        //     {
        //         printf("Senha incorreta!");
        //         getchar();
        //     }           
        // }
        usu->status = 'T';      
        fseek(fp, (-1)*sizeof(Usuarios), SEEK_CUR);
        fwrite(usu, sizeof(Usuarios), 1, fp);        
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\nDados editados com sucesso!");
    }
    else 
    {
        printf("O funcionario de id = %s nao foi encontrado\n", idBusca);
    }
    printf("\n>>> Tecle ENTER para continuar");
    getchar();
    free(usu);
    fclose(fp);      
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
} 


char oqueAtualizarUsuario(void)
{    
    char opcao;
    printf("O que voce deseja atualizar?\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Tudo\n");
    printf("\t2 - Nome\n");
    printf("\t3 - E-mail\n");
    printf("\t4 - Telefone\n");
    // printf("\t5 - Senha\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deletarUsuario(void)
{
    FILE* fp;
    Usuarios* usu;
    int achou;
    char resp;
    char idBusca[7];

    fp = fopen("usuario.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe o ID: ");
    scanf(" %[0-9]", idBusca);
    getchar();
    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;

    while((!achou) && (fread(usu, sizeof(Usuarios), 1, fp))) 
    {
        if ((strcmp(usu->id, idBusca) == 0) && (usu->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeUsuario(usu);
        printf("Deseja realmente apagar este usuario [S/N]? ");
        scanf("%c", &resp);
        getchar();
        if (resp == 'S' || resp == 's')
        {
            usu->status = 'F';
            fseek(fp, (-1)*sizeof(Usuarios), SEEK_CUR);
            fwrite(usu, sizeof(Usuarios), 1, fp);       
            printf("Usuario excluido com sucesso\n\n");
        }
        else
        {
            printf("Dados nao foram alterados\n\n");
        }
    }
    else
    {
        printf("O usuario de id = %s nao foi encontrado\n\n", idBusca);
    } 
    printf(">>> Tecle ENTER para continuar");
    getchar();
    free(usu);
    fclose(fp);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gravaUsuario(Usuarios* usu)
{
    FILE* fp;
    fp = fopen("usuario.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    fwrite(usu, sizeof(Usuarios), 1, fp);
    fclose(fp);
}

void exibeUsuario(Usuarios* usu)
{
    if ((usu == NULL) || (usu->status == 'F')) 
    {
        printf("\n= = = Usuario Inexistente = = =\n");
    }
    else 
    {
        printf("\n");
        printf("Nome: %s\n", usu->nome);
        printf("E-mail: %s\n", usu->email);
        printf("Telefone: %s\n", usu->telefone);
        printf("Id: %s\n", usu->id);
        if (usu->cargo == 1)
        {
            printf("Cargo: Gerencia");
        }
        else
        {
            if (usu->departamento == 1)
            {
                printf("Cargo: Funcionario(a) do Departamento Administrativo");
            }
            else if (usu->departamento == 2)
            {
                printf("Cargo: Funcionario(a) do Departamento Comercial");
            }
            else
            {
                printf("Cargo: Funcionario(a) do Departamento Tecnico");
            }           
        }        
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
        getchar(); //Precisa do getchar, pois sem ele aparece e some rapidamente
    }
}

void listaUsuario(void) 
{
    FILE* fp;
    Usuarios* usu;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-     U S U A R I O S  C A D A S T R A D O S    -=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
    usu = (Usuarios*) malloc(sizeof(Usuarios));
    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    while (fread(usu, sizeof(Usuarios), 1, fp)) 
    {
        if (usu->status != 'F') 
        {
            exibeUsuario(usu);
        }
    }
    fclose(fp);
    free(usu);
}