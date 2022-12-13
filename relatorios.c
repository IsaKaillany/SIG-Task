#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "usuarios.h"
#include "compromissos.h"
#include "avisos.h"


void navegacaoRelatorios(void)
{
    char opcao;
    
    do
    {
        opcao = telaRelatorios();
        switch (opcao)
        {
        case '1':
            navRelatoriosUsu();
            break;
        case '2':
            navRelatoriosComp();
            break;
        case '3':
            navRelatoriosAvisos();
            break;
        }
    } while (opcao != '0');
}

char telaRelatorios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-    R E L A T O R I O S    -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Relatorios de Usuarios\n");
    printf("\t2 - Relatorios de Compromissos\n");
    printf("\t3 - Relatorios de Avisos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navRelatoriosUsu(void)
{
    char opcao;
    NoUsuario* lista;
    do
    {
        opcao = relatoriosUsuarios();
        switch (opcao)
        {
        case '1':
            listaUsuario();
            break;
        case '2':
            filtrarUsuarios();
            break;
        case '3':
            lista = listaOrdenadaUsu();
            exibeOrdemUsuario(lista);
            break;
        }
    } while (opcao != '0');
}

char relatoriosUsuarios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Listar todos\n");
    printf("\t2 - Listar por cargo\n");
    printf("\t3 - Listar em ordem alfabetica\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navRelatoriosComp(void)
{
    char opcao;
    do
    {
        opcao = relatoriosCompromissos();
        switch (opcao)
        {
        case '1':
            listaCompromissos();
            break;
        case '2':
            filtrarCompromissos();
            break;
        }
    } while (opcao != '0');
}

char relatoriosCompromissos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Listar todos\n");
    printf("\t2 - Listar por data\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navRelatoriosAvisos(void)
{
    char opcao;
    do
    {
        opcao = relatoriosAvisos();
        switch (opcao)
        {
        case '1':
            listaAvisos();
            break;
        case '2':
            filtrarAvisos();
            break;
        }
    } while (opcao != '0');
}

char relatoriosAvisos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Listar todos\n");
    printf("\t2 - Listar por data\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int filtrarUsuarios(void)
{
    FILE* fp;
    Usuarios* usu;
    int listcargo, listdepart, achou;

    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Selecione o Cargo:\n");
    listcargo = escolhaCargo();
    if (listcargo == 2)
    {
        listdepart = departamentoUsuario();
    }
    // printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    achou = 0;
    while((fread(usu, sizeof(Usuarios), 1, fp)))
    {        
        if (((usu->cargo == listcargo)) && (usu->status == 'T'))
        {
            if ((usu->cargo == 1) && (listcargo == 1))
            {
                exibeUsuario(usu);
            }
            else if (((usu->cargo == 2) && (listcargo == 2)) && (usu->departamento == listdepart))
            {
                exibeUsuario(usu);
            }
            else
            {
                printf("\nNAO HA USUARIOS CADASTRADOS COM ESSAS INFORMACOES!!!\n");
                printf("\n>>> Tecle ENTER para continuar");
                getchar();
            }
            
            achou = 1;
        }        
    }
    fclose(fp);
    if (achou)
    {
        return 0;
    }
    else 
    {
        printf("\nERRO 404!!!");
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(usu);   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int filtrarCompromissos(void)
{
    FILE* fp;
    Compromissos* task;
    int dia, mes, achou;

    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe uma data:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    getchar();
    printf("Mes: ");
    scanf("%d", &mes);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    task = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((fread(task, sizeof(Compromissos), 1, fp)))
    {        
        if (((task->dia == dia) && (task->mes == mes)) && (task->status == 'T'))
        {
            exibeCompromisso(task);
            achou = 1;
        }        
    }
    fclose(fp);
    if (achou)
    {
        return 0;
    }
    else 
    {
        printf("\nNao existem compromissos na data %d/%d", dia, mes);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(task);   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int filtrarAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    int dia, mes, achou;

    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    L I S T A G E M    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe uma data:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    getchar();
    printf("Mes: ");
    scanf("%d", &mes);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    warning = (Avisos*) malloc(sizeof(Avisos));
    achou = 0;
    while((fread(warning, sizeof(Avisos), 1, fp)))
    {        
        if (((warning->dia == dia) && (warning->mes == mes)) && (warning->status == 'T'))
        {
            exibeAviso(warning);
            achou = 1;
        }        
    }
    fclose(fp);
    if (achou)
    {
        return 0;
    }
    else 
    {
        printf("\nNao existem avisos na data %d/%d", dia, mes);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(warning);   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

NoUsuario* listaOrdenadaUsu(void)
{
    FILE* fp;
    Usuarios* usu;
    NoUsuario* novoUsuario;
    NoUsuario* lista;

    lista = NULL;
    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    usu = (Usuarios*) malloc(sizeof(Usuarios));
    while(fread(usu, sizeof(Usuarios), 1, fp)) 
    {        
        if (usu->status == 'T') 
        {
            novoUsuario = (NoUsuario*) malloc(sizeof(NoUsuario));
            strcpy(novoUsuario->nome, usu->nome);
            strcpy(novoUsuario->email, usu->email);
            strcpy(novoUsuario->senha, usu->senha);
            strcpy(novoUsuario->telefone, usu->telefone);
            strcpy(novoUsuario->id, usu->id);
            novoUsuario->cargo = usu->cargo;
            novoUsuario->departamento = usu->departamento;
            novoUsuario->status = usu->status;

            if (lista == NULL)
            {
                lista = novoUsuario;
                novoUsuario->prox = NULL;
            }
            else if (strcmp(novoUsuario->nome, lista->nome) < 0)
            {
                novoUsuario->prox = lista;
                lista = novoUsuario;
            }
            else
            {
                NoUsuario* anter = lista;
                NoUsuario* atual = lista->prox;
                while ((atual != NULL) && strcmp(atual->nome, novoUsuario->nome) < 0)
                {
                    anter = atual;
                    atual = atual->prox;
                }
                anter->prox = novoUsuario;
                novoUsuario->prox = atual;
            }           
        }
    }
    fclose(fp);
    free(usu);
    return lista;
}

void exibeOrdemUsuario(NoUsuario* lista)
{
    while (lista != NULL)
    {    
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
        printf("Nome: %s\n", lista->nome);
        printf("E-mail: %s\n", lista->email);
        printf("Telefone: %s\n", lista->telefone);
        printf("Id: %s\n", lista->id);
        if (lista->cargo == 1)
        {
            printf("Cargo: Gerencia");
        }
        else
        {
            if (lista->departamento == 1)
            {
                printf("Cargo: Funcionario(a) do Departamento Administrativo");
            }
            else if (lista->departamento == 2)
            {
                printf("Cargo: Funcionario(a) do Departamento Comercial");
            }
            else
            {
                printf("Cargo: Funcionario(a) do Departamento Tecnico");
            }           
        } 
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");  
        getchar(); //Precisa do getchar, pois sem ele aparece e some rapidamente 
        lista = lista->prox;
    }
}