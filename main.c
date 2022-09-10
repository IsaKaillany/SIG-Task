#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Manipulação de caracteres
#include <string.h> //Manipulação de strings
#include <unistd.h>


// Assinatura das funções
char telaPrincipal(void);
void telaInfo(void);
char telaUsuarios(void);
char telaAtividades(void);
// char telaCompromissos(void);
char telaAgenda(void);
// char telaGerencia(void);
// char telaAvisos(void);


int main(void)
{
    char tela;
    tela = telaPrincipal();
    switch (tela)
    {
        case '1':
            telaUsuarios();
            break;
        case '2':
            telaAtividades();
            break;
        case '3':
            telaAgenda();
            break;
        case '4':
            telaInfo();
            break;
        case '0':
            printf("Fim do programa!");
            break;
        default:
            printf("Por favor insira uma opcao valida\n");
            break;
    }   
    return 0;
}



char telaPrincipal(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    S I G - T a s k    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Usuarios\n");
    printf("\t2 - Atividades\n");
    printf("\t3 - Agenda\n");
    printf("\t4 - Informacoes\n");
    printf("\t0 - Finalizar\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
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
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

char telaAtividades(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-    A T I V I D A D E S    -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Gerentes\n");
    printf("\t2 - Diretores\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

void telaInfo(void)
{
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("       Universidade Federal do Rio Grande do Norte       \n");
    printf("           Centro de Ensino Superior do Serido           \n"); 
    printf("         Departamento de Computacao e Tecnologia         \n");
    printf("            Disciplina DCT1106 -- Programacao            \n");
    printf("              Docente: Dr. Flavius Gorgonio              \n");
    printf("        Projeto: Agenda de Tarefas e Compromissos        \n");
    printf("                   Since August, 2022                    \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-    D E V E L O P E R S    -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("> Felipe Souza Benicio da Silva\n");
    printf("> Matricula: 20220043343\n");
    printf("> Isa Kaillany Soares Pereira\n"); 
    printf("> Matricula: 20220043568\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    O B J E T I V O    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("O presente projeto tem como objetivo desenvolver um \n");
    printf("programa de computador que realize o agendamento de \n"); 
    printf("tarefas de forma eficiente, fornecendo lembretes aos \n");
    printf("usuarios sobre compromissos agendados.");                                                                                                                                     
}

// char telaCompromissos(void)
// {
//     char opcao;
//     system("clear||cls");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("\t1 - Cadastrar Compromisso\n");
//     printf("\t2 - Buscar\n");
//     printf("\t3 - Atualizar\n");
//     printf("\t4 - Deletar\n");
//     printf("\t0 - Voltar ao menu\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf(">>> Opcao ");
//     scanf("%c", &opcao);

//     return opcao;
// }


char telaAgenda(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Departamento Administrativo\n");
    printf("\t2 - Departamento Comercial\n");
    printf("\t3 - Departamento Tecnico\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);
    getchar();

    return opcao;
}

// char telaGerencia(void)
// {
//     char opcao;
//     system("clear||cls");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-=-=-    G E R E N C I A    -=-=-=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("\t1 - Avisos\n");
//     printf("\t2 - Compromissos\n");
//     printf("\t0 - Voltar ao menu\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf(">>> Opcao ");
//     scanf("%c", &opcao);

//     return opcao;
// }

// char telaAvisos(void)
// {
//     char opcao;
//     system("clear||cls");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-=-=-=-    A V I S O S    -=-=-=-=-=-=-=-=-=-\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf("\t1 - Cadastrar Avisos\n");
//     printf("\t2 - Buscar\n");
//     printf("\t3 - Atualizar\n");
//     printf("\t4 - Deletar\n");
//     printf("\t0 - Voltar ao menu\n");
//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
//     printf(">>> Opcao ");
//     scanf("%c", &opcao);

//     return opcao;
// }