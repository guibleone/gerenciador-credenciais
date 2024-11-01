#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include "types.h"
#include <stdio.h>

int RowCounter(char *filename);
void loadCredentials(Credential *credentials);
int showCredentials(int x, int y, Credential *credentials);

#endif