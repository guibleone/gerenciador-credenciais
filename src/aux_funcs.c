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

void loadCredentials(Credential *credentials) {
    FILE *file;
    file = fopen("usuarios.txt", "r");

    char service[40];
    char login[40];
    char password[40];

    int i = 0;
    while (fscanf(file, "%s %s %s", service, login, password) != EOF) {
        strcpy(credentials[i].service, service);
        strcpy(credentials[i].login, login);
        strcpy(credentials[i].password, password);
        i++;
    }
}

int showCredentials(int x, int y, Credential * credentials) {
    printf("%d%20s%20s%15s\n", x, credentials[x].service, credentials[x].login, credentials[x].password);

    if (x == y - 1){
        return x;
    }
    
    return showCredentials(x + 1, y, credentials);
}