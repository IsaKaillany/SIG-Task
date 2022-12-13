#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "avisos.h"
#include "validacoes.h"
#include "usuarios.h"

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cadastroAvisos(void)
{
    int codigoAux;
    char codigoString[6];
    Avisos* warning;

    warning = (Avisos*) malloc(sizeof(Avisos));

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTitulo: ");
    scanf(" %99[^\n]", warning->titulo);
    getchar();
    printf("Descricao: ");
    scanf(" %999[^\n]", warning->descricao);
    getchar();
    do
    {
        printf("Dia [dd]: ");
        scanf(" %d", &warning->dia);
        getchar();
        printf("Mes [mm]: ");
        scanf(" %d", &warning->mes);
        getchar();
    } while (validaData(anoAtual(), warning->dia, warning->mes));
    
    printf("Departamento:\n");
    warning->departamento = escolhaDepartamento(); 
    warning->status = 'T';

    //Código
    codigoAux = geraCodigoAviso();
    sprintf(codigoString, "%d", codigoAux); //Transforma int em char
    strcpy(warning->codigo, codigoString);
    printf("\nCodigo do aviso: %s", codigoString);

    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();

    gravaAviso(warning);
    free(warning);
    
}

int buscarAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    char codigoBusca[6]; //dia+mes+departamento
    int achou; 

    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe o codigo: ");
    scanf(" %5[0-9]", codigoBusca);
    getchar();

    warning = (Avisos*) malloc(sizeof(Avisos));
    achou = 0;
    while((!achou) && (fread(warning, sizeof(Avisos), 1, fp))) 
    {        
        if ((strcmp(warning->codigo, codigoBusca) == 0) && (warning->status == 'T'))
        {
            achou = 1;   
        }
    }
    fclose(fp);
    if (achou)
    {
        exibeAviso(warning);
    }
    else
    {
        printf("O aviso de codigo = %s nao foi encontrado\n", codigoBusca);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(warning);     
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
    return 0;
}

int atualizarAvisos(void)
{
    FILE* fp;
    // Usuarios* usu;
    Avisos* warning;
    int achou;
    char resp;
    char codigoBusca[6];
    // char senhaUpd[9];

    fp = fopen("aviso.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nInforme o codigo: ");
    scanf(" %6[^\n]", codigoBusca);
    getchar();
    warning = (Avisos*) malloc(sizeof(Avisos));
    achou = 0;
    while((!achou) && (fread(warning, sizeof(Avisos), 1, fp))) 
    {
        if ((strcmp(warning->codigo, codigoBusca) == 0) && (warning->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeAviso(warning);
        resp = oqueAtualizarAvisos(); 
        printf("\n");
        if (resp == '1')
        {
            printf("Titulo: ");
            scanf(" %99[^\n]", warning->titulo);
            getchar();
            printf("Descricao: ");
            scanf(" %999[^\n]", warning->descricao);
            getchar();
            do
            {
                printf("Dia [dd]: ");
                scanf(" %d", &warning->dia);
                getchar();
                printf("Mes [mm]: ");
                scanf(" %d", &warning->mes);
                getchar();
            } while (validaData(anoAtual(), warning->dia, warning->mes));
            
        }
        else if (resp == '2')
        {
            printf("\nTitulo: ");
            scanf(" %99[^\n]", warning->titulo);
            getchar();
        }
        else if (resp == '3')
        {
            printf("Descricao: ");
            scanf(" %999[^\n]", warning->descricao);
            getchar();
        }
        else if (resp == '4')
        {
            do
            {
                printf("Dia [dd]: ");
                scanf(" %d", &warning->dia);
                getchar();
                printf("Mes [mm]: ");
                scanf(" %d", &warning->mes);
                getchar();
            } while (validaData(anoAtual(), warning->dia, warning->mes));
        }

        // usu = (Usuarios*) malloc(sizeof(Usuarios));
        // printf("Confirme sua senha: ");
        // scanf(" %s", senhaUpd);
        // getchar(); 

        // if ((strcmp(usu->senha, senhaUpd) == 0))
        // {
        //     warning->status = 'T';      
        //     fseek(fp, (-1)*sizeof(Avisos), SEEK_CUR);
        //     fwrite(warning, sizeof(Avisos), 1, fp);
        //     printf("Atualizacao concluida com sucesso");
        // }
        // else
        // {
        //     printf("Senha incorreta!");
        // }
    }    
    else
    {
        printf("O aviso de codigo '%s' nao foi encontrado\n", codigoBusca);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n>>> Tecle ENTER para continuar");
    getchar();
    // free(usu);
    free(warning);
    fclose(fp);
    return 0;
}

char oqueAtualizarAvisos(void)
{
    char opcao;
    // system("clear||cls");
    printf("O que voce deseja atualizar?\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Tudo\n");
    printf("\t2 - Titulo\n");
    printf("\t3 - Descricao\n");
    printf("\t4 - Data\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int deletarAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    int achou;
    char codigoBusca[6], resp;

    fp = fopen("aviso.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo: ");
    scanf(" %s", codigoBusca);
    getchar();

    warning = (Avisos*) malloc(sizeof(Avisos));
    achou = 0;
    while((!achou) && (fread(warning, sizeof(Avisos), 1, fp))) 
    {
        if ((strcmp(warning->codigo, codigoBusca) == 0) && (warning->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeAviso(warning);
        printf("Deseja realmente apagar este aviso [S/N]? ");
        scanf("%c", &resp);
        getchar();
        if (resp == 'S' || resp == 's')
        {
            warning->status = 'F';
            fseek(fp, (-1)*sizeof(Avisos), SEEK_CUR);
            fwrite(warning, sizeof(Avisos), 1, fp);       
            printf("\nAviso excluido com sucesso!\n");
        }
        else
        {
            printf("\nDados nao foram alterados\n");
        }
    }
    else
    {
        printf("\nO aviso de codigo '%s' nao foi encontrado\n", codigoBusca);
    }  
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Tecle ENTER para continuar");
    getchar();
    free(warning);
    fclose(fp);
    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int gravaAviso(Avisos* warning)
{
    FILE* fp;
    fp = fopen("aviso.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    fwrite(warning, sizeof(Avisos), 1, fp);
    fclose(fp);
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void exibeAviso(Avisos* warning)
{
    if (warning == NULL) 
    {
        printf("\n= = = Aviso não cadastrado = = =\n");
    }
    else 
    {
        printf("\n");
        printf("Titulo: %s\n", warning->titulo);
        printf("Descricao: %s\n", warning->descricao);
        printf("Data: %d/%d\n", warning->dia, warning->mes);
        printf("Codigo: %s\n", warning->codigo);
        if (warning->departamento == 1)
        {
            printf("Departamento: Administrativo");
        }
        else if (warning->departamento == 2)
        {
            printf("Departamento: Comercial");
        }
        else
        {
            printf("Departamento: Tecnico");
        }           
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");  
        getchar(); //Precisa do getchar, pois sem ele aparece e some rapidamente
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int listaAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-   A V I S O S  C A D A S T R A D O S  -=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); 
    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        return 0;
    }
    while (fread(warning, sizeof(Avisos), 1, fp)) 
    {
        if (warning->status != 'F') 
        {
            exibeAviso(warning);
        }
    }
    fclose(fp);
    free(warning);
    return 0;
}
