#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "hash.h"
#include "string_t.h"
#include "utility.h"

int test_blob_empty_file() {
    char filename[] = "test/files/empty.txt";
    string_t raw_blob;
    if (construct_raw_blob((const char *)filename, &raw_blob) != 0) return -1;

    char correct[] = "blob 0\0";
    assert(memcmp(raw_blob.str, correct, raw_blob.size) == 0);

    printf("PASS: test_empty_file\n");

    return 0;
}

int test_blob_short_file() {
    char filename[] = "test/files/hello.py";
    string_t raw_blob;
    if (construct_raw_blob((const char *)filename, &raw_blob) != 0) return -1;

    char correct[] = "blob 21\0print(\"Hello world!\")";
    assert(memcmp(raw_blob.str, correct, raw_blob.size) == 0);

    printf("PASS: test_short_file\n");

    return 0;
}