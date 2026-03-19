#include <stdio.h>
#include <assert.h>
#include "path.h"

void test_file_exists() {
    const char file_in_root[] = "./README.md";
    assert(exists(file_in_root) == 0); // File exists

    const char no_file[] = "./no-file.txt";
    assert(exists(no_file) != 0); // No such file

    const char file_in_subdirectory[] = "./src/main.c";
    assert(exists(file_in_subdirectory) == 0); // File exists

    printf("test_file_exists: All tests passed.\n");
}

void test_get_relative_path() {
    const char in_root[] = "test.txt";
    char *path_one = NULL;
    assert(get_file_path(in_root, &path_one) == 0);

    const char not_exist[] = "no_file.txt";
    char *path_two = NULL;
    assert(get_file_path(not_exist, &path_two) == -1);

    printf("test_get_relative_path: ALl tests passed.\n");
}