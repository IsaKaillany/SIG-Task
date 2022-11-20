#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"
#include <time.h>
#include "usuarios.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
> O tamanho do email precisa ser maior que 8
> Precisa ter no mínimo 9 letras
> O @ e o . não podem aparecer nos 3 primeiros caracteres
> Não pode ter mais de um "@" e mais de um "."
> Não pode ter caracteres especiais
> Precisa ter apenas um @ e um .
> O ponto só aparece na colocação 3 após o @
*/
int validaEmail(char email[])
{
    int tam = strlen(email), i, letra = 0;
    int arroba = 0, ponto = 0, lugarponto = 0, lugararroba = 0;
    
    for (i = 0; i < tam; i++)
    {
        char c = email[i];
        if ((email[0] == '@') || (email[1] == '@') || (email[2] == '@'))
        {
          return 1;
        }      
        if ((email[0] == '.') || (email[1] == '.') || (email[2] == '.'))
        {
          return 1;
        }        
        if (c == '@')
        {
            arroba++;
            lugararroba = i;
        }
        if (c == '.')
        {
            ponto++;
            lugarponto = i;
        }
        if (isalpha(c))
        {
          letra++;
        }
        if (c == '&' || c == '=' || c == '_' || c == '"' || c == '+' || c == '-' || 
            c == ',' || (c == '<') || c == '>' || c == '[' || c == ']')
        {
          return 1;          
        }
    }
    if ((tam > 8 && letra > 8) && (arroba == 1 && ponto == 1) && (lugararroba+2 < lugarponto))
    {
      return 0;
    }    
    else
    {
      return 1;
    }
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int validaNome(char nome[])
{
  int tam = strlen(nome);
  int letra = 0, espaco = 0, i;
  
  if (tam <= 2) //verifica o tamanho
  {
    return 1;
  }
  else
  {
    for (i = 0; i < tam; i++)
      {
        char c = nome[i];
        
        if (isalpha(c)) //verifica se é letra
        {
          letra++;
        }
        else if (c == ' ') //verifica se é espaço
        {
          espaco++;
        }          
        else //verifica se não é espaço nem letra
        {
          return 1;
        }
      }
    if (letra == 0)
    {
      return 1;
    }
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validaSenha(char senha[])
{
  int tam = strlen(senha);
  int digito = 0, letra = 0, i;
  
  if (tam != 8) //verifica o tamanho
  {
    return 1;    
  }
  else
  {
    for (i = 0; i < tam; i++) 
      {
        char c = senha[i];
        
        if (isdigit(c)) //verifica se é dígito
        {
          digito++;
        }
        else if (isalpha(c)) //verifica se é letra
        {
          letra++;
        }
        else //verifica se não é digito nem letra
        {
          return 1;
        }
       
      }
    if ((digito == 0) || (letra == 0)) //verifica se tem letra e dígito
    {
      return 1;
    }
  }
return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validaTelefone(char telefone[])
{
  int tam = strlen(telefone);
  int digito = 0, i; 
  
  if (tam != 11) //verifica o tamanho
  {
    return 1;
  }
  else
  {
    for (i = 0; i < tam; i++)
      {
        char c = telefone[i];
  
        if (isdigit(c)) //verifica se é dígito
        {
          digito++;
        }
        else
        {
          return 1;
        }
      }
    if (digito == 0) //verifica se tem dígito
    {
      return 1;
    }
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validaHora(int hora, int min)
{

  if ((hora < 0 || hora > 23) || (min < 0 || min > 59)) //Se a hora ou os minutos não estiverem de acordo com esse padrão, é inválido
  {
    return 1;      
  }
  else
  {
    return 0;
  }    

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int anoAtual(void) //by https://www.clubedohardware.com.br/forums/topic/1273224-retornar-o-ano-atual-no-sistema-e-exibir-na-tela-em-c/
{
    int anoAtual; //Esta variável foi criada para receber o resultado do comando que exibe o ano atual.
    time_t data_ano; //Foi criada uma variável chamada data_ano que é do tipo time_t que é um tipo de variável que recebe valores de data e hora.
    time(&data_ano);
  
    struct tm *data = localtime(&data_ano);

    anoAtual = (data->tm_year+1900);    

    return anoAtual;
}

int validaData(int anoAtual, int dia, int mes)
{
  if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12))
  {
    if (mes == 2) // fevereiro
    {
      if (((anoAtual % 4 == 0) && (anoAtual % 100 != 0)) || (anoAtual % 400 == 0))  // ano bissexto
      {
        if (dia >= 30)
        {
          return 1;
        }
      } 
      else
      {
        if (dia >= 29)
        {
          return 1;
        }
      }
    }
    else if ((dia >= 32) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 ||
              mes == 10 || mes == 12)) // meses com 31 dias
    {
      return 1;
    }
    else if ((dia >= 31) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) // meses com 30 dias
    {
      return 1;
    }
    return 0;
  }
  else
  {
    return 1;    
  }  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validaID(char idAux[]) 
{
    FILE* fp;
    Usuarios* usu;
    // int achou;
    
    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        printf("(X-X)/\n");
        exit(1);
    }
    usu = (Usuarios*) malloc(sizeof(Usuarios));
    while((fread(usu, sizeof(Usuarios), 1, fp))) 
    {        
        if ((strcmp(usu->id, idAux) == 0) && (usu->status == 'T')) 
        {
            fclose(fp);
            free(usu);
            return 1;
        }
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int geraID(int cargo, int departamento) 
{
    int number;

    if (cargo == 1)
    {
        srand(time(NULL));
        number = 1100000 + rand()%9999999; //Sorteando um valor entre 1100000 e 9999999
    }
    else
    {
        srand(time(NULL));
        if (departamento == 1)
        {
            number = 2210000 + rand()%9999999; //Sorteando um valor entre 2210000 e 9999999
        }
        else if (departamento == 2)
        {
            // srand(time(NULL));
            number = 2220000 + rand()%9999999; //Sorteando um valor entre 2220000 e 9999999
        }
        else
        {
            // srand(time(NULL));
            number = 2230000 + rand()%9999999; //Sorteando um valor entre 2230000 e 9999999
        }
    }
    return number;    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int geraCodigoComp(void) //gerador de código (tam = 9)
{
    int number;

    srand(time(NULL));
    number = 202200000 + rand()%999999999; //Sorteando um valor entre 202200000 e 999999999

    return number;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int geraCodigoAviso(void) //gerador de código (tam = 5)
{
    int number;

    srand(time(NULL));
    number = 10000 + rand()%99999; //Sorteando um valor entre 20220 e 99999

    return number;
}