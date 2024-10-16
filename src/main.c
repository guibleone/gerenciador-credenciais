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

  printf("BEM VINDO AO ENCRIPTADOR 3000\n"); 
  printf("Oque deseja fazer:\n"); 
  printf("1 - Buscar, atraves de Email e Senha.\n"); 
  printf("2 - Cadastro de Nova Credencial.\n"); 
  printf("3 - Edição de Credenciais.\n"); 
  printf("4 - Exclusão de Credenciais");
  printf("5 - Alteração de Credenciais de Acesso.\n"); 
  int opc;
  scanf("%d", &opc);
  getchar();
  switch (opc) {
    case 1:
      searchUser(user, registro);
      break;
    case 2:
      userRegister(user, registro);
      break;
    case 3:
      updateUser(user, registro);
      break;
    case 4:
      deleteUser(user, registro);
      break;
    default: 
      printf("Não selecionado nenhuma opcão");
      return 0;
      break;
  }

  printUser(user);

  fclose(registro);
  free(user);

  return EXIT_SUCCESS;
}