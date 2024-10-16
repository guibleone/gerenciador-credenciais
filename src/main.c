#include <stdlib.h>
#include <stdio.h>

#include "funcs.h"

int main(int argc, char *arcv[])
{
  User *user = (User *)malloc(sizeof(User));

  userRegister(user);
  printUser(user);

  free(user);

  return EXIT_SUCCESS;
}