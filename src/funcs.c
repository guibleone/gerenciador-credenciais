#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manipulate_io.h"
#include "types.h"
#include "aux_funcs.h"


void userRegister(User *user, FILE *registro)
{
  if (user == NULL)
  {
    fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
    exit(EXIT_FAILURE);
  }

  printf("------Cadastro de Usuário------\n");
  readUser(user);
  UserCriptographed userCripto;
  userCripto.email = toCriptograph(user->email);
  userCripto.password = toCriptograph(user->password);

  for (int i = 0; i < 32; i++)
    fprintf(registro, "%02x", userCripto.email[i]);
  // fprintf(registro, " ");
  for (int i = 0; i < 32; i++)
    fprintf(registro, "%02x", userCripto.password[i]);
  fprintf(registro, "\n");
  printf("Usuário registrado com sucesso!\n");
}

void printUser(User *user)
{
  printf("Email: %s\n", user->email);
  printf("Senha: %s\n", user->password);
}

void searchUser(User *user, FILE *registro){
  readUser(user);
  UserCriptographed searchedUser;
  searchedUser.email = toCriptograph(user->email);
  searchedUser.password = toCriptograph(user->password);
  // unsigned char * teste = toCriptograph(user->email);
  UserCriptographedArray * ListHashs = getRegistersOnFile(registro);
  
  // getRegistersOnFile(&ListHashs,registro);
  printf("Tamanho: %d\n",ListHashs->size);
  for (int i = 0; i < ListHashs->size; i++) {
    printf("User[%d]:%s ",i,ListHashs->UsersCriptographed[i].email);
    printf("Senha[%d]:%s ",i,ListHashs->UsersCriptographed[i].password);
  }
  
  // if(compareUnsignedChar(teste, , 32)) {
  //   printf("Encontrado Usuário");
  // }
  free(ListHashs->UsersCriptographed);
}
void updateUser(User *user, FILE *registro){
  readUser(user);

}
void deleteUser(User *user, FILE *registro){
  readUser(user);

}