#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int RowCounter(FILE *arquivo) {
  char string[132];
  int c = 0;
  while (fgets(string, sizeof(string), arquivo) != NULL) {
    c++;
  }
  return c;
}

void getRegistersOnFile (FILE * registro) {
    int count = 0;
    // UserCriptographedArray * ArrayUsers,
    char * hash = (char *) malloc(65 * sizeof(char));
    // char hash[66];
    // ArrayUsers->size = RowCounter(registro);
    // ArrayUsers->UsersCriptographed = malloc(ArrayUsers->size * sizeof(UserCriptographed)); 
    // if (ArrayUsers->UsersCriptographed == NULL) {
    //     fprintf(stderr, "Erro ao alocar memória.\n");
    //     return;
    // }

    while (fgets(hash, 65, registro) != NULL){
        if (!strcmp( hash, "\n\0")){
            printf("flase");
            continue;
        }
        if (count % 2 == 0)
            printf("User[%d]: %s -\n",count/2,hash);
        //     ArrayUsers->UsersCriptographed[count].email = (unsigned char *) hash;
        if (count % 2 != 0)
            printf("Senha[%d]: %s -\n",(count - 1)/2,hash);
        //     ArrayUsers->UsersCriptographed[count - 1].password = (unsigned char *) hash;
        count ++;
        // printf("- %s -\n",hash);
    }
}