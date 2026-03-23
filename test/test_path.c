#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <assert.h>
#include "path.h"

int test_exists() {
    const char dne[] = "no/such-file.txt";
    assert(exists(dne) != 0);

    const char in_cwd[] = "Makefile";
    assert(exists(in_cwd) == 0);

    const char nested[] = "src/main.c";
    assert(exists(nested) == 0);

    printf("test_exists: PASS\n");

    return 0;
}

int test_get_file_path() {
    char test_dir[] = "src";
    if (chdir(test_dir) != 0) {
        fprintf(stderr, "An error occurred changing working directory.\n");
        return -1;
    }

    const char file[] = "main.c";
    
    char expected_relative_path[] = "./src/main.c";

    char actual_relative_path[PATH_MAX];

    assert(get_file_path(file, actual_relative_path) == 0);
    assert(strncmp(expected_relative_path, actual_relative_path, strlen(expected_relative_path)) == 0);

    chdir("..");
    printf("test_get_file_path: PASS\n");

    return 0;
}