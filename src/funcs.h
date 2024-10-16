#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"
#include <stdio.h>

void userRegister(User *user, FILE *registro);
void printUser(User *user);
void searchUser(User *user, FILE *registro);
void updateUser(User *user, FILE *registro);
void deleteUser(User *user, FILE *registro);
#endif