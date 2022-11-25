#include <stdio.h>
#include <stdlib.h>

void navegacaoRelatorios(void)
{
    char opcao;
    do
    {
        opcao = telaRelatorios();
        switch (opcao)
        {
        case '1':
                
            break;
        case '2':
            
            break;
        case '3':
            
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
    printf("\t1 - Usuarios Cadastrados\n");
    printf("\t2 - Compromissos Cadastrados\n");
    printf("\t3 - Avisos Cadastrados\n");
    printf("\t0 - Voltar ao menu\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(">>> Opcao ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}
