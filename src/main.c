#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main() {
    // Sistema de login
    char *args[] = {"Mostrar todas credenciais", "Buscar por serviço",
                    "Cadastrar nova credencial", "Editar credencial",
                    "Excluir credencial",        "Sair"};

    int argc = 6;
    int opc;

    do {
        opc = menu(args, argc);

        switch (opc) {
        case 1:
            handleShowAll();
            break;
        case 2:
            handleSearchByService();
            break;
        case 3:
            handleCreateCredential();
            break;
        case 4:
            handleEditCredential();
            break;
        case 5:
            handleDeleteCredential();
            break;
        case 6:
            printf("Saindo do sistema!\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
        waitEnter();
    } while (opc != 6);

    return EXIT_SUCCESS;
}
