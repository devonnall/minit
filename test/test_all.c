#include <stdio.h>
#include "test_path.h"
#include "test_blob.h"
#include "test_hash.h"

int main() {
    test_file_exists();
    test_get_relative_path();
    test_blob_empty_file();
    test_blob_short_file();
    test_sha_generation_empty_file();
    test_sha_generation_short_file();
}