#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "string_t.h"

#define MAX_FILE_SIZE 100000

int read_file(char *path, string_t *file_content, int *n_digits) {
    FILE *file = fopen(path, "r");
    if (file == NULL) return -1;

    char *content = malloc(MAX_FILE_SIZE * sizeof(char));
    if (content == NULL) {
        perror("malloc");
        return -1;
    }

    char line[BUFSIZ];
    while (fgets(line, BUFSIZ, file) != NULL) {
        strncat(content, line, MAX_FILE_SIZE - strlen(content) - 1);
    }


    char temp[9];
    *n_digits = snprintf(temp, sizeof(temp), "%lu", strlen(content));

    file_content->str = content;
    file_content->size = strlen(content);
    file_content->capacity = MAX_FILE_SIZE;

    return 0;
}

int prepend(char *first, char *second, char **dst) {
    int total_size = strlen(first) + strlen(second);

    *dst = malloc(total_size * sizeof(char));
    if (*dst == NULL) return -1;

    snprintf(*dst, total_size, "%s%s", first, second);
    return 0;
}

void prepend_str(char *prepend, char *src, char **dst) {
    strcpy(*dst, prepend);
    strcat(*dst, src);
}

int create_directory(char *root, char *name, char **path) {
    strcpy(*path, root);
    strcat(*path, name);

    mode_t permissions = 0777;
    if (mkdir(*path, permissions) != 0) {
        if (errno == EEXIST) {
            return -1;
        } 

        fprintf(stderr, "Failed to create '%s' directory.\n", *path);
        return -2;
    }

    return 0;
}

int create_directories(char *root, char **subdirectories, int num_directories) {
    for (int i = 0; i < num_directories; i++) {
        char *path = malloc(256 * sizeof(char));
        if (create_directory(root, subdirectories[i], &path) != 0) {
            free(path);
            return -1;
        }
        free(path);
    }
    return 0;
}
