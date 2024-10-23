#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

int RowCounter(char * filename){
  FILE * file;
  file = fopen(filename, "r");
  int c = 0;
  char ch;
  while ((ch = getc(file)) != EOF){
    if (ch == '\n')
    {
      c++;
    }
  }
  fclose(file);
  return c;
}

void loadCredentials(Credential * credenciais){
  FILE * file;
  file = fopen("usuarios.txt", "r");

  char servico[40];
  char login[40];
  char senha[40];

  int i = 0;
  while (fscanf(file, "%s %s %s", servico, login, senha) != EOF){
    strcpy(credenciais[i].servico, servico);
    strcpy(credenciais[i].email, login);
    strcpy(credenciais[i].password, senha);
    i++;
  }
}