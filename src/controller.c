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

  fprintf(file, "%s", service);
  fprintf(file, " ");
  fprintf(file, "%s", login);
  fprintf(file, " ");
  fprintf(file, "%s", password);
  fprintf(file, "\n");
}

void searchByService(char * service){
  int c = RowCounter("usuarios.txt");
  int found = 0;
  Credential * credenciais = (Credential*)malloc(sizeof(Credential) * c);

  loadCredentials(credenciais);

  printf("%s%20s%20s%15s\n","ID", "Serviço", "Login", "Senha");
  for (int i = 0; i < c; i++){
    if (!strcmp(credenciais[i].service, service)){
      found = 1;
      printf("%d%20s%20s%15s\n", i, credenciais[i].service, credenciais[i].login, credenciais[i].password);
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

  printf("%s%20s%20s%15s\n","ID", "Serviço", "Login", "Senha");
  for (int i = 0; i < c; i++){
    printf("%d%20s%20s%15s\n", i, credenciais[i].service, credenciais[i].login, credenciais[i].password);
  }
}

void deleteCredential(int id){
  int c = RowCounter("usuarios.txt");
  Credential * credenciais = (Credential*)malloc(sizeof(Credential) * c);

  loadCredentials(credenciais);

  FILE * file;
  file = fopen("usuarios.txt", "w");

  for (int i = 0; i < c; i++){
    if (i != id){
      fprintf(file, "%s", credenciais[i].service);
      fprintf(file, " ");
      fprintf(file, "%s", credenciais[i].login);
      fprintf(file, " ");
      fprintf(file, "%s", credenciais[i].password);
      fprintf(file, "\n");
    }
  }

  fclose(file);
}
