#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

void drawLine(int length, char ch) {
    for (int i = 0; i < length; i++)
        printf("%c", ch);
    printf("\n");
}

void waitEnter() {
    printf(">>> Aperte 'Enter' para continuar...\n");
    while (getchar() != '\n'); // Limpa o buffer de entrada
    getchar();
}

int menu(char *argv[], int argc) {
    system("clear");
    drawLine(60, '=');
    printf("Gerenciador de Senhas\n");
    drawLine(60, '=');

    for (int i = 0; i < argc; i++) {
        printf("[%d] - %s\n", i + 1, argv[i]);
    }
    printf(">>>> ");
    int option;
    scanf("%d", &option);

    return option;
}

void handleSearchByService() {
    char *servico = (char *)malloc(sizeof(char) * 40);
    system("clear");
    printf("Pesquisar por serviço\n");
    printf("Serviço: ");
    scanf("%s", servico);
    system("clear");
    searchByService(servico);
}

void handleCreateCredential() {
    char service[40];
    char login[40];
    char password[40];

    system("clear");
    printf("Cadastro nova credencial\n");
    printf("Serviço: ");
    scanf("%s", service);
    printf("Login: ");
    scanf("%s", login);
    printf("Senha: ");
    scanf("%s", password);

    createCredential(service, login, password);

    printf("Credencial cadastrada!\n");
}

void handleShowAll() {
    system("clear");
    getAll();
}

void handleDeleteCredential() {
    system("clear");
    int c = getAll();
    printf("Qual credencial deseja excluir? (ID): ");
    int id;
    scanf("%d", &id);

    if (id >= 0 && id < c){
        deleteCredential(id);
        printf("Credencial apagada com sucesso!\n");
    } else {
        fprintf(stderr, "ID inválido!\n");
    }
}

void handleEditCredential() {
    system("clear");
    int c = getAll();
    printf("Qual credencial deseja editar? (ID): ");
    int id;
    scanf("%d", &id);

    if (id >= 0 && id < c){
        char login[40];
        char password[40];

        printf("Editar credencial #%d\n", id);
        printf("Login: ");
        scanf("%s", login);
        printf("Senha: ");
        scanf("%s", password);

        editCredential(id, login, password);

        printf("Credencial editada com sucesso!\n");
    } else {
        fprintf(stderr, "ID inválido!\n");
    }

}