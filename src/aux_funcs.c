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

void getRegistersOnFile (UserCriptographedArray * ArrayUsers,FILE * registro) {
    int count = 0;
    // ,
    char * hash = (char *) malloc(65 * sizeof(char));
    ArrayUsers->size = RowCounter(registro);
    printf("Tamanho retornado: %d\n", ArrayUsers->size); 
    ArrayUsers->UsersCriptographed = malloc(ArrayUsers->size * sizeof(UserCriptographed)); 
    if (ArrayUsers->UsersCriptographed == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    printf("Memória alocada com sucesso.\n");
    while (fgets(hash, 65, registro) != NULL){
        //Retirar /n/0 do arquivo
        if (!strcmp( hash, "\n\0")){
            // printf("flase");
            continue;
        }
        if (count % 2 == 0)
            printf("User[%d]: %s -\n",count/2,(unsigned char *) hash);
            // ArrayUsers->UsersCriptographed[count/2].email = (unsigned char *) hash;
        if (count % 2 != 0)
            printf("Senha[%d]: %s -\n",(count - 1)/2,(unsigned char *) hash);
            // ArrayUsers->UsersCriptographed[(count - 1)/2].password = (unsigned char *) hash;
        count ++;
        // printf("- %s -\n",hash);
    }
}