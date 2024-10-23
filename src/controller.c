#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "aux_funcs.h"

void userRegister(char * service, char * login, char * password){
  FILE * file;
  file = fopen("usuarios.txt", "a+");
  if (file == NULL){
    fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < strlen(service); i++)
    fprintf(file, "%c", service[i]);
  fprintf(file, " ");
  for (int i = 0; i < strlen(login); i++)
    fprintf(file, "%c", login[i]);
  fprintf(file, " ");
  for (int i = 0; i < strlen(password); i++)
    fprintf(file, "%c", password[i]);
  fprintf(file, "\n");
}

void searchByService(char * service){
  int c = RowCounter("usuarios.txt");
  int found = 0;
  Credential * credenciais = (Credential*)malloc(sizeof(Credential) * c);

  loadCredentials(credenciais);

  printf("%s%15s%15s\n", "Serviço", "Login", "Senha");
  for (int i = 0; i < c; i++){
    if (!strcmp(credenciais[i].servico, service)){
      found = 1;
      printf("%s%15s%15s\n", credenciais[i].servico, credenciais[i].email, credenciais[i].password);
    }
  }

  if (!found) {
    printf("Nenhum registro encontrado\n");
  }

}

void getAll(){
  int c = RowCounter("usuarios.txt");
  Credential * credenciais = (Credential*)malloc(sizeof(Credential) * c);

  loadCredentials(credenciais);

  printf("%s%15s%15s\n", "Serviço", "Login", "Senha");
  for (int i = 0; i < c; i++){
    printf("%s%15s%15s\n", credenciais[i].servico, credenciais[i].email, credenciais[i].password);
  }
}
