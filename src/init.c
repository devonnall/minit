#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utility.h"
#include "init.h"

int create_dir(char *dir) {
    mode_t permissions = 0777;
    if (mkdir(dir, permissions) != 0) {
        if (errno == EEXIST) {
            return -1;
        }

        fprintf(stderr, "Failed to create '%s' directory.", dir);
        return -2;
    }

    return 0;
}

int create_dirs(char *root, char **dirs, int num_dirs) {
    for (int i = 0; i < num_dirs; i++) {
        size_t len = strlen(root) + strlen(dirs[i]);
        char path[len];
        snprintf(path, len, "%s%s", root, dirs[i]);
        if (create_dir(path) != 0) {
            return -1;
        }
    }
    return 0;
}

int create_file(char *root, char *file) {
    size_t len = strlen(root) + strlen(file) + 1;
    char path[len];
    snprintf(path, len, "%s%s", root, file);

    FILE *fp = fopen(path, "a");
    if (fp == NULL) return -1;
    fclose(fp);
    return 0;
}

int init(char *root_path) {
    strncat(root_path, "/", 1);

    char minit_dir[] = ".minit/";
    char *path = strncat(root_path, minit_dir, strlen(minit_dir));

    int minit_result = create_dir(path);
    if (minit_result == -1) {
        printf("Minit repository already initialized.\n\nAborting...\n");
        return -1;
    } else if (minit_result == -2) {
        fprintf(stderr, "A problem occurred initializing minit repository.\n\nAborting...\n");
        return -1;
    }

    char *directories[] = {
        "refs/",
        "objects/",
        "logs/"
    };

    int num_directories = 3;

    if (create_dirs(path, directories, num_directories) != 0) {
        return -1;
    }

    char *filenames[] = {
        "HEAD",
        "index",
        "config",
        "description",
    };

    for (int i = 0; i < 4; i++) {
        if (create_file(path, filenames[i]) != 0) return -1;
    }

    printf("Minit repository successfully initialized\n");

    return 0;
}