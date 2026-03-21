#ifndef HASH_H
#define HASH_H

#include "string_t.h"

#define SHA_STR_LENGTH 41

int construct_raw_blob(const char *path, string_t *raw_blob);
int convert_unsigned_to_hex_str(unsigned char *str, char **hex);
int extract_directory_name(char *sha, char **dir);
int compute_sha(string_t *content, unsigned char **hash);

#endif