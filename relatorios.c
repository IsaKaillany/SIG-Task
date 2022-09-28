#include <stdio.h>
#include <stdlib.h>

char telaRelatorios(void)
{
    char opcao;
    system("clear||cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-    R E L A T O R I O S    -=-=-=-=-=-=-=-\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");    
    printf("\t1 - Relatorio dos Usuarios\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}