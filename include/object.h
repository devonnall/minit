#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define SHA_STR_LENGTH 41

struct object {
    char hash_hex[41];
    unsigned char *compressed_content;
};

int get_uncompressed_object_content(const char *path, char **blob_content, size_t *total_len, char *type);
int get_object_hex(unsigned char *hash, char *hex);
int split_object_hash(struct object *obj, char **dir, char **file);
void get_object_hash(char *content, size_t content_len, unsigned char *hash);
int compress_object(char *raw_blob, size_t blob_len, struct object *obj);

#endif