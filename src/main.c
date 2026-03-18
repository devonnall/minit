#include <stdio.h>
#include <stdlib.h>
#include "add.h"

int main(int argc, char **argv) {
    char *path = argv[1];
    v_char *contents = read_file_content(path);
    return 0;
}