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
  rewind(arquivo);
  return c;
}

UserCriptographedArray * getRegistersOnFile (FILE * registro) {
    int count = 0;
    // ,
    UserCriptographedArray * ArrayUsers;
    char * hash = (char *) malloc(65 * sizeof(char));
    ArrayUsers->size = RowCounter(registro);
    // printf("%dteste", ArrayUsers->size);
    ArrayUsers->UsersCriptographed = (UserCriptographed *) malloc(ArrayUsers->size * sizeof(UserCriptographed)); 
    for (int i = 0; i < ArrayUsers->size; i++){
      ArrayUsers->UsersCriptographed[i].email = (unsigned char *) malloc(65 * sizeof(unsigned char)); 
      ArrayUsers->UsersCriptographed[i].password = (unsigned char *) malloc(65 * sizeof(unsigned char)); 
    }
    if (ArrayUsers->UsersCriptographed == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // printf("%s", ArrayUsers->UsersCriptographed[0].email);
    printf("Memória alocada com sucesso11.\n");
    while (fgets(hash, 65, registro) != NULL){
        //Retirar /n/0 do arquivo
        if (!strcmp( hash, "\n\0")){
            // printf("flase");
            continue;
        }
        if (count % 2 == 0)
            strcpy((char *)ArrayUsers->UsersCriptographed[count / 2].email, hash);
        if (count % 2 != 0)
            strcpy((char *)ArrayUsers->UsersCriptographed[(count-1) / 2].password, hash);
        count ++;
        // printf("- %s -\n",hash);
    }

    for (int i = 0; i < ArrayUsers->size; i++) {
    printf("User[%d]:%s \n",i,ArrayUsers->UsersCriptographed[i].email);
    printf("Senha[%d]:%s \n",i,ArrayUsers->UsersCriptographed[i].password);
  }

    return ArrayUsers;
}