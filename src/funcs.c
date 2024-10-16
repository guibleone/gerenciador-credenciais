#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manipulate_io.h"
#include "types.h"

void readUser (User *user) {
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
}

void userRegister(User *user, FILE *registro)
{
  if (user == NULL)
  {
    fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
    exit(EXIT_FAILURE);
  }

  printf("------Cadastro de Usuário------\n");
  readUser(user);
  
  // fprintf(registro, "%02x %02x\n", toCriptograph(user->email), toCriptograph(user->password));

  printf("Usuário registrado com sucesso!\n");
}

void printUser(User *user)
{
  printf("Email: %s\n", user->email);
  printf("Senha: %s\n", user->password);
}

void searchUser(User *user, FILE *registro){
  readUser(user);
  unsigned char * teste = toCriptograph(user->email);
  
  // if(compareUnsignedChar(teste, , 32)) {
  //   printf("Encontrado Usuário");
  // }
}
void updateUser(User *user, FILE *registro){
  readUser(user);

}
void deleteUser(User *user, FILE *registro){
  readUser(user);

}