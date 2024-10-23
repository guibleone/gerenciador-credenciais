#ifndef TYPES_H
#define TYPES_H

#define MAX_EMAIL 50
#define MAX_PASSWORD 20

typedef struct { 
  char servico[40];
  char email[40];
  char password[40];
} Credential;

#endif