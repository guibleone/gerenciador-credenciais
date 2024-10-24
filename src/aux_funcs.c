#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

int RowCounter(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr,
                "Não há credenciais salvas. Cadastre uma primeiramente.\n");
        exit(EXIT_FAILURE);
    }
    int c = 0;
    char ch;
    while ((ch = getc(file)) != EOF) {
        if (ch == '\n') {
            c++;
        }
    }
    fclose(file);
    return c;
}

void loadCredentials(Credential *credenciais) {
    FILE *file;
    file = fopen("usuarios.txt", "r");

    char service[40];
    char login[40];
    char password[40];

    int i = 0;
    while (fscanf(file, "%s %s %s", service, login, password) != EOF) {
        strcpy(credenciais[i].service, service);
        strcpy(credenciais[i].login, login);
        strcpy(credenciais[i].password, password);
        i++;
    }
}