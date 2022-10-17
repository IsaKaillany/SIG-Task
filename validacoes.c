#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"


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
  char tam = strlen(nome);
  int letra = 0, espaco = 0, i;
  
  if (tam < 2) //verifica o tamanho
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