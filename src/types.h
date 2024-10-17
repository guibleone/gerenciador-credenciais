#ifndef TYPES_H
#define TYPES_H

#define MAX_EMAIL 50
#define MAX_PASSWORD 20

typedef struct
{
  char email[MAX_EMAIL];
  char password[MAX_PASSWORD];
} User;

typedef struct {
  unsigned char * email;
  unsigned char * password;
} UserCriptographed;

typedef struct {
  UserCriptographed * UsersCriptographed;
  int size;
} UserCriptographedArray;

#endif