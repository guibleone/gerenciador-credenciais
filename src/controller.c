#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aux_funcs.h"
#include "types.h"

void createCredential(char *service, char *login, char *password) {
    FILE *file;
    file = fopen("usuarios.txt", "a+");

    if (file == NULL) {
        fprintf(stderr, "Erro: Ponteiro de usuário inválido.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s %s %s\n", service, login, password);
    fclose(file);
}

void searchByService(char *service) {
    int c = RowCounter("usuarios.txt");
    int found = 0;
    Credential *credentials = (Credential *)malloc(sizeof(Credential) * c);
    if (credentials == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credentials);

    printf("%s%20s%20s%15s\n", "ID", "Serviço", "Login", "Senha");
    for (int i = 0; i < c; i++) {
        if (!strcmp(credentials[i].service, service)) {
            found = 1;
            printf("%d%20s%20s%15s\n", i, credentials[i].service, credentials[i].login, credentials[i].password);
        }
    }

    if (!found)
        printf("Nenhum registro encontrado\n");

    free(credentials);
}

void getAll() {
    int c = RowCounter("usuarios.txt");
    if (c <= 0) {
        fprintf(stderr, "Nenhuma credencial cadastrada.\n");
    }

    Credential *credentials = (Credential *)malloc(sizeof(Credential) * c);
    if (credentials == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
    }

    loadCredentials(credentials);

    if (c > 0) {
        printf("%s%20s%20s%15s\n", "ID", "Serviço", "Login", "Senha");
        showCredentials(0, c, credentials);
    }

    free(credentials);
}

void deleteCredential(int id) {
    int c = RowCounter("usuarios.txt");
    Credential *credentials = (Credential *)malloc(sizeof(Credential) * c);
    if (credentials == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credentials);

    FILE *file;
    file = fopen("usuarios.txt", "w");

    if ((id + 1) > c)
        fprintf(stderr, "Não existe credencial com este ID.\n");
    if (id < 0)
        fprintf(stderr, "ID inválido!\n");

    for (int i = 0; i < c; i++) {
        if (i != id) {
            fprintf(file, "%s %s %s\n", credentials[i].service,
                    credentials[i].login, credentials[i].password);
        }
    }

    free(credentials);
    fclose(file);
}

void editCredential(int id, char *login, char *password) {
    int c = RowCounter("usuarios.txt");
    Credential *credentials = (Credential *)malloc(sizeof(Credential) * c);
    if (credentials == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
        exit(EXIT_FAILURE);
    }

    loadCredentials(credentials);

    FILE *file;
    file = fopen("usuarios.txt", "w");

    if ((id + 1) > c)
        fprintf(stderr, "Não existe credencial com este ID.\n");
    if (id < 0)
        fprintf(stderr, "ID inválido!\n");

    for (int i = 0; i < c; i++) {
        if (i != id) {
            fprintf(file, "%s %s %s\n", credentials[i].service, credentials[i].login, credentials[i].password);
        }
        if (i == id) {
            fprintf(file, "%s %s %s\n", credentials[i].service, strcpy(credentials[i].login, login), strcpy(credentials[i].password, password));
        }
    }

    free(credentials);
    fclose(file);
}
