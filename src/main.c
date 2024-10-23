#include <stdlib.h>
#include <stdio.h>

#include "controller.h"
#include "interface.h"

int main(){

  //sistema de login

  char * args[] = {
    "Mostrar todas credenciais",
    "Buscar por serviço", 
    "Cadastrar nova credencial", 
    "Editar credencial", 
    "Excluir credencial"
  };

  int argc = 5;

  int opc = menu(args, argc);

  switch (opc) {
    case 1:
      handleShowAll();
      break;
    case 2:
      handleSearchByService();
      break;
    case 3:
      handleCreateNewCredential();
      break;
    case 4:
      // atualizar credencial
      break;
    case 5:
      handleDeleteCredential();
      break;
    default: 
      printf("Esta opção não é valida\n");
      return 0;
      break;
  }

  return EXIT_SUCCESS;
}