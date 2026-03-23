// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include "add.h"
// #include "hash.h"
// #include "string_t.h"

// int test_split_hash() {
//     string_t file = {
//         .str = "src/hash.c",
//         .size = 10
//     };

//     struct blob_object blob;
//     assert(get_blob_object(&file, &blob) == 0);
//     printf("test_split_hash: %s\n", blob.hash_hex);

//     char *dir = NULL;
//     char *filename = NULL;
//     assert(split_object_hash(&blob, &dir, &filename) == 0);

//     printf("PASS: test_split_hash\n");

//     return 0;
// }

// int test_add_file() {
//     string_t file = {
//         .str = "src/hash.c",
//         .size = 10
//     };

//     struct blob_object blob;
//     assert(get_blob_object(&file, &blob) == 0);
//     printf("test_add_file: %s\n", blob.hash_hex);
//     return 0;
// }