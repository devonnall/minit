#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/sha.h>
#include "string_t.h"
#include "hash.h"
#include "utility.h"

int construct_raw_blob(const char *path, string_t *raw_blob) {
    string_t content;
    int n_digits = 0;

    if (read_file(path, &content, &n_digits) != 0) return -1;

    int prefix_size = 6 + n_digits + 1; // "blob " + digit count + \0
    int content_size = content.size;
    int combined_size = prefix_size + content_size;

    char prefix[prefix_size];
    char *combined = malloc(combined_size * sizeof(char));

    if (combined == NULL) return -1;
    
    snprintf(prefix, sizeof(prefix), "blob %d", content_size);

    memcpy(combined, prefix, prefix_size - 1);
    memcpy(combined + prefix_size - 1, content.str, content_size);

    combined[combined_size - 1] = '\0';

    raw_blob->str = combined;
    raw_blob->size = combined_size - 1;

    return 0;
}

int convert_unsigned_to_hex_str(unsigned char *str, char **hex) {
    *hex = malloc(SHA_STR_LENGTH * sizeof(char));
    if (*hex == NULL) return -1;
    
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(*hex + (i * 2), "%02x", str[i]);
    }

    return 0;
}

int extract_directory_name(char *sha, char **dir) {
    int len = 4;
    *dir = malloc(len * sizeof(char));

    if (*dir == NULL) return -1;

    strncat(*dir, sha, 2);
    strncat(*dir, "/\0", 2);

    return 0;
}

int compute_sha(string_t *content, unsigned char **hash) {
    *hash = malloc(SHA_DIGEST_LENGTH * sizeof *hash);
    if (*hash == NULL) return -1;

    SHA1((unsigned char *)(content->str), content->size, *hash);
    return 0;
}