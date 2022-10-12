#include <stdio.h>
#include <stdlib.h>
#include "atividades.h"
#include "usuarios.h"

void moduloAtividades(void)
{
    char opcao;
    telaPerfil();
    do
    {
        opcao = telaGerenciaAtividades();
        switch (opcao)
        {
        case '1':
            navegacaoCrudCompromissos();
            break;
        case '2':
            navegacaoCrudAvisos();
            break;
        }
    } while (opcao != '0');
}









