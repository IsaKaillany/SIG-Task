#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compromissos.h"
#include "validacoes.h"
#include "usuarios.h"


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

void cadastroCompromissos(void)
{
    int codigoAux;
    char codigoString[10];
    Compromissos* task;

    task = (Compromissos*) malloc(sizeof(Compromissos));

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTitulo: ");
    scanf(" %99[^\n]", task->titulo);
    getchar();
    printf("Descricao: ");
    scanf(" %999[^\n]", task->descricao);
    getchar();
    do
    {
        printf("Dia [dd]: ");
        scanf(" %d", &task->dia);
        getchar();
        printf("Mes [mm]: ");
        scanf(" %d", &task->mes);
        getchar();
    } while (validaData(anoAtual(), task->dia, task->mes));
    do
    {
        printf("Hora [00]: ");
        scanf(" %d", &task->hora);
        getchar();
        printf("Minutos [00]: ");
        scanf(" %d", &task->min);
        getchar();
    } while(validaHora(task->hora, task->min));

    printf("Departamento:\n");
    task->departamento = escolhaDepartamento(); 
    
    printf("\nID do funcionario: ");
    scanf(" %7[^\n]", task->id);
    getchar();
    task->status = 'T';

    //Código
    codigoAux = geraCodigoComp();
    itoa(codigoAux, codigoString, 10); //Transforma int em char
    strcpy(task->codigo, codigoString);
    printf("Codigo do compromisso: %s", codigoString);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
    
    gravaCompromisso(task);
    free(task);
}

void buscarCompromissos(void) 
{
    FILE* fp;
    Compromissos* task;
    char codigoBusca[10]; 
    int achou;

    fp = fopen("compromisso.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("Informe o codigo: ");
    scanf(" %9[^\n]", codigoBusca);
    getchar();

    task = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((!achou) && (fread(task, sizeof(Compromissos), 1, fp)))
    {        
        if ((strcmp(task->codigo, codigoBusca) == 0) && (task->status == 'T'))
        {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou)
    {
        exibeCompromisso(task);
    }
    else
    {
        printf("O compromisso de codigo '%s' nao foi encontrado\n", codigoBusca);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(task);     
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarCompromissos(void)
{
    FILE* fp;
    // Usuarios* usu;
    Compromissos* task;
    int achou;
    char resp;
    char codigoBusca[10]; 
    // char senhaUpd[9];

    fp = fopen("compromisso.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo do Compromisso: ");
    scanf(" %9[^\n]", codigoBusca);
    getchar();
    task = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((!achou) && (fread(task, sizeof(Compromissos), 1, fp))) 
    {
        if ((strcmp(task->codigo, codigoBusca) == 0) && (task->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeCompromisso(task);
        resp = oqueAtualizarCompromissos(); 
        printf("\n");
        if (resp == '1')
        {
            printf("Titulo: ");
            scanf(" %99[^\n]", task->titulo);
            getchar();
            printf("Descricao: ");
            scanf(" %999[^\n]", task->descricao);
            getchar();
            do
            {
                printf("Dia [dd]: ");
                scanf(" %d", &task->dia);
                getchar();
                printf("Mes [mm]: ");
                scanf(" %d", &task->mes);
                getchar();
            } while (validaData(anoAtual(), task->dia, task->mes));
            do
            {
                printf("Hora [00]: ");
                scanf(" %d", &task->hora);
                getchar();
                printf("Minuto [00]: ");
                scanf(" %d", &task->min);
                getchar();
            } while (validaHora(task->hora, task->min));
            
        }
        else if (resp == '2')
        {
            printf("\nTitulo: ");
            scanf(" %99[^\n]", task->titulo);
            getchar();
        }
        else if (resp == '3')
        {
            printf("Descricao: ");
            scanf(" %999[^\n]", task->descricao);
            getchar();
        }
        else if (resp == '4')
        {
            do
            {
                printf("Dia [dd]: ");
                scanf(" %d", &task->dia);
                getchar();
                printf("Mes [mm]: ");
                scanf(" %d", &task->mes);
                getchar();
            } while (validaData(anoAtual(), task->dia, task->mes));
        }
        else if (resp == '5')
        {
            do
            {
                printf("Hora [00]: ");
                scanf(" %d", &task->hora);
                getchar();
                printf("Minuto [00]: ");
                scanf(" %d", &task->min);
                getchar();
            } while (validaHora(task->hora, task->min));
        }
        task->status = 'T';      
        fseek(fp, (-1)*sizeof(Compromissos), SEEK_CUR);
        fwrite(task, sizeof(Compromissos), 1, fp);
        printf("\nAtualizacao concluida com sucesso");

        // usu = (Usuarios*) malloc(sizeof(Usuarios));
        // printf("\nConfirme sua senha: ");
        // scanf(" %s", senhaUpd);
        // getchar(); 

        // if ((strcmp(usu->senha, senhaUpd) == 0))
        // {
        //     task->status = 'T';      
        //     fseek(fp, (-1)*sizeof(Compromissos), SEEK_CUR);
        //     fwrite(task, sizeof(Compromissos), 1, fp);
        //     printf("Atualizacao concluida com sucesso");
        // }
        // else
        // {
        //     printf("Senha incorreta!");
        // }
    }    
    else
    {
        printf("O compromisso, de codigo '%s', nao foi encontrado!\n", codigoBusca);
    }
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n>>> Tecle ENTER para continuar");
    getchar();
    // free(usu);
    free(task);
    fclose(fp);
}

char oqueAtualizarCompromissos(void)
{
    char opcao;
    // system("clear||cls");
    printf("O que voce deseja atualizar?\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Tudo\n");
    printf("\t2 - Titulo\n");
    printf("\t3 - Descricao\n");
    printf("\t4 - Data\n");
    printf("\t5 - Hora\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deletarCompromissos(void)
{
    FILE* fp;
    Compromissos* comp;
    int achou;
    char codigoBusca[10], resp;

    fp = fopen("compromisso.dat", "r+b");
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
    printf("\nCodigo: ");
    scanf(" %[0-9]", codigoBusca);
    getchar();

    comp = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((!achou) && (fread(comp, sizeof(Compromissos), 1, fp))) 
    {
        if ((strcmp(comp->codigo, codigoBusca) == 0) && (comp->status == 'T')) 
        {
            achou = 1;
        }
    }
    if (achou)
    {
        exibeCompromisso(comp);
        printf("Deseja realmente apagar este compromisso [S/N]? ");
        scanf("%c", &resp);
        getchar();
        if (resp == 'S' || resp == 's')
        {
            comp->status = 'F';
            fseek(fp, (-1)*sizeof(Compromissos), SEEK_CUR);
            fwrite(comp, sizeof(Compromissos), 1, fp);       
            printf("\nCompromisso excluido com sucesso!\n");
        }
        else
        {
            printf("\nDados nao foram alterados\n");
        }
    }
    else
    {
        printf("\nO compromisso de codigo '%s' nao foi encontrado\n", codigoBusca);
    }  
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Tecle ENTER para continuar");
    getchar();
    free(comp);
    fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    scanf(" %d", &opcao);
    getchar();

    return opcao;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void gravaCompromisso(Compromissos* task)
{
    FILE* fp;
    fp = fopen("compromisso.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    fwrite(task, sizeof(Compromissos), 1, fp);
    fclose(fp);
}

//Depois ver como fazer para conseguir listar os compromissos de um único departamento
void exibeCompromisso(Compromissos* task)
{
    if (task == NULL) 
    {
        printf("\n= = = Compromisso não cadastrado = = =\n");
    }
    else 
    {
        printf("\n");
        printf("Titulo: %s\n", task->titulo);
        printf("Descricao: %s\n", task->descricao);
        printf("Data: %d/%d\n", task->dia, task->mes);
        printf("Horario: %d:%.2d\n", task->hora, task->min);
        printf("Codigo: %s\n", task->codigo);
        printf("ID: %s\n", task->id);
        if (task->departamento == 1)
        {
            printf("Departamento: Administrativo");
        }
        else if (task->departamento == 2)
        {
            printf("Departamento: Comercial");
        }
        else
        {
            printf("Departamento: Tecnico");
        }           
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  
        getchar(); //Precisa do getchar, pois sem ele aparece e some rapidamente
    }
}
