#include "auth.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int authenticate(char * login, char * password){
    char registeredLogin[] = "root";
    char registeredPassword[] = "root";

    if (!strcmp(login, registeredLogin)){
        if (!strcmp(password, registeredPassword)){
            return 1;
        }
    }

    printf("Usuário ou senha inválidos!\n");
    exit(EXIT_FAILURE);
}