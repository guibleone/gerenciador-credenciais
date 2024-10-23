#include <stdlib.h>
#include <stdio.h>

#include "funcs.h"

int main(int argc, char *arcv[]){

  //sistema de login

  printf("BEM VINDO AO ENCRIPTADOR 3000\n"); 
  printf("Oque deseja fazer:\n"); 
  printf("1 - Buscar através do login.\n"); 
  printf("2 - Cadastro de Nova Credencial.\n"); 
  printf("3 - Edição de Credenciais.\n"); 
  printf("4 - Exclusão de Credenciais\n");
  printf(">>>> ");
  int opc;
  scanf("%d", &opc);
  getchar();
  switch (opc) {
    case 1:
      handleSearchByService();
      break;
    case 2:
      handleCreateNewCredential();
      break;
    case 3:
      // atualizar credencial
      break;
    case 4:
      // deletar credencial
      break;
    default: 
      printf("Não selecionado nenhuma opcão");
      return 0;
      break;
  }

  return EXIT_SUCCESS;
}