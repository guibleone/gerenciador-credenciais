#ifndef CONTROLLER_H
#define CONTROLLER_H

int getAll();
void createCredential(char *service, char *login, char *password);
void searchByService(char *service);
void deleteCredential(int id);
void editCredential(int id, char *login, char *password);

#endif