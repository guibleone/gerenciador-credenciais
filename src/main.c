#include <stdlib.h>
#include <stdio.h>

#include "funcs.h"

int main(int argc, char *arcv[])
{
  User *user = (User *)malloc(sizeof(User));
  FILE *registro = fopen("usuarios.txt", "a+");
  if (registro == NULL)
  {
    fprintf(stderr, "Erro: Falha ao abrir registro de usuários.\n");
    exit(EXIT_FAILURE);
  }

  userRegister(user, registro);
  printUser(user);

  fclose(registro);
  free(user);

  return EXIT_SUCCESS;
}