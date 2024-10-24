#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aux_funcs.h"
#include "types.h"

void userRegister(char *service, char *login, char *password) {
    FILE *file;
    file = fopen("usuarios.txt", "a+");
    if (file == NULL) {
        fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s", service);
    fprintf(file, " ");
    fprintf(file, "%s", login);
    fprintf(file, " ");
    fprintf(file, "%s", password);
    fprintf(file, "\n");
}

void searchByService(char *service) {
    int c = RowCounter("usuarios.txt");
    int found = 0;
    Credential *credenciais = (Credential *)malloc(sizeof(Credential) * c);
    if (credenciais == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credenciais);

    for (int i = 0; i < c; i++) {
        if (!strcmp(credenciais[i].service, service)) {
            found = 1;
            if (i == 0)
                printf("%s%20s%20s%15s\n", "ID", "Serviço", "Login", "Senha");
            printf("%d%20s%20s%15s\n", i, credenciais[i].service,
                   credenciais[i].login, credenciais[i].password);
        }
    }

    if (!found)
        printf("Nenhum registro encontrado\n");

    free(credenciais);
}

void getAll() {
    int c = RowCounter("usuarios.txt");
    if (c <= 0) {
        fprintf(stderr, "Nenhuma credencial cadastrada.\n");
        exit(EXIT_FAILURE);
    }

    Credential *credenciais = (Credential *)malloc(sizeof(Credential) * c);
    if (credenciais == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credenciais);

    printf("%s%20s%20s%15s\n", "ID", "Serviço", "Login", "Senha");
    for (int i = 0; i < c; i++) {
        printf("%d%20s%20s%15s\n", i, credenciais[i].service,
               credenciais[i].login, credenciais[i].password);
    }

    free(credenciais);
}

void deleteCredential(int id) {
    int c = RowCounter("usuarios.txt");
    Credential *credenciais = (Credential *)malloc(sizeof(Credential) * c);
    if (credenciais == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credenciais);

    FILE *file;
    file = fopen("usuarios.txt", "w");

    if ((id + 1) > c)
        fprintf(stderr, "Não existe credencial com este ID.\n");
    if (id < 0)
        fprintf(stderr, "ID inválido!\n");

    for (int i = 0; i < c; i++) {
        if (i != id) {
            fprintf(file, "%s", credenciais[i].service);
            fprintf(file, " ");
            fprintf(file, "%s", credenciais[i].login);
            fprintf(file, " ");
            fprintf(file, "%s", credenciais[i].password);
            fprintf(file, "\n");
        }
    }

    free(credenciais);
    fclose(file);
}
