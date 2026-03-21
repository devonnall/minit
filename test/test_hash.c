#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash.h"
#include "utility.h"

int test_sha_generation_empty_file() {
    FILE *fp;
    char expected_hash[50];

    fp = popen("git hash-object test/files/empty.txt", "r");
    if (fp == NULL) return -1;

    fgets(expected_hash, sizeof(expected_hash), fp);
    pclose(fp);

    const char file[] = "test/files/empty.txt";
    string_t raw_blob;

    assert(construct_raw_blob(file, &raw_blob) == 0);

    unsigned char *hash = NULL;
    assert(compute_sha(&raw_blob, &hash) == 0);

    char *hash_hex = NULL;
    assert(convert_unsigned_to_hex_str(hash, &hash_hex) == 0);
    assert(strncmp(hash_hex, expected_hash, 40) == 0);

    printf("PASS: test_sha_generation_empty_file\n");

    return 0;
}

int test_sha_generation_short_file() {
    FILE *fp;
    char expected_hash[50];

    fp = popen("git hash-object test/files/hello.py", "r");
    if (fp == NULL) return -1;

    fgets(expected_hash, sizeof(expected_hash), fp);
    pclose(fp);

    const char file[] = "test/files/hello.py";
    string_t raw_blob;

    assert(construct_raw_blob(file, &raw_blob) == 0);

    unsigned char *hash = NULL;
    assert(compute_sha(&raw_blob, &hash) == 0);

    char *hash_hex = NULL;
    assert(convert_unsigned_to_hex_str(hash, &hash_hex) == 0);
    assert(strncmp(hash_hex, expected_hash, 40) == 0);

    printf("PASS: test_sha_generation_short_file\n");

    return 0;
}