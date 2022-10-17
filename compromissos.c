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

// Tirar setor, chamar a função escolhaDepartamento na variavel depart, tirar o vetor de depart
void cadastroCompromissos(void)
{
    char titulo[100], descri[1000], data[6], id[7];
    // char codigo;
    int depart, hora, min, validadorHorario;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    C A D A S T R O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nTitulo: ");
    scanf("%[A-Z a-z]", titulo);
    getchar();
    printf("Descricao: ");
    scanf("%[A-Z a-z]", descri);
    getchar();
    printf("Data [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    do
    {
        printf("Hora [00]: ");
        scanf("%d", &hora);
        getchar();
        printf("Minutos [00]: ");
        scanf("%d", &min);
        getchar();
        validadorHorario = validaHora(hora, min);
    } while(validadorHorario != 0);
    printf("Departamento:\n");
    depart = escolhaDepartamento(); 
    printf("ID do funcionario: ");
    scanf("%[0-9]", id);
    getchar();
    // Criar código juntando a data, hora e departamento p/ mostrar no final
    // codigo = data + hora + (char)depart;
    // printf("Codigo: %s", codigo);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Cadastro concluido!\n");
    printf("\nTecle ENTER para continuar");
    getchar();
}

//Mostrar o título e código da data pesquisada, depois digita o código para ver as infos completas do compromisso
void buscarCompromissos(void)
{
    char data[6];

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-      B U S C A R      -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nData [dd/mm]: ");
    scanf("%[0-9/]", data);
    getchar();
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void atualizarCompromissos(void)
{
    char codigo[10], senha[9], resp;
    int validadorSenha;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-   A T U A L I Z A R   -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo [9 digitos]: ");
    scanf("%[0-9]", codigo);
    getchar();
    resp = oqueAtualizarCompromissos(); 
    // printf("%c", resp);
    // Para confirmar a atualização usar a senha (E vai mudar de lugar)
    do
    {
        printf("Senha: ");
        scanf("%s", senha);
        getchar(); 
        validadorSenha = validaSenha(senha);
    } while(validadorSenha != 0);   
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
    char codigo[10], senha[9];
    int validadorSenha;

    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-     D E L E T A R     -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nCodigo: ");
    scanf("%[0-9]", codigo);
    getchar();
    //Senha para confirmação
    do
    {
        printf("Senha: ");
        scanf("%s", senha);
        getchar(); 
        validadorSenha = validaSenha(senha);
    } while(validadorSenha != 0);   
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
    scanf("%d", &opcao);
    getchar();

    return opcao;
}