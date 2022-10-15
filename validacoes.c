#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Se o tamanho for menor que 10
Se não tiver "@" e "."
Se não tiver pelo menos 3 caracteres antes do "@"
Se tiver mais de um "@" e mais de um "."*/
int validaEmail(char email[])
{
    // char email[50] = {"isa@gmail.com"};
    int tam = strlen(email), i;
    int arroba = 0, ponto = 0, valid = 0;
    
    
    for (i = 0; i < tam; i++)
    {
        char c = email[i];
        if ((email[0] == '@') || (email[1] == '@') || (email[2] == '@'))
        {
          printf("E-mail Inválido!");
          return 1;
        }
      

        if ((email[0] == '.') || (email[1] == '.') || (email[2] == '.'))
        {
          printf("E-mail Inválido!");
          return 1;
        }



        if (c == '@')
        {
            arroba++;
        }


        if (c == '.')
        {
            ponto++;
        }



    }


    if ((tam > 8) && (arroba == 1 && ponto == 1))
    {
    //   printf("E-mail Válido!");  
      return 0;
    }
    
    
    else
    {
      printf("E-mail Inválido!");
      return 1;
      
    }

}





int validaSenha(char senha[])
{
  int tam = strlen(senha);
  int digito = 0, letra = 0;
  
  if (tam != 8) //verifica o tamanho
  {
    return 1;    
  }
  else
  {
    for (int i = 0; i < tam; i++) 
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
    if ((digito == 0) || (letra == 0))
    {
      return 1;
    }
  } 
  return 0;
}



int validaNome(char nome[])
{
  char tam = strlen(nome);
  int letra = 0, espaco = 0;
  
  if (tam < 2) //verifica o tamanho
  {
    return 1;
  }
  else
  {
    for (int i = 0; i < tam; i++)
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
        else
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



int validaSenha(char senha[])
{
  int tam = strlen(senha);
  int digito = 0, letra = 0;
  
  if (tam != 8) //verifica o tamanho
  {
    return 1;    
  }
  else
  {
    for (int i = 0; i < tam; i++) 
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
        else
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