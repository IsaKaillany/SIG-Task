#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


// Assinatura das funções
char telaPrincipal(void);
void telaInfo(void);
char telaUsuarios(void);


int main(void)
{
    char tela;
    tela = telaPrincipal();
    switch (tela)
    {
        /*case '1':
            telaUsuarios();
            break;
        case '2':
            telaCompromissos();
            break;
        case '3':
            telaAgenda();
            break;*/
        case '4':
            telaInfo();
            break;
        default:
            printf("Opcao invalida\n");
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
    printf("\t4 - Informacoes\n");
    printf("\t0 - Sair\n");
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
    printf("\t1 - Selecionar usuario\n");
    printf("\t2 - Cadastrar usuario\n");
    printf("\t3 - Atualizar\n");
    printf("\t4 - Deletar\n");
    printf("\t0 - Sair\n");
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
    printf("-=-=-=-=-=-=-=-=-=-    E Q U I P E    -=-=-=-=-=-=-=-=-=-\n");
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