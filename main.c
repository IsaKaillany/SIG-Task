#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Manipulação de caracteres
#include <string.h> //Manipulação de strings
#include <unistd.h>


// Assinatura das funções
char telaPrincipal(void);
void telaInfo(void);
char telaUsuarios(void);
char telaCompromissos(void);
char telaAgenda(void);
char telaGerencia(void);
char telaAvisos(void);


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
            telaCompromissos();
            break;
        case '3':
            telaAgenda();
            break;
        case '4':
            telaGerencia();            
            break;
        case '5':
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
    printf("\t2 - Compromissos\n");
    printf("\t3 - Agenda\n");
    printf("\t4 - Gerencia\n");
    printf("\t5 - Informacoes\n");
    printf("\t0 - Finalizar\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

    return opcao;
}

char telaUsuarios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    U S U A R I O S    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Selecionar Usuario\n");
    printf("\t2 - Cadastrar Usuario\n");
    printf("\t3 - Atualizar\n");
    printf("\t4 - Deletar\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

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

char telaCompromissos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-    C O M P R O M I S S O S    -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Compromisso\n");
    printf("\t2 - Buscar\n");
    printf("\t3 - Atualizar\n");
    printf("\t4 - Deletar\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

    return opcao;
}


char telaAgenda(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-    A G E N D A    -=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Listar Compromissos\n");
    printf("\t2 - Compromissos Gerenciais\n");
    printf("\t3 - Compromissos de Trabalho\n");
    printf("\t4 - Compromissos Pessoais\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

    return opcao;
}

char telaGerencia(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-    G E R E N C I A    -=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Avisos\n");
    printf("\t2 - Compromissos\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

    return opcao;
}

char telaAvisos(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-          A V I S O S          -=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t1 - Cadastrar Avisos\n");
    printf("\t2 - Buscar\n");
    printf("\t3 - Atualizar\n");
    printf("\t4 - Deletar\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf("%c", &opcao);

    return opcao;
}