#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

int exists(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        return -1;
    }
    return 0;
}

int get_absolute_root(char *current_dir, char *marker_path) {
    char *last_slash;
    while ((last_slash = strrchr(current_dir, '/')) != NULL) {
        snprintf(marker_path, PATH_MAX, "%s/.minit", current_dir);
        if (exists(marker_path) == 0) {
            return 0;
        }
        if (last_slash == current_dir) return -1;
        *last_slash = '\0';
    }
    return -1;
}

int get_file_path(const char *filename, char **path) {
    char abs_path[PATH_MAX];
    char current_dir[PATH_MAX];
    char marker_path[PATH_MAX];
    *path = malloc(PATH_MAX * sizeof(char));

    if (realpath(filename, abs_path) == NULL) {
        perror("realpath");
        return -1;
    }

    strcpy(current_dir, abs_path);

    if (get_absolute_root(current_dir, marker_path) != 0) {
        return -1;
    }

    char *parent = strrchr(current_dir, '/');
    if (!parent) return -1;
    snprintf(*path, PATH_MAX, ".%s%s\n", parent, abs_path + strlen(current_dir));
    return 0;
}