#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/sha.h>
#include <zlib.h>
#include "object.h"
#include "utility.h"

int get_uncompressed_object_content(const char *path, char **blob_content, size_t *total_len, char *type) {
    char content[MAX_FILE_SIZE];
    if (read_file(path, content) != 0) return -1;

    int content_len = strlen(content);
    int num_digits = 0;
    get_digit_count(content_len, &num_digits);

    int header_len = strlen(type) + num_digits + 1;
    int combined_len = header_len + content_len;

    char header[header_len];
    char *combined = malloc((combined_len + 1) * sizeof(char));
    if (combined == NULL) return -1;
    
    snprintf(header, header_len, "%s %d", type, content_len);

    memcpy(combined, header, header_len);
    memcpy(combined + header_len - 1, content, content_len);

    combined[combined_len - 1] = '\0';

    *blob_content = combined;
    *total_len = combined_len;

    return 0;
}

int get_object_hex(unsigned char *hash, char *hex) {
    if (hash == NULL) return -1;

    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf(hex + (i * 2), "%02x", hash[i]);
    }

    return 0;
}

int split_object_hash(struct object *obj, char **dir, char **file) {
    char name[3];

    *dir = strncat(name, obj->hash_hex, 2);
    *file = obj->hash_hex + 2;

    return 0;
}

int compress_object(char *object_content, size_t len, struct object *obj) {
    uLong object_len = (uLong)len;

    uLong output_len = compressBound(object_len);
    unsigned char *output = (unsigned char *)malloc(output_len);

    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;

    deflateInit(&strm, Z_BEST_COMPRESSION);

    strm.next_in = (Bytef *)(object_content);
    strm.avail_in = object_len;
    strm.next_out = output;
    strm.avail_out = output_len;

    deflate(&strm, Z_FINISH);
    deflateEnd(&strm);

    obj->compressed_content = output;

    return 0;
}

void get_object_hash(char *object_content, size_t content_len, unsigned char *hash) {
    SHA1((unsigned char *)(object_content), content_len, hash);
}