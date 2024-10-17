#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include <stdio.h>
#include "types.h"

void readUser (User *user);
int getRegistersOnFile (UserCriptographedArray * ArrayUsers,FILE * registro);
#endif