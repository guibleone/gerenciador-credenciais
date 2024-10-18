#include "manipulate_io.h"
#include <stdio.h>
#include <gcrypt.h>

int compareUnsignedChar (unsigned char * text1,unsigned char * text2, int nBytes) {
    for (int i = 0; i < nBytes; i++) {
        printf("%02x - %02x", text1[i],text2[i]);
        if (text1[i] != text2[i])
            return 0;
    }
    return 1;
}

char* sha256_to_string(unsigned char* hash, size_t length) {
    // Aloca memória para a string hexadecimal (2 caracteres para cada byte + terminador '\0')
    char* hex_string = (char*)malloc((length * 2 + 1) * sizeof(char));
    if (hex_string == NULL) {
        printf("Erro ao alocar memória para hex_string.\n");
        return NULL;
    }

    // Converte cada byte do hash para sua representação hexadecimal
    for (size_t i = 0; i < length; i++) {
        sprintf(hex_string + (i * 2), "%02x", hash[i]);
    }

    // Adiciona o terminador nulo no final da string
    hex_string[length * 2] = '\0';

    return hex_string;
}
   char * toCriptograph (char * string) {
     if (!gcry_check_version(GCRYPT_VERSION)) {
        fprintf(stderr, "Erro: versão incompatível da libgcrypt!\n");
        return NULL;
    }

    unsigned char * hash = (unsigned char *) malloc(32 * sizeof(unsigned char)); // SHA-256 produz hashs de 32 bytes
    if (hash == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        return NULL;
    }
    //Calcula o Tam e ja transforma em Hash
    gcry_md_hash_buffer(GCRY_MD_SHA256, hash, string, strlen(string));   

    // printf("SHA-256: ");
    // for (int i = 0; i < 32; i++) {
    //     printf("%02x", hash[i]);
    // }
    // char * teste1  = (char *) hash;
    // printf("%.*s", (int) sizeof(hash), hash);
    // printf("\n");/
    char* hex_string = (char*)malloc((32 * 2 + 1) * sizeof(char));
    if (hex_string == NULL) {
        printf("Erro ao alocar memória para hex_string.\n");
        return NULL;
    }

    // Converte cada byte do hash para sua representação hexadecimal
    for (size_t i = 0; i < 32; i++) {
        sprintf(hex_string + (i * 2), "%02x", hash[i]);
    }

    // Adiciona o terminador nulo no final da string
    hex_string[32 * 2] = '\0';

    return hex_string;
}
