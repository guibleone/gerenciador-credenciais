#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

void userRegister(User *user, FILE *registro)
{
  if (user == NULL)
  {
    fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
    exit(EXIT_FAILURE);
  }

  printf("------Cadastro de Usuário------\n");
  printf("Digite seu email: ");

  if (fgets(user->email, sizeof(user->email), stdin) == NULL)
  {
    fprintf(stderr, "Erro: Falha ao ler o email.\n");
    exit(EXIT_FAILURE);
  }
  user->email[strcspn(user->email, "\n")] = '\0';

  printf("Digite sua senha: ");
  if (fgets(user->password, sizeof(user->password), stdin) == NULL)
  {
    fprintf(stderr, "Erro: Falha ao ler a senha.\n");
    exit(EXIT_FAILURE);
  }
  user->password[strcspn(user->password, "\n")] = '\0';

  fprintf(registro, "%s %s\n", user->email, user->password);

  printf("Usuário registrado com sucesso!\n");
}

void printUser(User *user)
{
  printf("Email: %s\n", user->email);
  printf("Senha: %s\n", user->password);
}