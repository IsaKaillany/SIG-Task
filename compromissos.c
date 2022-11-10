#include <stdio.h>
#include <stdlib.h>
#include "compromissos.h"
#include "validacoes.h"


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
    Compromissos* task;
    task = (Compromissos*) malloc(sizeof(Compromissos));
    // char codigo;

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
    
    printf("ID do funcionario: ");
    scanf(" %6[^\n]", task->id);
    getchar();
    task->status = 'T';
    // Criar código c/ data+horario+departamento
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
    
    gravaCompromisso(task);
    free(task);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

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


void buscarCompromissos(void) //falta implementar o código
{
    FILE* fp;
    Compromissos* task;
    int codigoBusca; //data+horario+departamento
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
    scanf(" %d", &codigoBusca);
    getchar();

    task = (Compromissos*) malloc(sizeof(Compromissos));
    achou = 0;
    while((!achou) && (fread(task, sizeof(Compromissos), 1, fp)))
    {        
        if ((task->codigo == codigoBusca) && (task->status == 'T'))
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
        printf("O compromisso de codigo = %d nao foi encontrado\n", codigoBusca);
        printf("\n>>> Tecle ENTER para continuar");
        getchar();
    }
    free(task);     
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarCompromissos(void)
{
    char codigo[10], senha[9], resp;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo [9 digitos]: ");
    scanf(" %[0-9]", codigo);
    getchar();
    resp = oqueAtualizarCompromissos(); 
    // printf("%c", resp);
    // Para confirmar a atualização usar a senha (E vai mudar de lugar)
    do
    {
        printf("Senha: ");
        scanf("%s", senha);
        getchar(); 
    } while(validaSenha(senha));   
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
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

void deletarCompromissos(void)
{
    char codigo[10], senha[9];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo: ");
    scanf(" %[0-9]", codigo);
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
        printf("ID: %s\n", task->id);
        printf("Departamento: %d\n", task->departamento);
        getchar(); //Precisa do getchar, pois sem ele aparece e some rapidamente
    }
}