#ifndef FUNCS_H
#define FUNCS_H

#include "types.h"
#include <stdio.h>

void userRegister(char * service, char * login, char * password);
void searchByService(char * service);
void handleSearchByService();
void handleCreateNewCredential();
#endif