#include <stdio.h>
#include <stdlib.h>
#include "compromissos.h"
#include "avisos.h"
#include "validacoes.h"

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
    Avisos* warning;
    warning = (Avisos*) malloc(sizeof(Avisos));
    // char codigo;

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
    //Criar código
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();

    gravaAviso(warning);
    free(warning);
    
}

void gravaAviso(Avisos* warning)
{
    FILE* fp;
    fp = fopen("aviso.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    fwrite(warning, sizeof(Avisos), 1, fp);
    fclose(fp);
}

void buscarAvisos(void)
{
    FILE* fp;
    Avisos* warning;
    char diaBusca[3], mesBusca[3];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nDia [dd]: ");
    scanf(" %[0-9/]", diaBusca);
    getchar();
    printf("\nMes [mm]: ");
    scanf(" %[0-9/]", mesBusca);
    getchar();


    warning = (Avisos*) malloc(sizeof(Avisos));
    fp = fopen("aviso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    while(!feof(fp)) 
    {
        fread(warning, sizeof(Avisos), 1, fp);
        if ((warning->dia == diaBusca) && (warning->mes == mesBusca)) 
        {
            fclose(fp);
        
        }
    }
    fclose(fp);
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
    do
    {
        printf("Senha: ");
        scanf(" %s", senha);
        getchar(); 
    } while(validaSenha(senha));   
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
    scanf(" %c", &opcao);
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
    do
    {
        printf("Senha: ");
        scanf(" %s", senha);
        getchar(); 
    } while(validaSenha(senha));   
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}