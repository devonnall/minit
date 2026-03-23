#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: minit <command> [arguments]\n");
        return 1;
    }

    if (strncmp(argv[1], "init", 4) == 0) {
        if (argc == 2) {
            char dir[] = ".";
            init(dir);
        } else if (argc == 3) {
            init(argv[2]);
        } else {
            printf("Usage: minit init [dir]\n");
            return 1;
        }
    }
    return 0;
}