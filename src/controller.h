#include "types.h"

int getAll();
void createCredential(char *service, char *login, char *password);
void searchByService(char *service);
void deleteCredential(int id);
void editCredential(int id, char *login, char *password);
void readBufferFromFile(char * buffer, int buffer_size);
unsigned long int getBufferSize();
void writeBufferOnFile(char * buffer, int buffer_size);
int RowCounter(char *filename);
void loadCredentials(Credential *credentials);
int showCredentials(int x, int y, Credential * credentials);