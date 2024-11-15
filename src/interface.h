#ifndef INTERFACE_H
#define INTERFACE_H

int menu(char *argv[], int argc);
void waitEnter();
void handleSearchByService();
void handleCreateCredential();
void handleShowAll();
void handleDeleteCredential();
void handleEditCredential();
void handleLogin();

#endif