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

    fclose(file);
}

int showCredentials(int x, int y, Credential * credentials) {
    printf("%d%25s%25s%20s\n", x, credentials[x].service, credentials[x].login, credentials[x].password);

    if (x == y - 1){
        return x;
    }
    
    return showCredentials(x + 1, y, credentials);
}


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

    printf("%s%25s%25s%20s\n", "ID", "Serviço", "Login", "Senha");
    for (int i = 0; i < c; i++) {
        if (!strcmp(credentials[i].service, service)) {
            found = 1;
            printf("%d%25s%25s%20s\n", i, credentials[i].service, credentials[i].login, credentials[i].password);
        }
    }

    if (!found)
        printf("\033[31mNenhum registro encontrado\n\033[m");

    free(credentials);
}

int getAll() {
    int c = RowCounter("usuarios.txt");
    if (c <= 0) {
        fprintf(stderr, "\033[31mNenhuma credencial cadastrada.\n\033[m");
    }

    Credential *credentials = (Credential *)malloc(sizeof(Credential) * c);
    if (credentials == NULL) {
        fprintf(stderr, "Erro ao alocar credenciais.\n");
    }

    loadCredentials(credentials);

    if (c > 0) {
        printf("%s%25s%25s%20s\n", "ID", "Serviço", "Login", "Senha");
        showCredentials(0, c, credentials);
    }

    free(credentials);
    return c;
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

void readBufferFromFile(char * buffer, int buffer_size){
    FILE * file;
    file = fopen("usuarios.txt", "r");
    fread(buffer, buffer_size, 1, file);
    fclose(file);
}

unsigned long int getBufferSize(){
    FILE * file;

    file = fopen("usuarios.txt", "r");
    char ch;
    unsigned long int count = 0;
    while((ch = getc(file)) != EOF){
        count++;
    }

    fclose(file);
    return count;
}

void writeBufferOnFile(char * buffer, int buffer_size){
    FILE * file;
    file = fopen("usuarios.txt", "w");
    fwrite(buffer, buffer_size, 1, file);
    fclose(file);  
}
