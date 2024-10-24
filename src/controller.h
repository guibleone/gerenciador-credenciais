#ifndef CONTROLLER_H
#define CONTROLLER_H

void userRegister(char *service, char *login, char *password);
void searchByService(char *service);
void getAll();
void deleteCredential(int id);

#endif