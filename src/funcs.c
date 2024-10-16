#include <stdio.h>
#include <stdlib.h>

#include "types.h"

void userRegister(User *user)
{
  if (user == NULL)
  {
    fprintf(stderr, "Erro ao cadastrar usuário.");
    exit(EXIT_FAILURE);
  }

  FILE *arq = fopen("usuarios.txt", "a+");
  if (arq == NULL)
  {
    fprintf(stderr, "Erro ao abrir arquivo de registro de usuários.");
    exit(EXIT_FAILURE);
  }

  printf("------Cadastro de Usuário------\n");
  printf("Digite seu email: ");
  scanf("%s", user->email);

  printf("Digite sua senha: ");
  scanf("%s", user->password);

  fprintf(arq, "%s %s\n", user->email, user->password);
  fclose(arq);
}

void printUser(User *user)
{
  printf("Email: %s\n", user->email);
  printf("Senha: %s\n", user->password);
}