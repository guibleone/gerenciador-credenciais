#include "manipulate_io.h"
#include <stdio.h>
#include <gcrypt.h>

int compareUnsignedChar (unsigned char * text1,unsigned char * text2, int nBytes) {
    for (int i = 0; i < nBytes; i++) {
        if (text1[i] != text2[i])
            return 0;
    }
    return 1;
}
 unsigned char * toCriptograph (char * string) {
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

    printf("SHA-256: ");
    // for (int i = 0; i < 32; i++) {
    //     printf("%02x", hash[i]);
    // }
    char * teste1  = (char *) hash;
    printf("%.*s", (int) sizeof(hash), hash);
    printf("\n");
    return hash;
}
