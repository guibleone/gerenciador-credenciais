#include "crypt_module.h"
#include "controller.h"
#include <stdlib.h>

void encrypt(char * buffer, unsigned long buffer_size, int key){
	register unsigned long i = 0;
	for (; i < buffer_size; i++){
		buffer[i] = buffer[i] + (i % (key*key));
	}
}

void decrypt(char * buffer, unsigned long buffer_size, int key){
	register unsigned long i = 0;
	for (; i < buffer_size; i++){
		buffer[i] = buffer[i] - (i % (key * key));
	}
}

void decryptFile(){
    unsigned long int size = getBufferSize();
    char * buffer = (char*)malloc(sizeof(char) * size);
    readBufferFromFile(buffer, size);
    decrypt(buffer, size, 5);
    writeBufferOnFile(buffer, size);
    free(buffer);
}

void encryptFile(){
    unsigned long int size = getBufferSize();
    char * buffer = (char*)malloc(size * sizeof(char));
    readBufferFromFile(buffer, size);
    encrypt(buffer, size, 5);
    writeBufferOnFile(buffer, size);
    free(buffer);
}