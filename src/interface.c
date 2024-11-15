#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include "auth.h"

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

void handleLogin(){
    char login[30];
    char password[30];

    drawLine(60, '=');
    printf("\033[34m%42s\n\033[m", "Gerenciador de Credenciais");
    drawLine(60, '=');
    printf("Login: ");
    scanf("%s", login);
    printf("password: ");
    scanf("%s", password);

    authenticate(login, password);
}

int menu(char *argv[], int argc) {
    system("clear");
    drawLine(60, '=');
    printf("\033[34m%42s\n\033[m", "Gerenciador de Credenciais");
    drawLine(60, '=');

    for (int i = 0; i < argc; i++) {
        printf("\033[32m[%d]\033[m - %s\n", i + 1, argv[i]);
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

    printf("\033[32mCredencial cadastrada!\n\033[m");
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
        printf("\033[32mCredencial apagada com sucesso!\n\033[m");
    } else {
        fprintf(stderr, "\033[31mID inválido!\n\033[m");
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

        printf("\033[32mCredencial editada com sucesso!\n\033[m");
    } else {
        fprintf(stderr, "\033[31mID inválido!\n\033[m");
    }

}
