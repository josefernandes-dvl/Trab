#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "prototipos.h"

#define TAMANHO_HASH SHA256_DIGEST_LENGTH

void gerar_hash(const char *senha, unsigned char *hash)
{
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, senha, strlen(senha));
    SHA256_Final(hash, &ctx);
}