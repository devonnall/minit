#include <stdio.h>
#include "test_path.h"
#include "test_hash.h"
#include "test_add.h"

int main() {
    test_exists();
    test_get_file_path();
    // test_blob_empty_file();
    // test_blob_short_file();
    // test_sha_generation_empty_file();
    // test_sha_generation_short_file();
    // test_split_hash();
    // test_add_file();
}