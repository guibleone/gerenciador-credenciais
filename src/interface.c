#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

void drawLine(int length, char ch) {
    for (int i = 0; i < length; i++)
        printf("%c", ch);
    printf("\n");
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
    searchByService(servico);
}

void handleCreateNewCredential() {
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

    userRegister(service, login, password);

    printf("Credencial cadastrada!\n");
}

void handleShowAll() {
    system("clear");
    getAll();
}

void handleDeleteCredential() {
    system("clear");
    getAll();
    printf("Qual credencial deseja excluir? (ID): ");
    int id;
    scanf("%d", &id);
    deleteCredential(id);
}